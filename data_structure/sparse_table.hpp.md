---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/sa_lcp.hpp
    title: string/sa_lcp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/staticrmq.test.cpp
    title: data_structure/test/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n#include <functional>\n\
    \ntemplate <typename T, typename F = std::less<T>>\nclass SparseTable {\n    std::vector<std::vector<T>>\
    \ table;\n    int s;\n    const F f;\n\n    int log2(int n) const {\n        return\
    \ 31 - __builtin_clz(n);\n    }\n    \n    T min2(const T &x, const T &y) const\
    \ {\n        if (f(x, y)) {\n            return x;\n        } else {\n       \
    \     return y;\n        }\n    }\n\npublic:\n    SparseTable(std::vector<T> arr,\
    \ const F &f = F()) : s((int) arr.size()), f(f) {\n        if (s == 0) {\n   \
    \         return;\n        }\n        int m = log2(s);\n        table.resize(m\
    \ + 1);\n        table[0] = std::move(arr);\n        for (int i = 1; i <= m; ++i)\
    \ {\n            int w = 1 << i;\n            table[i].resize(s - w + 1);\n  \
    \          for (int j = 0; j < (int) table[i].size(); ++j) {\n               \
    \ table[i][j] = min2(table[i - 1][j], table[i - 1][j + (w >> 1)]);\n         \
    \   }\n        }\n    }\n\n    int size() const {\n        return s;\n    }\n\n\
    \    // not empty\n    T min(int l, int r) const {\n        assert(l >= 0 && l\
    \ < r && r <= s);\n        int m = log2(r - l);\n        return min2(table[m][l],\
    \ table[m][r - (1 << m)]);\n    }\n};\n\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#include <functional>\n\ntemplate <typename T, typename F =\
    \ std::less<T>>\nclass SparseTable {\n    std::vector<std::vector<T>> table;\n\
    \    int s;\n    const F f;\n\n    int log2(int n) const {\n        return 31\
    \ - __builtin_clz(n);\n    }\n    \n    T min2(const T &x, const T &y) const {\n\
    \        if (f(x, y)) {\n            return x;\n        } else {\n           \
    \ return y;\n        }\n    }\n\npublic:\n    SparseTable(std::vector<T> arr,\
    \ const F &f = F()) : s((int) arr.size()), f(f) {\n        if (s == 0) {\n   \
    \         return;\n        }\n        int m = log2(s);\n        table.resize(m\
    \ + 1);\n        table[0] = std::move(arr);\n        for (int i = 1; i <= m; ++i)\
    \ {\n            int w = 1 << i;\n            table[i].resize(s - w + 1);\n  \
    \          for (int j = 0; j < (int) table[i].size(); ++j) {\n               \
    \ table[i][j] = min2(table[i - 1][j], table[i - 1][j + (w >> 1)]);\n         \
    \   }\n        }\n    }\n\n    int size() const {\n        return s;\n    }\n\n\
    \    // not empty\n    T min(int l, int r) const {\n        assert(l >= 0 && l\
    \ < r && r <= s);\n        int m = log2(r - l);\n        return min2(table[m][l],\
    \ table[m][r - (1 << m)]);\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy:
  - string/sa_lcp.hpp
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/staticrmq.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
redirect_from:
- /library/data_structure/sparse_table.hpp
- /library/data_structure/sparse_table.hpp.html
title: data_structure/sparse_table.hpp
---
