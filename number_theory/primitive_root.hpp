#pragma once
#include "factorize.hpp"

// p: prime
unsigned long long find_primitive_root(unsigned long long p) {
    using M = MontgomeryModInt64<20250128>;
    assert(is_prime(p));
    if (p == 2) {
        return 1;
    }
    M::set_mod(p);
    std::vector<unsigned long long> ps = factorize(p - 1);
    ps.erase(std::unique(ps.begin(), ps.end()), ps.end());
    while (true) {
        unsigned long long x = uniform<unsigned long long>(1, p);
        M x_(x), one(1ULL);
        bool ok = true;
        for (unsigned long long q : ps) {
            if (x_.pow((p - 1) / q).x == one.x) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return x;
        }
    }
    return 0;
}
