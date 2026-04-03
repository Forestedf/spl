#pragma once

struct Barrett {
    unsigned m;
    unsigned long long im;
    explicit Barrett(unsigned m) : m(m), im(-1ull / m + 1) {}
    unsigned mul(unsigned x, unsigned y) const {
        unsigned long long z = (unsigned long long)x * y;
        unsigned long long q = ((__uint128_t)z * im) >> 64;
        unsigned long long t = q * m;
        return z - t + (z < t ? m : 0);
    }
};
