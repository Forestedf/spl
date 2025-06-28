---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number_theory/test/binary_gcd_stress.test.cpp
    title: number_theory/test/binary_gcd_stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/binary_gcd.hpp\"\n\nunsigned long long binary_gcd(unsigned\
    \ long long x, unsigned long long y) {\n    if (x == 0) {\n        return y;\n\
    \    }\n    if (y == 0) {\n        return x;\n    }\n    int a = __builtin_ctz(x);\n\
    \    int b = __builtin_ctz(y);\n    x >>= a;\n    y >>= b;\n    while (x != y)\
    \ {\n        int m = __builtin_ctz(x - y);\n        if (x > y) {\n           \
    \ x = (x - y) >> m;\n        } else {\n            y = (y - x) >> m;\n       \
    \ }\n    }\n    return x << (a < b ? a : b);\n}\n"
  code: "#pragma once\n\nunsigned long long binary_gcd(unsigned long long x, unsigned\
    \ long long y) {\n    if (x == 0) {\n        return y;\n    }\n    if (y == 0)\
    \ {\n        return x;\n    }\n    int a = __builtin_ctz(x);\n    int b = __builtin_ctz(y);\n\
    \    x >>= a;\n    y >>= b;\n    while (x != y) {\n        int m = __builtin_ctz(x\
    \ - y);\n        if (x > y) {\n            x = (x - y) >> m;\n        } else {\n\
    \            y = (y - x) >> m;\n        }\n    }\n    return x << (a < b ? a :\
    \ b);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/binary_gcd.hpp
  requiredBy: []
  timestamp: '2025-05-31 22:12:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/binary_gcd_stress.test.cpp
documentation_of: number_theory/binary_gcd.hpp
layout: document
redirect_from:
- /library/number_theory/binary_gcd.hpp
- /library/number_theory/binary_gcd.hpp.html
title: number_theory/binary_gcd.hpp
---
