---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number_theory/test/ax_by_c_stress.test.cpp
    title: number_theory/test/ax_by_c_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/ax_by_c.hpp\"\n\n#line 2 \"number_theory/utils.hpp\"\
    \n\n#include <utility>\n\nconstexpr bool is_prime(unsigned n) {\n    if (n ==\
    \ 0 || n == 1) {\n        return false;\n    }\n    for (unsigned i = 2; i * i\
    \ <= n; ++i) {\n        if (n % i == 0) {\n            return false;\n       \
    \ }\n    }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned x, unsigned\
    \ y, unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y != 0) {\n\
    \        if (y & 1) {\n            ret = (unsigned)((unsigned long long)ret *\
    \ self % mod);\n        }\n        self = (unsigned)((unsigned long long)self\
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
    \ (x + y - 1) / y;\n    } else {\n        return -(-x / y);\n    }\n}\n\n// b\
    \ >= 1\n// returns (g, x) s.t. g = gcd(a, b), a * x = g (mod b), 0 <= x < b /\
    \ g\n// from ACL\ntemplate <typename T>\nstd::pair<T, T> extgcd(T a, T b) {\n\
    \    a = safe_mod(a, b);\n    T s = b, t = a, m0 = 0, m1 = 1;\n    while (t) {\n\
    \        T u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        std::swap(s,\
    \ t);\n        std::swap(m0, m1);\n    }\n    if (m0 < 0) {\n        m0 += b /\
    \ s;\n    }\n    return std::pair<T, T>(s, m0);\n}\n\n// b >= 1\n// returns (g,\
    \ x, y) s.t. g = gcd(a, b), a * x + b * y = g, 0 <= x < b / g, |y| < max(2, |a|\
    \ / g)\ntemplate <typename T>\nstd::tuple<T, T, T> extgcd2(T a, T b) {\n    T\
    \ _a = safe_mod(a, b);\n    T quot = (a - _a) / b;\n    T x00 = 0, x01 = 1, y0\
    \ = b;\n    T x10 = 1, x11 = -quot, y1 = _a;\n    while (y1) {\n        T u =\
    \ y0 / y1;\n        x00 -= u * x10;\n        x01 -= u * x11;\n        y0 -= u\
    \ * y1;\n        std::swap(x00, x10);\n        std::swap(x01, x11);\n        std::swap(y0,\
    \ y1);\n    }\n    if (x00 < 0) {\n        x00 += b / y0;\n        x01 -= a /\
    \ y0;\n    }\n    return std::tuple<T, T, T>(y0, x00, x01);\n}\n\n// gcd(x, m)\
    \ == 1\ntemplate <typename T>\nT inv_mod(T x, T m) {\n    return extgcd(x, m).second;\n\
    }\n#line 4 \"number_theory/ax_by_c.hpp\"\n#include <optional>\n\n// solve a *\
    \ x + b * y = c\n// |x| <= |b * c|, |y| <= |a * c| (|a|, |b|, |c| > 0)\ntemplate\
    \ <typename T>\nstd::optional<std::pair<T, T>> ax_by_c(T a, T b, T c) {\n    if\
    \ (c == 0) {\n        return std::pair<T, T>(0, 0);\n    }\n    if (a == 0 &&\
    \ b == 0) {\n        return std::nullopt;\n    }\n    if (a == 0) {\n        if\
    \ (c % b) {\n            return std::nullopt;\n        }\n        return std::pair<T,\
    \ T>(0, c / b);\n    }\n    if (b == 0) {\n        if (c % a) {\n            return\
    \ std::nullopt;\n        }\n        return std::pair<T, T>(c / a, 0);\n    }\n\
    \    if (b < 0) {\n        a = -a;\n        b = -b;\n        c = -c;\n    }\n\
    \    auto [g, x, y] = extgcd2(a, b);\n    if (c % g) {\n        return std::nullopt;\n\
    \    }\n    T mult = c / g;\n    x *= mult;\n    y *= mult;\n    return std::pair<T,\
    \ T>(x, y);\n}\n"
  code: "#pragma once\n\n#include \"utils.hpp\"\n#include <optional>\n\n// solve a\
    \ * x + b * y = c\n// |x| <= |b * c|, |y| <= |a * c| (|a|, |b|, |c| > 0)\ntemplate\
    \ <typename T>\nstd::optional<std::pair<T, T>> ax_by_c(T a, T b, T c) {\n    if\
    \ (c == 0) {\n        return std::pair<T, T>(0, 0);\n    }\n    if (a == 0 &&\
    \ b == 0) {\n        return std::nullopt;\n    }\n    if (a == 0) {\n        if\
    \ (c % b) {\n            return std::nullopt;\n        }\n        return std::pair<T,\
    \ T>(0, c / b);\n    }\n    if (b == 0) {\n        if (c % a) {\n            return\
    \ std::nullopt;\n        }\n        return std::pair<T, T>(c / a, 0);\n    }\n\
    \    if (b < 0) {\n        a = -a;\n        b = -b;\n        c = -c;\n    }\n\
    \    auto [g, x, y] = extgcd2(a, b);\n    if (c % g) {\n        return std::nullopt;\n\
    \    }\n    T mult = c / g;\n    x *= mult;\n    y *= mult;\n    return std::pair<T,\
    \ T>(x, y);\n}\n"
  dependsOn:
  - number_theory/utils.hpp
  isVerificationFile: false
  path: number_theory/ax_by_c.hpp
  requiredBy: []
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/ax_by_c_stress.test.cpp
documentation_of: number_theory/ax_by_c.hpp
layout: document
redirect_from:
- /library/number_theory/ax_by_c.hpp
- /library/number_theory/ax_by_c.hpp.html
title: number_theory/ax_by_c.hpp
---
