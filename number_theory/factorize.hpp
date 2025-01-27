#pragma once
#include <algorithm>
#include <vector>
#include "../template/random.hpp"
#include "primality.hpp"
#include "montgomery_64.hpp"

template <typename T>
unsigned long long rho(unsigned long long n, unsigned long long c) {
    T cc(c);
    auto f = [cc](T x) -> T {
        return x * x + cc;
    };
    T y(2);
    T x = y;
    T z = y;
    T p(1);
    unsigned long long g = 1;
    constexpr int M = 128;
    for (int r = 1; g == 1; r *= 2) {
        x = y;
        for (int i = 0; i < r && g == 1; i += M) {
            z = y;
            for (int j = 0; j < r - i && j < M; ++j) {
                y = f(y);
                p *= y - x;
            }
            g = std::gcd(p.val(), n);
        }
    }
    if (g == n) {
        do {
            z = f(z);
            g = std::gcd((z - x).val(), n);
        } while (g == 1);
    }
    return g;
}

unsigned long long find_factor(unsigned long long n) {
    using M = MontgomeryModInt64<20250127>;
    M::set_mod(n);
    while (true) {
        unsigned long long c = uniform(n);
        unsigned long long g = rho<M>(n, c);
        if (g != n) {
            return g;
        }
    }
    return 0;
}

void factor_inner(unsigned long long n, std::vector<unsigned long long> &ps) {
    if (is_prime(n)) {
        ps.push_back(n);
        return;
    }
    if (n % 2 == 0) {
        ps.push_back(2);
        factor_inner(n / 2, ps);
        return;
    }
    unsigned long long m = find_factor(n);
    factor_inner(m, ps);
    factor_inner(n / m, ps);
}

std::vector<unsigned long long> factorize(unsigned long long n) {
    if (n <= 1) {
        return std::vector<unsigned long long>();
    }
    std::vector<unsigned long long> ps;
    factor_inner(n, ps);
    std::sort(ps.begin(), ps.end());
    return ps;
}
