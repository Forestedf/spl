---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/scc.test.cpp
    title: graph/test/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.hpp\"\n#include <iostream>\n#include <cassert>\n\
    #include <vector>\ntemplate <typename T>\nstruct Edge {\n    using W = T;\n  \
    \  int from, to, id;\n    W weight;\n    Edge<T> rev() const {\n        return\
    \ Edge<T>{to, from, id, weight};\n    }\n};\ntemplate <typename T>\nvoid debug(const\
    \ Edge<T> &e) {\n    std::cerr << e.from << \" -> \" << e.to << \" id = \" <<\
    \ e.id << std::cerr << \" weight = \";\n    debug(e.weight);\n}\ntemplate <typename\
    \ T = int, bool DIR = false>\nclass Graph {\npublic:\n    using E = Edge<T>;\n\
    \    using W = T;\n    static constexpr bool DIRECTED = DIR;\n    struct Adjacency\
    \ {\n        using Iter = typename std::vector<E>::iterator;\n        Iter be,\
    \ en;\n        Iter begin() const { return be; }\n        Iter end() const { return\
    \ en; }\n        int size() const { return (int)std::distance(be, en); }\n   \
    \     E &operator[](int idx) const { return be[idx]; }\n    };\n    struct ConstAdjacency\
    \ {\n        using Iter = typename std::vector<E>::const_iterator;\n        Iter\
    \ be, en;\n        Iter begin() const { return be; }\n        Iter end() const\
    \ { return en; }\n        int size() const { return (int)std::distance(be, en);\
    \ }\n        const E &operator[](int idx) const { return be[idx]; }\n    };\n\n\
    private:\n    int n, m;\n    std::vector<E> edges, csr;\n    std::vector<int>\
    \ sep;\n    bool built;\n\npublic:\n    Graph(int n) : n(n), m(0), built(false)\
    \ {}\n    int v() const { return n; }\n    int e() const { return m; }\n    int\
    \ add_vertex() {\n        return n++;\n    }\n    void add_edge(int from, int\
    \ to, W weight = 1) {\n        assert(0 <= from && from < n && 0 <= to && to <\
    \ n);\n        edges.emplace_back(E{from, to, m++, weight});\n    }\n    void\
    \ build() {\n        sep.assign(n + 1, 0);\n        csr.resize(DIRECTED ? m :\
    \ 2 * m);\n        for (const E &e : edges) {\n            ++sep[e.from + 1];\n\
    \            if (!DIRECTED) {\n                ++sep[e.to + 1];\n            }\n\
    \        }\n        for (int i = 0; i < n; ++i) {\n            sep[i + 1] += sep[i];\n\
    \        }\n        std::vector<int> c = sep;\n        for (const E &e : edges)\
    \ {\n            csr[c[e.from]++] = e;\n            if (!DIRECTED) {\n       \
    \         csr[c[e.to]++] = e.rev();\n            }\n        }\n        built =\
    \ true;\n    }\n    Adjacency operator[](int v) {\n        assert(built && 0 <=\
    \ v && v < n);\n        return Adjacency{csr.begin() + sep[v], csr.begin() + sep[v\
    \ + 1]};\n    }\n    ConstAdjacency operator[](int v) const {\n        assert(built\
    \ && 0 <= v && v < n);\n        return ConstAdjacency{csr.begin() + sep[v], csr.begin()\
    \ + sep[v + 1]};\n    }\n};\n#line 3 \"graph/strongly_connected_components.hpp\"\
    \ntemplate <typename T>\nstd::vector<int> strongly_connected_components(const\
    \ Graph<T, true> &g) {\n    std::vector<int> comp(g.v(), -1);\n    int t = 0,\
    \ cc = 0;\n    std::vector<int> vs, ord(g.v(), -1), low(g.v(), -1);\n    auto\
    \ dfs = [&](auto dfs, int v) -> void {\n        vs.push_back(v);\n        ord[v]\
    \ = low[v] = t++;\n        for (const Edge<T> &e : g[v]) {\n            if (comp[e.to]\
    \ != -1) {\n                continue;\n            }\n            if (ord[e.to]\
    \ == -1) {\n                dfs(dfs, e.to);\n            }\n            if (low[e.to]\
    \ < low[v]) {\n                low[v] = low[e.to];\n            }\n        }\n\
    \        if (low[v] == ord[v]) {\n            while (comp[v] == -1) {\n      \
    \          int u = vs.back();\n                vs.pop_back();\n              \
    \  comp[u] = cc;\n            }\n            ++cc;\n        }\n    };\n    for\
    \ (int i = 0; i < g.v(); ++i) {\n        if (ord[i] == -1) {\n            dfs(dfs,\
    \ i);\n        }\n    }\n    for (int i = 0; i < g.v(); ++i) {\n        comp[i]\
    \ = cc - 1 - comp[i];\n    }\n    return comp;\n}\n"
  code: "#pragma once\n#include \"graph.hpp\"\ntemplate <typename T>\nstd::vector<int>\
    \ strongly_connected_components(const Graph<T, true> &g) {\n    std::vector<int>\
    \ comp(g.v(), -1);\n    int t = 0, cc = 0;\n    std::vector<int> vs, ord(g.v(),\
    \ -1), low(g.v(), -1);\n    auto dfs = [&](auto dfs, int v) -> void {\n      \
    \  vs.push_back(v);\n        ord[v] = low[v] = t++;\n        for (const Edge<T>\
    \ &e : g[v]) {\n            if (comp[e.to] != -1) {\n                continue;\n\
    \            }\n            if (ord[e.to] == -1) {\n                dfs(dfs, e.to);\n\
    \            }\n            if (low[e.to] < low[v]) {\n                low[v]\
    \ = low[e.to];\n            }\n        }\n        if (low[v] == ord[v]) {\n  \
    \          while (comp[v] == -1) {\n                int u = vs.back();\n     \
    \           vs.pop_back();\n                comp[u] = cc;\n            }\n   \
    \         ++cc;\n        }\n    };\n    for (int i = 0; i < g.v(); ++i) {\n  \
    \      if (ord[i] == -1) {\n            dfs(dfs, i);\n        }\n    }\n    for\
    \ (int i = 0; i < g.v(); ++i) {\n        comp[i] = cc - 1 - comp[i];\n    }\n\
    \    return comp;\n}\n"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/scc.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.hpp
- /library/graph/strongly_connected_components.hpp.html
title: graph/strongly_connected_components.hpp
---
