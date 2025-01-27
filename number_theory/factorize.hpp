#pragma once
#include <algorithm>
#include <vector>
#include "../template/random.hpp"
#include "primality.hpp"

unsigned long long rho(unsigned long long n, unsigned long long c) {
    auto f = [&](unsigned long long x) -> unsigned long long {
        return ((__uint128_t)x * x + c) % n;
    };
    unsigned long long x = 1, y = 2;
    unsigned long long g = 1;
    for (int r = 1; g == 1; r *= 2) {
        x = y;
        for (int i = 0; i < r && g == 1; ++i) {
            y = f(y);
            g = std::gcd(x + n - y, n);
        }
    }
    return g;
}

unsigned long long find_factor(unsigned long long n) {
    while (true) {
        unsigned long long c = uniform(n);
        unsigned long long g = rho(n, c);
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
