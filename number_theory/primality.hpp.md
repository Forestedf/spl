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
    path: number_theory/test/primality_test.test.cpp
    title: number_theory/test/primality_test.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/primitive_root.test.cpp
    title: number_theory/test/primitive_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/primality.hpp\"\n\nnamespace primality {\n\
    \nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\nu64 inv_64(u64\
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
    \ {\n    return primality::is_prime(n);\n}\n"
  code: "#pragma once\n\nnamespace primality {\n\nusing u64 = unsigned long long;\n\
    using u128 = __uint128_t;\n\nu64 inv_64(u64 n) {\n    u64 r = n;\n    for (int\
    \ i = 0; i < 5; ++i) {\n        r *= 2 - n * r;\n    }\n    return r;\n}\n\n//\
    \ n: odd, < 2^{62}\nstruct Montgomery64 {\n    u64 n, mni, p;\n    Montgomery64(u64\
    \ n) : n(n), mni(-inv_64(n)), p(-1ULL % n + 1) {}\n    u64 mulmr(u64 xr, u64 yr)\
    \ const {\n        u128 z = (u128)xr * yr;\n        u64 ret = (z + (u128)((u64)z\
    \ * mni) * n) >> 64;\n        if (ret >= n) {\n            ret -= n;\n       \
    \ }\n        return ret;\n    }\n    u64 mr(u64 xr) const {\n        u64 ret =\
    \ (xr + (u128)(xr * mni) * n) >> 64;\n        if (ret >= n) {\n            ret\
    \ -= n;\n        }\n        return ret;\n    }\n    u64 pow(u64 xr, u64 t) const\
    \ {\n        u64 ret = p;\n        while (t) {\n            if (t & 1) {\n   \
    \             ret = mulmr(ret, xr);\n            }\n            xr = mulmr(xr,\
    \ xr);\n            t >>= 1;\n        }\n        return ret;\n    }\n};\n\nbool\
    \ is_prime(u64 n) {\n    if (n == 2) {\n        return true;\n    }\n    if (n\
    \ == 1 || n % 2 == 0) {\n        return false;\n    }\n    u64 s = __builtin_ctzll(n\
    \ - 1);\n    u64 d = (n - 1) >> s;\n    u64 base[] = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022};\n    Montgomery64 mont(n);\n    u64 fl = n - mont.p;\n\
    \    for (u64 b : base) {\n        b = mont.mr(b);\n        if (!b) {\n      \
    \      continue;\n        }\n        u64 t = mont.pow(b, d);\n        if (t ==\
    \ mont.p) {\n            continue;\n        }\n        u64 i = 0;\n        for\
    \ (; i < s; ++i) {\n            if (t == fl) {\n                break;\n     \
    \       }\n            t = mont.mulmr(t, t);\n        }\n        if (i == s) {\n\
    \            return false;\n        }\n    }\n    return true;\n}\n\n}  // namespace\
    \ primality\n\nbool is_prime(unsigned long long n) {\n    return primality::is_prime(n);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/primality.hpp
  requiredBy:
  - number_theory/factorize.hpp
  - number_theory/primitive_root.hpp
  - convolution/mul_mod_p_conv.hpp
  timestamp: '2025-01-27 10:50:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/factorize.test.cpp
  - number_theory/test/primality_test.test.cpp
  - number_theory/test/primitive_root.test.cpp
  - convolution/test/mul_modp_convolution.test.cpp
documentation_of: number_theory/primality.hpp
layout: document
redirect_from:
- /library/number_theory/primality.hpp
- /library/number_theory/primality.hpp.html
title: number_theory/primality.hpp
---
