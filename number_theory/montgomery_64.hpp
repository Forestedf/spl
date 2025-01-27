#pragma once
#include <cassert>

// mod: odd, < 2^{63}
template <int id>
struct MontgomeryModInt64 {
    using u64 = unsigned long long;
    using u128 = __uint128_t;

    static u64 inv_64(u64 n) {
        u64 r = n;
        for (int i = 0; i < 5; ++i) {
            r *= 2 - n * r;
        }
        return r;
    }

    static u64 mod, neg_inv, sq;
    static void set_mod(u64 m) {
        assert(m % 2 == 1 && m < (1ULL << 63));
        mod = m;
        neg_inv = -inv_64(m);
        sq = -u128(mod) % mod;
    }
    static u64 get_mod() { return mod; }

    static u64 reduce(u128 xr) {
        u64 ret = (xr + u128(u64(xr) * neg_inv) * mod) >> 64;
        if (ret >= mod) {
            ret -= mod;
        }
        return ret;
    }

    using M = MontgomeryModInt64<id>;

    u64 x;
    MontgomeryModInt64() : x(0) {}
    MontgomeryModInt64(u64 _x) : x(reduce(u128(_x) * sq)) {}

    u64 val() const { return reduce(u128(x)); }

    M &operator+=(M rhs) {
        if ((x += rhs.x) >= mod) {
            x -= mod;
        }
        return *this;
    }
    M &operator-=(M rhs) {
        if ((x -= rhs.x) >= mod) {
            x += mod;
        }
        return *this;
    }
    M &operator*=(M rhs) {
        x = reduce(u128(x) * rhs.x);
        return *this;
    }
    M operator+(M rhs) const { return M(*this) += rhs; }
    M operator-(M rhs) const { return M(*this) -= rhs; }
    M operator*(M rhs) const { return M(*this) *= rhs; }

    M pow(u64 t) const {
        M ret(1);
        M self = *this;
        while (t) {
            if (t & 1) {
                ret *= self;
            }
            self *= self;
            t >>= 1;
        }
        return ret;
    }
    M inv() const {
        assert(x);
        return this->pow(mod - 2);
    }

    M &operator/=(M rhs) {
        *this /= rhs.inv();
        return *this;
    }
    M operator/(M rhs) const { return M(*this) /= rhs; }
};

template <int id> unsigned long long MontgomeryModInt64<id>::mod = 1;
template <int id> unsigned long long MontgomeryModInt64<id>::neg_inv = 1;
template <int id> unsigned long long MontgomeryModInt64<id>::sq = 1;
