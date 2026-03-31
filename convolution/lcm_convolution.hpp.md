---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/lcm_convolution.stress.test.cpp
    title: convolution/test/lcm_convolution.stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/lcm_convolution.test.cpp
    title: convolution/test/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/lcm_convolution.hpp\"\n#include <cassert>\n\
    #include <vector>\n// length: max(a.size(), b.size())\n// ignore index 0\ntemplate\
    \ <typename T>\nstd::vector<T> lcm_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    if (a.size() <= 1 || b.size() <= 1) {\n        return std::vector<T>(std::max(a.size(),\
    \ b.size()), T(0));\n    }\n    if (a.size() > b.size()) {\n        a.swap(b);\n\
    \    }\n    int n = (int)b.size();\n    a.resize(n, T(0));\n    std::vector<int>\
    \ is_prime(n, 1);\n    for (int i = 2; i < n; ++i) {\n        if (!is_prime[i])\
    \ {\n            continue;\n        }\n        for (int j = 1, k = i; k < n; ++j,\
    \ k += i) {\n            a[k] += a[j];\n            b[k] += b[j];\n          \
    \  is_prime[k] = 0;\n        }\n        is_prime[i] = 1;\n    }\n    for (int\
    \ i = 1; i < n; ++i) {\n        b[i] *= a[i];\n    }\n    for (int i = 2; i <\
    \ n; ++i) {\n        if (!is_prime[i]) {\n            continue;\n        }\n \
    \       for (int j = (n - 1) / i, k = j * i; j >= 1; --j, k -= i) {\n        \
    \    b[k] -= b[j];\n        }\n    }\n    b[0] = T(0);\n    return b;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n// length: max(a.size(),\
    \ b.size())\n// ignore index 0\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    if (a.size() <= 1 || b.size() <= 1) {\n        return\
    \ std::vector<T>(std::max(a.size(), b.size()), T(0));\n    }\n    if (a.size()\
    \ > b.size()) {\n        a.swap(b);\n    }\n    int n = (int)b.size();\n    a.resize(n,\
    \ T(0));\n    std::vector<int> is_prime(n, 1);\n    for (int i = 2; i < n; ++i)\
    \ {\n        if (!is_prime[i]) {\n            continue;\n        }\n        for\
    \ (int j = 1, k = i; k < n; ++j, k += i) {\n            a[k] += a[j];\n      \
    \      b[k] += b[j];\n            is_prime[k] = 0;\n        }\n        is_prime[i]\
    \ = 1;\n    }\n    for (int i = 1; i < n; ++i) {\n        b[i] *= a[i];\n    }\n\
    \    for (int i = 2; i < n; ++i) {\n        if (!is_prime[i]) {\n            continue;\n\
    \        }\n        for (int j = (n - 1) / i, k = j * i; j >= 1; --j, k -= i)\
    \ {\n            b[k] -= b[j];\n        }\n    }\n    b[0] = T(0);\n    return\
    \ b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2025-08-14 15:17:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/lcm_convolution.test.cpp
  - convolution/test/lcm_convolution.stress.test.cpp
documentation_of: convolution/lcm_convolution.hpp
layout: document
redirect_from:
- /library/convolution/lcm_convolution.hpp
- /library/convolution/lcm_convolution.hpp.html
title: convolution/lcm_convolution.hpp
---
