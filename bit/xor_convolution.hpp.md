---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: bit/test/bitwise_xor_convolution.test.cpp
    title: bit/test/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"bit/xor_convolution.hpp\"\n#include <cassert>\n#include\
    \ <type_traits>\n#include <vector>\ntemplate <typename T>\nvoid hadamard(int n,\
    \ std::vector<T> &a) {\n    for (int d = 0; d < n; ++d) {\n        for (int i\
    \ = 0; i < (1 << n); ++i) {\n            if ((i & (1 << d)) == 0) {\n        \
    \        T x = a[i], y = a[i ^ (1 << d)];\n                a[i] = x + y;\n   \
    \             a[i ^ (1 << d)] = x - y;\n            }\n        }\n    }\n}\ntemplate\
    \ <typename T>\nstd::vector<T> bitwise_xor_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size() && a.size() > 0);\n    int n = __builtin_ctz((unsigned)a.size());\n\
    \    assert((int)a.size() == (1 << n));\n    hadamard(n, a);\n    hadamard(n,\
    \ b);\n    for (int i = 0; i < (1 << n); ++i) {\n        a[i] *= b[i];\n    }\n\
    \    hadamard(n, a);\n    if constexpr (std::is_integral_v<T>) {\n        for\
    \ (int i = 0; i < (1 << n); ++i) {\n            a[i] /= 1 << n;\n        }\n \
    \   } else {\n        T inv = T(1 << n).inv();\n        for (int i = 0; i < (1\
    \ << n); ++i) {\n            a[i] *= inv;\n        }\n    }\n    return a;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\
    template <typename T>\nvoid hadamard(int n, std::vector<T> &a) {\n    for (int\
    \ d = 0; d < n; ++d) {\n        for (int i = 0; i < (1 << n); ++i) {\n       \
    \     if ((i & (1 << d)) == 0) {\n                T x = a[i], y = a[i ^ (1 <<\
    \ d)];\n                a[i] = x + y;\n                a[i ^ (1 << d)] = x - y;\n\
    \            }\n        }\n    }\n}\ntemplate <typename T>\nstd::vector<T> bitwise_xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    assert(a.size() == b.size() && a.size() > 0);\n\
    \    int n = __builtin_ctz((unsigned)a.size());\n    assert((int)a.size() == (1\
    \ << n));\n    hadamard(n, a);\n    hadamard(n, b);\n    for (int i = 0; i < (1\
    \ << n); ++i) {\n        a[i] *= b[i];\n    }\n    hadamard(n, a);\n    if constexpr\
    \ (std::is_integral_v<T>) {\n        for (int i = 0; i < (1 << n); ++i) {\n  \
    \          a[i] /= 1 << n;\n        }\n    } else {\n        T inv = T(1 << n).inv();\n\
    \        for (int i = 0; i < (1 << n); ++i) {\n            a[i] *= inv;\n    \
    \    }\n    }\n    return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: bit/xor_convolution.hpp
  requiredBy: []
  timestamp: '2024-05-04 22:50:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - bit/test/bitwise_xor_convolution.test.cpp
documentation_of: bit/xor_convolution.hpp
layout: document
redirect_from:
- /library/bit/xor_convolution.hpp
- /library/bit/xor_convolution.hpp.html
title: bit/xor_convolution.hpp
---
