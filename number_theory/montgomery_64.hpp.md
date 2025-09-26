---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/mul_mod_p_conv.hpp
    title: convolution/mul_mod_p_conv.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/factorize.hpp
    title: number_theory/factorize.hpp
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
    path: number_theory/test/montgomery_64_stress.test.cpp
    title: number_theory/test/montgomery_64_stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/primitive_root.test.cpp
    title: number_theory/test/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/montgomery_64.hpp\"\n#include <cassert>\n\n\
    // mod: odd, < 2^{63}\ntemplate <int id>\nstruct MontgomeryModInt64 {\n    using\
    \ u64 = unsigned long long;\n    using u128 = __uint128_t;\n\n    static u64 inv_64(u64\
    \ n) {\n        u64 r = n;\n        for (int i = 0; i < 5; ++i) {\n          \
    \  r *= 2 - n * r;\n        }\n        return r;\n    }\n\n    static u64 mod,\
    \ neg_inv, sq;\n    static void set_mod(u64 m) {\n        assert(m % 2 == 1 &&\
    \ m < (1ULL << 63));\n        mod = m;\n        neg_inv = -inv_64(m);\n      \
    \  sq = -u128(mod) % mod;\n    }\n    static u64 get_mod() { return mod; }\n\n\
    \    static u64 reduce(u128 xr) {\n        u64 ret = (xr + u128(u64(xr) * neg_inv)\
    \ * mod) >> 64;\n        if (ret >= mod) {\n            ret -= mod;\n        }\n\
    \        return ret;\n    }\n\n    using M = MontgomeryModInt64<id>;\n\n    u64\
    \ x;\n    MontgomeryModInt64() : x(0) {}\n    MontgomeryModInt64(u64 _x) : x(reduce(u128(_x)\
    \ * sq)) {}\n\n    u64 val() const { return reduce(u128(x)); }\n\n    M &operator+=(M\
    \ rhs) {\n        if ((x += rhs.x) >= mod) {\n            x -= mod;\n        }\n\
    \        return *this;\n    }\n    M &operator-=(M rhs) {\n        if ((x -= rhs.x)\
    \ >= mod) {\n            x += mod;\n        }\n        return *this;\n    }\n\
    \    M &operator*=(M rhs) {\n        x = reduce(u128(x) * rhs.x);\n        return\
    \ *this;\n    }\n    M operator+(M rhs) const { return M(*this) += rhs; }\n  \
    \  M operator-(M rhs) const { return M(*this) -= rhs; }\n    M operator*(M rhs)\
    \ const { return M(*this) *= rhs; }\n\n    M pow(u64 t) const {\n        M ret(1);\n\
    \        M self = *this;\n        while (t) {\n            if (t & 1) {\n    \
    \            ret *= self;\n            }\n            self *= self;\n        \
    \    t >>= 1;\n        }\n        return ret;\n    }\n    M inv() const {\n  \
    \      assert(x);\n        return this->pow(mod - 2);\n    }\n\n    M &operator/=(M\
    \ rhs) {\n        *this /= rhs.inv();\n        return *this;\n    }\n    M operator/(M\
    \ rhs) const { return M(*this) /= rhs; }\n};\n\ntemplate <int id> unsigned long\
    \ long MontgomeryModInt64<id>::mod = 1;\ntemplate <int id> unsigned long long\
    \ MontgomeryModInt64<id>::neg_inv = 1;\ntemplate <int id> unsigned long long MontgomeryModInt64<id>::sq\
    \ = 1;\n"
  code: "#pragma once\n#include <cassert>\n\n// mod: odd, < 2^{63}\ntemplate <int\
    \ id>\nstruct MontgomeryModInt64 {\n    using u64 = unsigned long long;\n    using\
    \ u128 = __uint128_t;\n\n    static u64 inv_64(u64 n) {\n        u64 r = n;\n\
    \        for (int i = 0; i < 5; ++i) {\n            r *= 2 - n * r;\n        }\n\
    \        return r;\n    }\n\n    static u64 mod, neg_inv, sq;\n    static void\
    \ set_mod(u64 m) {\n        assert(m % 2 == 1 && m < (1ULL << 63));\n        mod\
    \ = m;\n        neg_inv = -inv_64(m);\n        sq = -u128(mod) % mod;\n    }\n\
    \    static u64 get_mod() { return mod; }\n\n    static u64 reduce(u128 xr) {\n\
    \        u64 ret = (xr + u128(u64(xr) * neg_inv) * mod) >> 64;\n        if (ret\
    \ >= mod) {\n            ret -= mod;\n        }\n        return ret;\n    }\n\n\
    \    using M = MontgomeryModInt64<id>;\n\n    u64 x;\n    MontgomeryModInt64()\
    \ : x(0) {}\n    MontgomeryModInt64(u64 _x) : x(reduce(u128(_x) * sq)) {}\n\n\
    \    u64 val() const { return reduce(u128(x)); }\n\n    M &operator+=(M rhs) {\n\
    \        if ((x += rhs.x) >= mod) {\n            x -= mod;\n        }\n      \
    \  return *this;\n    }\n    M &operator-=(M rhs) {\n        if ((x -= rhs.x)\
    \ >= mod) {\n            x += mod;\n        }\n        return *this;\n    }\n\
    \    M &operator*=(M rhs) {\n        x = reduce(u128(x) * rhs.x);\n        return\
    \ *this;\n    }\n    M operator+(M rhs) const { return M(*this) += rhs; }\n  \
    \  M operator-(M rhs) const { return M(*this) -= rhs; }\n    M operator*(M rhs)\
    \ const { return M(*this) *= rhs; }\n\n    M pow(u64 t) const {\n        M ret(1);\n\
    \        M self = *this;\n        while (t) {\n            if (t & 1) {\n    \
    \            ret *= self;\n            }\n            self *= self;\n        \
    \    t >>= 1;\n        }\n        return ret;\n    }\n    M inv() const {\n  \
    \      assert(x);\n        return this->pow(mod - 2);\n    }\n\n    M &operator/=(M\
    \ rhs) {\n        *this /= rhs.inv();\n        return *this;\n    }\n    M operator/(M\
    \ rhs) const { return M(*this) /= rhs; }\n};\n\ntemplate <int id> unsigned long\
    \ long MontgomeryModInt64<id>::mod = 1;\ntemplate <int id> unsigned long long\
    \ MontgomeryModInt64<id>::neg_inv = 1;\ntemplate <int id> unsigned long long MontgomeryModInt64<id>::sq\
    \ = 1;\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/montgomery_64.hpp
  requiredBy:
  - convolution/mul_mod_p_conv.hpp
  - number_theory/factorize.hpp
  - number_theory/primitive_root.hpp
  timestamp: '2025-01-27 21:12:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/mul_modp_convolution.test.cpp
  - number_theory/test/primitive_root.test.cpp
  - number_theory/test/montgomery_64_stress.test.cpp
  - number_theory/test/factorize.test.cpp
documentation_of: number_theory/montgomery_64.hpp
layout: document
redirect_from:
- /library/number_theory/montgomery_64.hpp
- /library/number_theory/montgomery_64.hpp.html
title: number_theory/montgomery_64.hpp
---
