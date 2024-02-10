---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/1891.test.cpp
    title: data_structure/test/1891.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_set_range_composite.test.cpp
    title: data_structure/test/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/queue_operate_all_composite.test.cpp
    title: data_structure/test/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_affine_range_sum.test.cpp
    title: data_structure/test/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: number_theory/test/inv_mod_stress.test.cpp
    title: number_theory/test/inv_mod_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/utils.hpp\"\n\n#include <utility>\n\nconstexpr\
    \ bool is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n        return false;\n\
    \    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n\
    \            return false;\n        }\n    }\n    return true;\n}\n\nconstexpr\
    \ unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {\n    unsigned ret =\
    \ 1, self = x;\n    while (y != 0) {\n        if (y & 1) {\n            ret =\
    \ (unsigned)((unsigned long long)ret * self % mod);\n        }\n        self =\
    \ (unsigned)((unsigned long long)self * self % mod);\n        y /= 2;\n    }\n\
    \    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr unsigned primitive_root()\
    \ {\n    static_assert(is_prime(mod), \"`mod` must be a prime number.\");\n  \
    \  if (mod == 2) {\n        return 1;\n    }\n\n    unsigned primes[32] = {};\n\
    \    int it = 0;\n    {\n        unsigned m = mod - 1;\n        for (unsigned\
    \ i = 2; i * i <= m; ++i) {\n            if (m % i == 0) {\n                primes[it++]\
    \ = i;\n                while (m % i == 0) {\n                    m /= i;\n  \
    \              }\n            }\n        }\n        if (m != 1) {\n          \
    \  primes[it++] = m;\n        }\n    }\n    for (unsigned i = 2; i < mod; ++i)\
    \ {\n        bool ok = true;\n        for (int j = 0; j < it; ++j) {\n       \
    \     if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {\n                ok =\
    \ false;\n                break;\n            }\n        }\n        if (ok) return\
    \ i;\n    }\n    return 0;\n}\n\n// y >= 1\ntemplate <typename T>\nconstexpr T\
    \ safe_mod(T x, T y) {\n    x %= y;\n    if (x < 0) {\n        x += y;\n    }\n\
    \    return x;\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr T floor_div(T\
    \ x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n   \
    \ if (x >= 0) {\n        return x / y;\n    } else {\n        return -((-x + y\
    \ - 1) / y);\n    }\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr T ceil_div(T\
    \ x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n   \
    \ if (x >= 0) {\n        return (x + y - 1) / y;\n    } else {\n        return\
    \ -(-x / y);\n    }\n}\n\n// a, b >= 1\n// finds (x, y) such that |x| <= b, |y|\
    \ <= a, a * x + b * y == gcd(a, b)\ntemplate <typename T>\nstd::pair<T, T> extgcd(T\
    \ a, T b) {\n    if (a % b == 0) {\n        return std::pair<T, T>(0, 1);\n  \
    \  } else {\n        T q = a / b, r = a % b;\n        auto [c, d] = extgcd(b,\
    \ r);\n        return std::pair<T, T>(d, c - q * d);\n    }\n}\n\n// gcd(x, m)\
    \ == 1\ntemplate <typename T>\nT inv_mod(T x, T m) {\n    auto [a, b] = extgcd(x,\
    \ m);\n    if (a < 0) {\n        a += m;\n    }\n    if (a == m) {\n        a\
    \ -= m;\n    }\n    return a;\n}\n"
  code: "#pragma once\n\n#include <utility>\n\nconstexpr bool is_prime(unsigned n)\
    \ {\n    if (n == 0 || n == 1) {\n        return false;\n    }\n    for (unsigned\
    \ i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned\
    \ x, unsigned y, unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y\
    \ != 0) {\n        if (y & 1) {\n            ret = (unsigned)((unsigned long long)ret\
    \ * self % mod);\n        }\n        self = (unsigned)((unsigned long long)self\
    \ * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned\
    \ mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n    if (mod == 2) {\n        return 1;\n\
    \    }\n\n    unsigned primes[32] = {};\n    int it = 0;\n    {\n        unsigned\
    \ m = mod - 1;\n        for (unsigned i = 2; i * i <= m; ++i) {\n            if\
    \ (m % i == 0) {\n                primes[it++] = i;\n                while (m\
    \ % i == 0) {\n                    m /= i;\n                }\n            }\n\
    \        }\n        if (m != 1) {\n            primes[it++] = m;\n        }\n\
    \    }\n    for (unsigned i = 2; i < mod; ++i) {\n        bool ok = true;\n  \
    \      for (int j = 0; j < it; ++j) {\n            if (mod_pow(i, (mod - 1) /\
    \ primes[j], mod) == 1) {\n                ok = false;\n                break;\n\
    \            }\n        }\n        if (ok) return i;\n    }\n    return 0;\n}\n\
    \n// y >= 1\ntemplate <typename T>\nconstexpr T safe_mod(T x, T y) {\n    x %=\
    \ y;\n    if (x < 0) {\n        x += y;\n    }\n    return x;\n}\n\n// y != 0\n\
    template <typename T>\nconstexpr T floor_div(T x, T y) {\n    if (y < 0) {\n \
    \       x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return x\
    \ / y;\n    } else {\n        return -((-x + y - 1) / y);\n    }\n}\n\n// y !=\
    \ 0\ntemplate <typename T>\nconstexpr T ceil_div(T x, T y) {\n    if (y < 0) {\n\
    \        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return\
    \ (x + y - 1) / y;\n    } else {\n        return -(-x / y);\n    }\n}\n\n// a,\
    \ b >= 1\n// finds (x, y) such that |x| <= b, |y| <= a, a * x + b * y == gcd(a,\
    \ b)\ntemplate <typename T>\nstd::pair<T, T> extgcd(T a, T b) {\n    if (a % b\
    \ == 0) {\n        return std::pair<T, T>(0, 1);\n    } else {\n        T q =\
    \ a / b, r = a % b;\n        auto [c, d] = extgcd(b, r);\n        return std::pair<T,\
    \ T>(d, c - q * d);\n    }\n}\n\n// gcd(x, m) == 1\ntemplate <typename T>\nT inv_mod(T\
    \ x, T m) {\n    auto [a, b] = extgcd(x, m);\n    if (a < 0) {\n        a += m;\n\
    \    }\n    if (a == m) {\n        a -= m;\n    }\n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/utils.hpp
  requiredBy:
  - number_theory/mod_int.hpp
  timestamp: '2024-02-10 22:34:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/inv_mod_stress.test.cpp
  - data_structure/test/range_affine_range_sum.test.cpp
  - data_structure/test/1891.test.cpp
  - data_structure/test/queue_operate_all_composite.test.cpp
  - data_structure/test/point_set_range_composite.test.cpp
documentation_of: number_theory/utils.hpp
layout: document
redirect_from:
- /library/number_theory/utils.hpp
- /library/number_theory/utils.hpp.html
title: number_theory/utils.hpp
---
