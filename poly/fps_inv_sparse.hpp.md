---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: poly/test/inv_of_formal_power_series_sparse.test.cpp
    title: poly/test/inv_of_formal_power_series_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/fps_inv_sparse.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n// O(n * (# of nonzero))\ntemplate <typename T>\n\
    std::vector<T> fps_inv_sparse(const std::vector<T> &f) {\n    assert(!f.empty()\
    \ && f[0] != T(0));\n    int n = (int)f.size();\n    std::vector<std::pair<int,\
    \ T>> nonzero;\n    for (int i = 1; i < n; ++i) {\n        if (f[i] != T()) {\n\
    \            nonzero.emplace_back(i, f[i]);\n        }\n    }\n    std::vector<T>\
    \ g(n);\n    T inv_f0 = T(1) / f[0];\n    g[0] = inv_f0;\n    for (int i = 1;\
    \ i < n; ++i) {\n        for (auto [j, val] : nonzero) {\n            if (j >\
    \ i) {\n                break;\n            }\n            g[i] -= g[i - j] *\
    \ val;\n        }\n        g[i] *= inv_f0;\n    }\n    return g;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    // O(n * (# of nonzero))\ntemplate <typename T>\nstd::vector<T> fps_inv_sparse(const\
    \ std::vector<T> &f) {\n    assert(!f.empty() && f[0] != T(0));\n    int n = (int)f.size();\n\
    \    std::vector<std::pair<int, T>> nonzero;\n    for (int i = 1; i < n; ++i)\
    \ {\n        if (f[i] != T()) {\n            nonzero.emplace_back(i, f[i]);\n\
    \        }\n    }\n    std::vector<T> g(n);\n    T inv_f0 = T(1) / f[0];\n   \
    \ g[0] = inv_f0;\n    for (int i = 1; i < n; ++i) {\n        for (auto [j, val]\
    \ : nonzero) {\n            if (j > i) {\n                break;\n           \
    \ }\n            g[i] -= g[i - j] * val;\n        }\n        g[i] *= inv_f0;\n\
    \    }\n    return g;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_inv_sparse.hpp
  requiredBy: []
  timestamp: '2024-04-29 14:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - poly/test/inv_of_formal_power_series_sparse.test.cpp
documentation_of: poly/fps_inv_sparse.hpp
layout: document
redirect_from:
- /library/poly/fps_inv_sparse.hpp
- /library/poly/fps_inv_sparse.hpp.html
title: poly/fps_inv_sparse.hpp
---
