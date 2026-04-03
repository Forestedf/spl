---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: number_theory/dynamic_mod_int.hpp
    title: number_theory/dynamic_mod_int.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number_theory/test/dynamic_modint_stress.test.cpp
    title: number_theory/test/dynamic_modint_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/barrett.hpp\"\n\nstruct Barrett {\n    unsigned\
    \ m;\n    unsigned long long im;\n    explicit Barrett(unsigned m) : m(m), im(-1ull\
    \ / m + 1) {}\n    unsigned mul(unsigned x, unsigned y) const {\n        unsigned\
    \ long long z = (unsigned long long)x * y;\n        unsigned long long q = ((__uint128_t)z\
    \ * im) >> 64;\n        unsigned long long t = q * m;\n        return z - t +\
    \ (z < t ? m : 0);\n    }\n};\n"
  code: "#pragma once\n\nstruct Barrett {\n    unsigned m;\n    unsigned long long\
    \ im;\n    explicit Barrett(unsigned m) : m(m), im(-1ull / m + 1) {}\n    unsigned\
    \ mul(unsigned x, unsigned y) const {\n        unsigned long long z = (unsigned\
    \ long long)x * y;\n        unsigned long long q = ((__uint128_t)z * im) >> 64;\n\
    \        unsigned long long t = q * m;\n        return z - t + (z < t ? m : 0);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/barrett.hpp
  requiredBy:
  - number_theory/dynamic_mod_int.hpp
  timestamp: '2026-04-03 09:13:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/dynamic_modint_stress.test.cpp
documentation_of: number_theory/barrett.hpp
layout: document
redirect_from:
- /library/number_theory/barrett.hpp
- /library/number_theory/barrett.hpp.html
title: number_theory/barrett.hpp
---
