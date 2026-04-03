#pragma once
#include "barrett.hpp"
#include "utils.hpp"
#include <cassert>
#include <iostream>
#include <type_traits>

template <int ID>
struct DynamicModInt {
    using M = DynamicModInt<ID>;
    static Barrett br;
    unsigned val;
    
    static unsigned get_mod() {
        return br.m;
    }
    static void set_mod(unsigned m) {
        assert(1 <= m && m < (1u << 31));
        br = Barrett(m);
    }
    
    DynamicModInt() : val(0) {}
    template <typename T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>
    DynamicModInt(T x) {
        long long x_ = (long long)x % (long long)br.m;
        if (x_ < 0) {
            x_ += br.m;
        }
        val = x_;
    }
    template <typename T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>
    DynamicModInt(T x) : val((unsigned)(x % br.m)) {}
    
    template <typename T>
    M raw(T x) {
        M ret;
        ret.val = x;
        return ret;
    }
    
    unsigned get_val() const {
        return val;
    }
    
    M operator+() const { return *this; }
    M operator-() const { return M() - *this; }

    M &operator+=(const M &rhs) {
        val += rhs.val;
        if (val >= br.m) val -= br.m;
        return *this;
    }
    M &operator-=(const M &rhs) {
        val -= rhs.val;
        if (val >= br.m) val += br.m;
        return *this;
    }
    M &operator*=(const M &rhs) {
        val = br.mul(val, rhs.val);
        return *this;
    }
    M &operator/=(const M &rhs) {
        return *this *= rhs.inv();
    }

    M inv() const {
        auto [g, x] = extgcd(val, br.m);
        assert(g == 1);
        return M::raw(x);
    }
    M pow(unsigned long long x) const {
        M ret = M::raw(1);
        M self = *this;
        while (x != 0) {
            if (x & 1) ret *= self;
            self *= self;
            x >>= 1;
        }
        return ret;
    }
    
    friend M operator+(const M &lhs, const M &rhs) {
        return M(lhs) += rhs;
    }
    friend M operator-(const M &lhs, const M &rhs) {
        return M(lhs) -= rhs;
    }
    friend M operator*(const M &lhs, const M &rhs) {
        return M(lhs) *= rhs;
    }
    friend M operator/(const M &lhs, const M &rhs) {
        return M(lhs) /= rhs;
    }
    friend bool operator==(const M &lhs, const M &rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const M &lhs, const M &rhs) {
        return lhs.val != rhs.val;
    }
};

template <int ID>
Barrett DynamicModInt<ID>::br(998244353);
