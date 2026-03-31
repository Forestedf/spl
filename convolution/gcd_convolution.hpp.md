---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: convolution/test/gcd_convolution.stress.test.cpp
    title: convolution/test/gcd_convolution.stress.test.cpp
  - icon: ':heavy_check_mark:'
    path: convolution/test/gcd_convolution.test.cpp
    title: convolution/test/gcd_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/gcd_convolution.hpp\"\n#include <cassert>\n\
    #include <vector>\n// length: max(a.size(), b.size())\ntemplate <typename T>\n\
    std::vector<T> gcd_convolution(std::vector<T> a, std::vector<T> b) {\n    if (a.empty()\
    \ || b.empty()) {\n        return std::vector<T>(std::max(a.size(), b.size()),\
    \ 0);\n    }\n    if (a.size() > b.size()) {\n        a.swap(b);\n    }\n    int\
    \ m = (int)a.size();\n    int n = (int)b.size();\n    std::vector<T> c(n, T());\n\
    \    for (int i = 0; i < m; ++i) {\n        c[i] += a[i] * b[0];\n    }\n    for\
    \ (int i = 1; i < n; ++i) {\n        c[i] += a[0] * b[i];\n    }\n    std::vector<int>\
    \ is_prime(n, 1);\n    for (int i = 2; i < n; ++i) {\n        if (!is_prime[i])\
    \ {\n            continue;\n        }\n        // k * i < n\n        // k < n\
    \ / i\n        for (int j = (n - 1) / i, k = j * i; j >= 1; --j, k -= i) {\n \
    \           is_prime[k] = 0;\n            b[j] += b[k];\n        }\n        for\
    \ (int j = (m - 1) / i, k = j * i; j >= 1; --j, k -= i) {\n            a[j] +=\
    \ a[k];\n        }\n        is_prime[i] = 1;\n    }\n    for (int i = 1; i < m;\
    \ ++i) {\n        b[i] *= a[i];\n    }\n    for (int i = m; i < n; ++i) {\n  \
    \      b[i] = T();\n    }\n    for (int i = 2; i < m; ++i) {\n        if (!is_prime[i])\
    \ {\n            continue;\n        }\n        for (int j = 1, k = i; k < m; ++j,\
    \ k += i) {\n            b[j] -= b[k];\n        }\n    }\n    for (int i = 1;\
    \ i < m; ++i) {\n        c[i] += b[i];\n    }\n    return c;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n// length: max(a.size(),\
    \ b.size())\ntemplate <typename T>\nstd::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    if (a.empty() || b.empty()) {\n        return std::vector<T>(std::max(a.size(),\
    \ b.size()), 0);\n    }\n    if (a.size() > b.size()) {\n        a.swap(b);\n\
    \    }\n    int m = (int)a.size();\n    int n = (int)b.size();\n    std::vector<T>\
    \ c(n, T());\n    for (int i = 0; i < m; ++i) {\n        c[i] += a[i] * b[0];\n\
    \    }\n    for (int i = 1; i < n; ++i) {\n        c[i] += a[0] * b[i];\n    }\n\
    \    std::vector<int> is_prime(n, 1);\n    for (int i = 2; i < n; ++i) {\n   \
    \     if (!is_prime[i]) {\n            continue;\n        }\n        // k * i\
    \ < n\n        // k < n / i\n        for (int j = (n - 1) / i, k = j * i; j >=\
    \ 1; --j, k -= i) {\n            is_prime[k] = 0;\n            b[j] += b[k];\n\
    \        }\n        for (int j = (m - 1) / i, k = j * i; j >= 1; --j, k -= i)\
    \ {\n            a[j] += a[k];\n        }\n        is_prime[i] = 1;\n    }\n \
    \   for (int i = 1; i < m; ++i) {\n        b[i] *= a[i];\n    }\n    for (int\
    \ i = m; i < n; ++i) {\n        b[i] = T();\n    }\n    for (int i = 2; i < m;\
    \ ++i) {\n        if (!is_prime[i]) {\n            continue;\n        }\n    \
    \    for (int j = 1, k = i; k < m; ++j, k += i) {\n            b[j] -= b[k];\n\
    \        }\n    }\n    for (int i = 1; i < m; ++i) {\n        c[i] += b[i];\n\
    \    }\n    return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2025-08-14 14:47:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - convolution/test/gcd_convolution.test.cpp
  - convolution/test/gcd_convolution.stress.test.cpp
documentation_of: convolution/gcd_convolution.hpp
layout: document
redirect_from:
- /library/convolution/gcd_convolution.hpp
- /library/convolution/gcd_convolution.hpp.html
title: convolution/gcd_convolution.hpp
---
