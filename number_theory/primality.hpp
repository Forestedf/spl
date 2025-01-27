#pragma once

namespace primality {

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 inv_64(u64 n) {
    u64 r = n;
    for (int i = 0; i < 5; ++i) {
        r *= 2 - n * r;
    }
    return r;
}

// n: odd, < 2^{62}
struct Montgomery64 {
    u64 n, mni, p;
    Montgomery64(u64 n) : n(n), mni(-inv_64(n)), p(-1ULL % n + 1) {}
    u64 mulmr(u64 xr, u64 yr) const {
        u128 z = (u128)xr * yr;
        u64 ret = (z + (u128)((u64)z * mni) * n) >> 64;
        if (ret >= n) {
            ret -= n;
        }
        return ret;
    }
    u64 mr(u64 xr) const {
        u64 ret = (xr + (u128)(xr * mni) * n) >> 64;
        if (ret >= n) {
            ret -= n;
        }
        return ret;
    }
    u64 pow(u64 xr, u64 t) const {
        u64 ret = p;
        while (t) {
            if (t & 1) {
                ret = mulmr(ret, xr);
            }
            xr = mulmr(xr, xr);
            t >>= 1;
        }
        return ret;
    }
};

bool is_prime(u64 n) {
    if (n == 2) {
        return true;
    }
    if (n == 1 || n % 2 == 0) {
        return false;
    }
    u64 s = __builtin_ctzll(n - 1);
    u64 d = (n - 1) >> s;
    u64 base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    Montgomery64 mont(n);
    u64 fl = n - mont.p;
    for (u64 b : base) {
        b = mont.mr(b);
        if (!b) {
            continue;
        }
        u64 t = mont.pow(b, d);
        if (t == mont.p) {
            continue;
        }
        u64 i = 0;
        for (; i < s; ++i) {
            if (t == fl) {
                break;
            }
            t = mont.mulmr(t, t);
        }
        if (i == s) {
            return false;
        }
    }
    return true;
}

}  // namespace primality

bool is_prime(unsigned long long n) {
    return primality::is_prime(n);
}
