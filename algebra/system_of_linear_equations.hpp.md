---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algebra/test/system_of_linear_equations.test.cpp
    title: algebra/test/system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/system_of_linear_equations.hpp\"\n#include <optional>\n\
    #include <utility>\ntemplate <typename T>\nstd::optional<std::pair<std::vector<T>,\
    \ std::vector<std::vector<T>>>>\nlinear_equations(int n, int m, std::vector<std::vector<T>>\
    \ a, std::vector<T> b) {\n    assert((int)a.size() == n);\n    for (int i = 0;\
    \ i < n; ++i) {\n        assert((int)a[i].size() == m);\n    }\n    assert((int)b.size()\
    \ == n);\n    int li = 0;\n    std::vector<int> spe(m, -1);\n    for (int i =\
    \ 0; li < n && i < m; ++i) {\n        int row = -1;\n        for (int j = li;\
    \ j < n; ++j) {\n            if (a[j][i] != T()) {\n                row = j;\n\
    \                break;\n            }\n        }\n        if (row == -1) {\n\
    \            continue;\n        }\n        std::swap(a[row], a[li]);\n       \
    \ std::swap(b[row], b[li]);\n        T inv = a[li][i].inv();\n        for (int\
    \ j = 0; j < m; ++j) {\n            a[li][j] *= inv;\n        }\n        b[li]\
    \ *= inv;\n        for (int j = 0; j < n; ++j) {\n            if (j == li) {\n\
    \                continue;\n            }\n            T cf = a[j][i];\n     \
    \       for (int k = 0; k < m; ++k) {\n                a[j][k] -= a[li][k] * cf;\n\
    \            }\n            b[j] -= b[li] * cf;\n        }\n        spe[i] = li++;\n\
    \    }\n    for (int i = li; i < n; ++i) {\n        if (b[i] != T()) {\n     \
    \       return std::nullopt;\n        }\n    }\n    std::vector<T> ans(m, T());\n\
    \    std::vector<std::vector<T>> basis(m - li, std::vector<T>(m, T()));\n    int\
    \ ph = 0;\n    for (int i = 0; i < m; ++i) {\n        if (spe[i] != -1) {\n  \
    \          ans[i] = b[spe[i]];\n        } else {\n            basis[ph][i] = T(1);\n\
    \            for (int j = 0; j < i; ++j) {\n                if (int r = spe[j];\
    \ r != -1) {\n                    basis[ph][j] = -a[r][i];\n                }\n\
    \            }\n            ++ph;\n        }\n    }\n    return std::make_pair(ans,\
    \ basis);\n}\n"
  code: "#pragma once\n#include <optional>\n#include <utility>\ntemplate <typename\
    \ T>\nstd::optional<std::pair<std::vector<T>, std::vector<std::vector<T>>>>\n\
    linear_equations(int n, int m, std::vector<std::vector<T>> a, std::vector<T> b)\
    \ {\n    assert((int)a.size() == n);\n    for (int i = 0; i < n; ++i) {\n    \
    \    assert((int)a[i].size() == m);\n    }\n    assert((int)b.size() == n);\n\
    \    int li = 0;\n    std::vector<int> spe(m, -1);\n    for (int i = 0; li < n\
    \ && i < m; ++i) {\n        int row = -1;\n        for (int j = li; j < n; ++j)\
    \ {\n            if (a[j][i] != T()) {\n                row = j;\n           \
    \     break;\n            }\n        }\n        if (row == -1) {\n           \
    \ continue;\n        }\n        std::swap(a[row], a[li]);\n        std::swap(b[row],\
    \ b[li]);\n        T inv = a[li][i].inv();\n        for (int j = 0; j < m; ++j)\
    \ {\n            a[li][j] *= inv;\n        }\n        b[li] *= inv;\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (j == li) {\n                continue;\n\
    \            }\n            T cf = a[j][i];\n            for (int k = 0; k < m;\
    \ ++k) {\n                a[j][k] -= a[li][k] * cf;\n            }\n         \
    \   b[j] -= b[li] * cf;\n        }\n        spe[i] = li++;\n    }\n    for (int\
    \ i = li; i < n; ++i) {\n        if (b[i] != T()) {\n            return std::nullopt;\n\
    \        }\n    }\n    std::vector<T> ans(m, T());\n    std::vector<std::vector<T>>\
    \ basis(m - li, std::vector<T>(m, T()));\n    int ph = 0;\n    for (int i = 0;\
    \ i < m; ++i) {\n        if (spe[i] != -1) {\n            ans[i] = b[spe[i]];\n\
    \        } else {\n            basis[ph][i] = T(1);\n            for (int j =\
    \ 0; j < i; ++j) {\n                if (int r = spe[j]; r != -1) {\n         \
    \           basis[ph][j] = -a[r][i];\n                }\n            }\n     \
    \       ++ph;\n        }\n    }\n    return std::make_pair(ans, basis);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/system_of_linear_equations.hpp
  requiredBy: []
  timestamp: '2024-04-28 15:46:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algebra/test/system_of_linear_equations.test.cpp
documentation_of: algebra/system_of_linear_equations.hpp
layout: document
redirect_from:
- /library/algebra/system_of_linear_equations.hpp
- /library/algebra/system_of_linear_equations.hpp.html
title: algebra/system_of_linear_equations.hpp
---
