---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/montgomery_64.hpp
    title: number_theory/montgomery_64.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/primality.hpp
    title: number_theory/primality.hpp
  - icon: ':heavy_check_mark:'
    path: template/random.hpp
    title: template/random.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/mul_mod_p_conv.hpp
    title: convolution/mul_mod_p_conv.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/primitive_root.hpp
    title: number_theory/primitive_root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/mul_modp_convolution.test.cpp
    title: convolution/test/mul_modp_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/factorize.test.cpp
    title: number_theory/test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/primitive_root.test.cpp
    title: number_theory/test/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/factorize.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#line 2 \"template/random.hpp\"\n#include <chrono>\n#include <random>\n\
    \n#if defined(LOCAL) || defined(FIX_SEED)\nstd::mt19937_64 mt(123456789);\n#else\n\
    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    #endif\n\ntemplate <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 2 \"number_theory/primality.hpp\"\n\nnamespace primality\
    \ {\n\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\nu64 inv_64(u64\
    \ n) {\n    u64 r = n;\n    for (int i = 0; i < 5; ++i) {\n        r *= 2 - n\
    \ * r;\n    }\n    return r;\n}\n\n// n: odd, < 2^{62}\nstruct Montgomery64 {\n\
    \    u64 n, mni, p;\n    Montgomery64(u64 n) : n(n), mni(-inv_64(n)), p(-1ULL\
    \ % n + 1) {}\n    u64 mulmr(u64 xr, u64 yr) const {\n        u128 z = (u128)xr\
    \ * yr;\n        u64 ret = (z + (u128)((u64)z * mni) * n) >> 64;\n        if (ret\
    \ >= n) {\n            ret -= n;\n        }\n        return ret;\n    }\n    u64\
    \ mr(u64 xr) const {\n        u64 ret = (xr + (u128)(xr * mni) * n) >> 64;\n \
    \       if (ret >= n) {\n            ret -= n;\n        }\n        return ret;\n\
    \    }\n    u64 pow(u64 xr, u64 t) const {\n        u64 ret = p;\n        while\
    \ (t) {\n            if (t & 1) {\n                ret = mulmr(ret, xr);\n   \
    \         }\n            xr = mulmr(xr, xr);\n            t >>= 1;\n        }\n\
    \        return ret;\n    }\n};\n\nbool is_prime(u64 n) {\n    if (n == 2) {\n\
    \        return true;\n    }\n    if (n == 1 || n % 2 == 0) {\n        return\
    \ false;\n    }\n    u64 s = __builtin_ctzll(n - 1);\n    u64 d = (n - 1) >> s;\n\
    \    u64 base[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n    Montgomery64\
    \ mont(n);\n    u64 fl = n - mont.p;\n    for (u64 b : base) {\n        b = mont.mr(b);\n\
    \        if (!b) {\n            continue;\n        }\n        u64 t = mont.pow(b,\
    \ d);\n        if (t == mont.p) {\n            continue;\n        }\n        u64\
    \ i = 0;\n        for (; i < s; ++i) {\n            if (t == fl) {\n         \
    \       break;\n            }\n            t = mont.mulmr(t, t);\n        }\n\
    \        if (i == s) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n\n}  // namespace primality\n\nbool is_prime(unsigned long long n)\
    \ {\n    return primality::is_prime(n);\n}\n#line 2 \"number_theory/montgomery_64.hpp\"\
    \n#include <cassert>\n\n// mod: odd, < 2^{63}\ntemplate <int id>\nstruct MontgomeryModInt64\
    \ {\n    using u64 = unsigned long long;\n    using u128 = __uint128_t;\n\n  \
    \  static u64 inv_64(u64 n) {\n        u64 r = n;\n        for (int i = 0; i <\
    \ 5; ++i) {\n            r *= 2 - n * r;\n        }\n        return r;\n    }\n\
    \n    static u64 mod, neg_inv, sq;\n    static void set_mod(u64 m) {\n       \
    \ assert(m % 2 == 1 && m < (1ULL << 63));\n        mod = m;\n        neg_inv =\
    \ -inv_64(m);\n        sq = -u128(mod) % mod;\n    }\n    static u64 get_mod()\
    \ { return mod; }\n\n    static u64 reduce(u128 xr) {\n        u64 ret = (xr +\
    \ u128(u64(xr) * neg_inv) * mod) >> 64;\n        if (ret >= mod) {\n         \
    \   ret -= mod;\n        }\n        return ret;\n    }\n\n    using M = MontgomeryModInt64<id>;\n\
    \n    u64 x;\n    MontgomeryModInt64() : x(0) {}\n    MontgomeryModInt64(u64 _x)\
    \ : x(reduce(u128(_x) * sq)) {}\n\n    u64 val() const { return reduce(u128(x));\
    \ }\n\n    M &operator+=(M rhs) {\n        if ((x += rhs.x) >= mod) {\n      \
    \      x -= mod;\n        }\n        return *this;\n    }\n    M &operator-=(M\
    \ rhs) {\n        if ((x -= rhs.x) >= mod) {\n            x += mod;\n        }\n\
    \        return *this;\n    }\n    M &operator*=(M rhs) {\n        x = reduce(u128(x)\
    \ * rhs.x);\n        return *this;\n    }\n    M operator+(M rhs) const { return\
    \ M(*this) += rhs; }\n    M operator-(M rhs) const { return M(*this) -= rhs; }\n\
    \    M operator*(M rhs) const { return M(*this) *= rhs; }\n\n    M pow(u64 t)\
    \ const {\n        M ret(1);\n        M self = *this;\n        while (t) {\n \
    \           if (t & 1) {\n                ret *= self;\n            }\n      \
    \      self *= self;\n            t >>= 1;\n        }\n        return ret;\n \
    \   }\n    M inv() const {\n        assert(x);\n        return this->pow(mod -\
    \ 2);\n    }\n\n    M &operator/=(M rhs) {\n        *this /= rhs.inv();\n    \
    \    return *this;\n    }\n    M operator/(M rhs) const { return M(*this) /= rhs;\
    \ }\n};\n\ntemplate <int id> unsigned long long MontgomeryModInt64<id>::mod =\
    \ 1;\ntemplate <int id> unsigned long long MontgomeryModInt64<id>::neg_inv = 1;\n\
    template <int id> unsigned long long MontgomeryModInt64<id>::sq = 1;\n#line 7\
    \ \"number_theory/factorize.hpp\"\n\nnamespace factorize_impl {\n\nunsigned long\
    \ long bgcd(unsigned long long x, unsigned long long y) {\n    if (x == 0) {\n\
    \        return y;\n    }\n    if (y == 0) {\n        return x;\n    }\n    int\
    \ n = __builtin_ctzll(x);\n    int m = __builtin_ctzll(y);\n    x >>= n;\n   \
    \ y >>= m;\n    while (x != y) {\n        if (x > y) {\n            x = (x - y)\
    \ >> __builtin_ctzll(x - y);\n        } else {\n            y = (y - x) >> __builtin_ctzll(y\
    \ - x);\n        }\n    }\n    return x << (n < m ? n : m);\n}\n\ntemplate <typename\
    \ T>\nunsigned long long rho(unsigned long long n, unsigned long long c) {\n \
    \   T cc(c);\n    auto f = [cc](T x) -> T {\n        return x * x + cc;\n    };\n\
    \    T y(2);\n    T x = y;\n    T z = y;\n    T p(1);\n    unsigned long long\
    \ g = 1;\n    constexpr int M = 128;\n    for (int r = 1; g == 1; r *= 2) {\n\
    \        x = y;\n        for (int i = 0; i < r && g == 1; i += M) {\n        \
    \    z = y;\n            for (int j = 0; j < r - i && j < M; ++j) {\n        \
    \        y = f(y);\n                p *= y - x;\n            }\n            g\
    \ = bgcd(p.val(), n);\n        }\n    }\n    if (g == n) {\n        do {\n   \
    \         z = f(z);\n            g = bgcd((z - x).val(), n);\n        } while\
    \ (g == 1);\n    }\n    return g;\n}\n\nunsigned long long find_factor(unsigned\
    \ long long n) {\n    using M = MontgomeryModInt64<20250127>;\n    M::set_mod(n);\n\
    \    while (true) {\n        unsigned long long c = uniform(n);\n        unsigned\
    \ long long g = rho<M>(n, c);\n        if (g != n) {\n            return g;\n\
    \        }\n    }\n    return 0;\n}\n\nvoid factor_inner(unsigned long long n,\
    \ std::vector<unsigned long long> &ps) {\n    if (is_prime(n)) {\n        ps.push_back(n);\n\
    \        return;\n    }\n    if (n % 2 == 0) {\n        ps.push_back(2);\n   \
    \     factor_inner(n / 2, ps);\n        return;\n    }\n    unsigned long long\
    \ m = find_factor(n);\n    factor_inner(m, ps);\n    factor_inner(n / m, ps);\n\
    }\n\n}\n\nstd::vector<unsigned long long> factorize(unsigned long long n) {\n\
    \    if (n <= 1) {\n        return std::vector<unsigned long long>();\n    }\n\
    \    std::vector<unsigned long long> ps;\n    factorize_impl::factor_inner(n,\
    \ ps);\n    std::sort(ps.begin(), ps.end());\n    return ps;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../template/random.hpp\"\
    \n#include \"primality.hpp\"\n#include \"montgomery_64.hpp\"\n\nnamespace factorize_impl\
    \ {\n\nunsigned long long bgcd(unsigned long long x, unsigned long long y) {\n\
    \    if (x == 0) {\n        return y;\n    }\n    if (y == 0) {\n        return\
    \ x;\n    }\n    int n = __builtin_ctzll(x);\n    int m = __builtin_ctzll(y);\n\
    \    x >>= n;\n    y >>= m;\n    while (x != y) {\n        if (x > y) {\n    \
    \        x = (x - y) >> __builtin_ctzll(x - y);\n        } else {\n          \
    \  y = (y - x) >> __builtin_ctzll(y - x);\n        }\n    }\n    return x << (n\
    \ < m ? n : m);\n}\n\ntemplate <typename T>\nunsigned long long rho(unsigned long\
    \ long n, unsigned long long c) {\n    T cc(c);\n    auto f = [cc](T x) -> T {\n\
    \        return x * x + cc;\n    };\n    T y(2);\n    T x = y;\n    T z = y;\n\
    \    T p(1);\n    unsigned long long g = 1;\n    constexpr int M = 128;\n    for\
    \ (int r = 1; g == 1; r *= 2) {\n        x = y;\n        for (int i = 0; i < r\
    \ && g == 1; i += M) {\n            z = y;\n            for (int j = 0; j < r\
    \ - i && j < M; ++j) {\n                y = f(y);\n                p *= y - x;\n\
    \            }\n            g = bgcd(p.val(), n);\n        }\n    }\n    if (g\
    \ == n) {\n        do {\n            z = f(z);\n            g = bgcd((z - x).val(),\
    \ n);\n        } while (g == 1);\n    }\n    return g;\n}\n\nunsigned long long\
    \ find_factor(unsigned long long n) {\n    using M = MontgomeryModInt64<20250127>;\n\
    \    M::set_mod(n);\n    while (true) {\n        unsigned long long c = uniform(n);\n\
    \        unsigned long long g = rho<M>(n, c);\n        if (g != n) {\n       \
    \     return g;\n        }\n    }\n    return 0;\n}\n\nvoid factor_inner(unsigned\
    \ long long n, std::vector<unsigned long long> &ps) {\n    if (is_prime(n)) {\n\
    \        ps.push_back(n);\n        return;\n    }\n    if (n % 2 == 0) {\n   \
    \     ps.push_back(2);\n        factor_inner(n / 2, ps);\n        return;\n  \
    \  }\n    unsigned long long m = find_factor(n);\n    factor_inner(m, ps);\n \
    \   factor_inner(n / m, ps);\n}\n\n}\n\nstd::vector<unsigned long long> factorize(unsigned\
    \ long long n) {\n    if (n <= 1) {\n        return std::vector<unsigned long\
    \ long>();\n    }\n    std::vector<unsigned long long> ps;\n    factorize_impl::factor_inner(n,\
    \ ps);\n    std::sort(ps.begin(), ps.end());\n    return ps;\n}\n"
  dependsOn:
  - template/random.hpp
  - number_theory/primality.hpp
  - number_theory/montgomery_64.hpp
  isVerificationFile: false
  path: number_theory/factorize.hpp
  requiredBy:
  - convolution/mul_mod_p_conv.hpp
  - number_theory/primitive_root.hpp
  timestamp: '2025-01-27 21:54:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/mul_modp_convolution.test.cpp
  - number_theory/test/primitive_root.test.cpp
  - number_theory/test/factorize.test.cpp
documentation_of: number_theory/factorize.hpp
layout: document
redirect_from:
- /library/number_theory/factorize.hpp
- /library/number_theory/factorize.hpp.html
title: number_theory/factorize.hpp
---
