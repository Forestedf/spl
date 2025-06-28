---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: poly/test/find_linear_recurrence.test.cpp
    title: poly/test/find_linear_recurrence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/find_linear_recurrence.hpp\"\n#include <vector>\n//\
    \ trailing zeros \u304C\u5B58\u5728\u3059\u308B\u3053\u3068\u304C\u3042\u308B\n\
    template <typename T>\nstd::vector<T> find_linear_recurrence(const std::vector<T>\
    \ &s) {\n    int n = (int)s.size(), d = 0, e = 0, m = 0;\n    std::vector<T> b(n\
    \ + 1, T(0)), c(n + 1, T(0));\n    b[0] = T(1);\n    c[0] = T(1);\n    T v(1);\n\
    \    for (int i = 0; i < n; ++i) {\n        ++m;\n        T delta = 0;\n     \
    \   for (int j = 0; j <= d; ++j) {\n            delta += c[j] * s[i - j];\n  \
    \      }\n        if (delta != T(0)) {\n            T r = delta * v;\n       \
    \     if (2 * d <= i) {\n                std::vector<T> cc = c;\n            \
    \    for (int j = m; j <= m + e; ++j) {\n                    c[j] -= r * b[j -\
    \ m];\n                }\n                b.swap(cc);\n                e = d;\n\
    \                d = i + 1 - d;\n                m = 0;\n                v = T(1)\
    \ / delta;\n            } else {\n                for (int j = m; j <= m + e;\
    \ ++j) {\n                    c[j] -= r * b[j - m];\n                }\n     \
    \       }\n        }\n    }\n    c.resize(d + 1);\n    return c;\n}\n"
  code: "#pragma once\n#include <vector>\n// trailing zeros \u304C\u5B58\u5728\u3059\
    \u308B\u3053\u3068\u304C\u3042\u308B\ntemplate <typename T>\nstd::vector<T> find_linear_recurrence(const\
    \ std::vector<T> &s) {\n    int n = (int)s.size(), d = 0, e = 0, m = 0;\n    std::vector<T>\
    \ b(n + 1, T(0)), c(n + 1, T(0));\n    b[0] = T(1);\n    c[0] = T(1);\n    T v(1);\n\
    \    for (int i = 0; i < n; ++i) {\n        ++m;\n        T delta = 0;\n     \
    \   for (int j = 0; j <= d; ++j) {\n            delta += c[j] * s[i - j];\n  \
    \      }\n        if (delta != T(0)) {\n            T r = delta * v;\n       \
    \     if (2 * d <= i) {\n                std::vector<T> cc = c;\n            \
    \    for (int j = m; j <= m + e; ++j) {\n                    c[j] -= r * b[j -\
    \ m];\n                }\n                b.swap(cc);\n                e = d;\n\
    \                d = i + 1 - d;\n                m = 0;\n                v = T(1)\
    \ / delta;\n            } else {\n                for (int j = m; j <= m + e;\
    \ ++j) {\n                    c[j] -= r * b[j - m];\n                }\n     \
    \       }\n        }\n    }\n    c.resize(d + 1);\n    return c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/find_linear_recurrence.hpp
  requiredBy: []
  timestamp: '2025-03-07 18:08:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - poly/test/find_linear_recurrence.test.cpp
documentation_of: poly/find_linear_recurrence.hpp
layout: document
redirect_from:
- /library/poly/find_linear_recurrence.hpp
- /library/poly/find_linear_recurrence.hpp.html
title: poly/find_linear_recurrence.hpp
---
