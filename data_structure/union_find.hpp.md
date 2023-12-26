---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/unionfind.test.cpp
    title: data_structure/test/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/union_find.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nclass UnionFind {\n    std::vector<int>\
    \ par;\n\n    int _root(int v) {\n        if (par[v] < 0) {\n            return\
    \ v;\n        } else {\n            return par[v] = _root(par[v]);\n        }\n\
    \    }\n\npublic:\n    UnionFind(int n) : par(n, -1) {}\n\n    int root(int v)\
    \ {\n        assert(v >= 0 && v < (int)par.size());\n        return _root(v);\n\
    \    }\n\n    int size(int v) {\n        assert(v >= 0 && v < (int)par.size());\n\
    \        return -par[_root(v)];\n    }\n\n    bool unite(int u, int v) {\n   \
    \     assert(u >= 0 && u < (int)par.size() && v >= 0 && v < (int)par.size());\n\
    \        u = _root(u);\n        v = _root(v);\n        if (u == v) {\n       \
    \     return false;\n        }\n        if (par[u] < par[v]) {\n            std::swap(u,\
    \ v);\n        }\n        par[v] += par[u];\n        par[u] = v;\n        return\
    \ true;\n    }\n\n    bool same(int u, int v) {\n        assert(u >= 0 && u <\
    \ (int)par.size() && v >= 0 && v < (int)par.size());\n        return _root(u)\
    \ == _root(v);\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nclass UnionFind {\n    std::vector<int> par;\n\n    int _root(int v) {\n   \
    \     if (par[v] < 0) {\n            return v;\n        } else {\n           \
    \ return par[v] = _root(par[v]);\n        }\n    }\n\npublic:\n    UnionFind(int\
    \ n) : par(n, -1) {}\n\n    int root(int v) {\n        assert(v >= 0 && v < (int)par.size());\n\
    \        return _root(v);\n    }\n\n    int size(int v) {\n        assert(v >=\
    \ 0 && v < (int)par.size());\n        return -par[_root(v)];\n    }\n\n    bool\
    \ unite(int u, int v) {\n        assert(u >= 0 && u < (int)par.size() && v >=\
    \ 0 && v < (int)par.size());\n        u = _root(u);\n        v = _root(v);\n \
    \       if (u == v) {\n            return false;\n        }\n        if (par[u]\
    \ < par[v]) {\n            std::swap(u, v);\n        }\n        par[v] += par[u];\n\
    \        par[u] = v;\n        return true;\n    }\n\n    bool same(int u, int\
    \ v) {\n        assert(u >= 0 && u < (int)par.size() && v >= 0 && v < (int)par.size());\n\
    \        return _root(u) == _root(v);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/unionfind.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
redirect_from:
- /library/data_structure/union_find.hpp
- /library/data_structure/union_find.hpp.html
title: data_structure/union_find.hpp
---
