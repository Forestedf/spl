---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/two_edge_connected_components.test.cpp
    title: graph/test/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graph.hpp\"\n#include <iostream>\n#include <cassert>\n\
    #include <vector>\ntemplate <typename T>\nstruct Edge {\n    using W = T;\n  \
    \  int from, to, id;\n    W weight;\n};\ntemplate <typename T>\nvoid debug(const\
    \ Edge<T> &e) {\n    std::cerr << e.from << \" -> \" << e.to << \" id = \" <<\
    \ e.id << \" weight = \";\n    debug(e.weight);\n}\ntemplate <typename T = int,\
    \ bool DIR = false>\nclass Graph {\npublic:\n    using E = Edge<T>;\n    using\
    \ W = T;\n    static constexpr bool DIRECTED = DIR;\n    struct Adjacency {\n\
    \        using Iter = typename std::vector<E>::iterator;\n        Iter be, en;\n\
    \        Iter begin() const { return be; }\n        Iter end() const { return\
    \ en; }\n        int size() const { return (int)std::distance(be, en); }\n   \
    \     E &operator[](int idx) const { return be[idx]; }\n    };\n    struct ConstAdjacency\
    \ {\n        using Iter = typename std::vector<E>::const_iterator;\n        Iter\
    \ be, en;\n        Iter begin() const { return be; }\n        Iter end() const\
    \ { return en; }\n        int size() const { return (int)std::distance(be, en);\
    \ }\n        const E &operator[](int idx) const { return be[idx]; }\n    };\n\n\
    private:\n    int n, m;\n    std::vector<E> edges, csr;\n    std::vector<int>\
    \ sep;\n    bool built;\n\npublic:\n    Graph(int n) : n(n), m(0), built(false)\
    \ {}\n    int v() const { return n; }\n    int e() const { return m; }\n    void\
    \ add_edge(int from, int to, W weight = 1) {\n        assert(0 <= from && from\
    \ < n && 0 <= to && to < n);\n        edges.emplace_back(E{from, to, m++, weight});\n\
    \    }\n    void add_edge(E e) {\n        assert(0 <= e.from && e.from < n &&\
    \ 0 <= e.to && e.to < n);\n        edges.emplace_back(e);\n        ++m;\n    }\n\
    \    void build() {\n        sep.assign(n + 1, 0);\n        csr.resize(DIRECTED\
    \ ? m : 2 * m);\n        for (const E &e : edges) {\n            ++sep[e.from\
    \ + 1];\n            if (!DIRECTED) {\n                ++sep[e.to + 1];\n    \
    \        }\n        }\n        for (int i = 0; i < n; ++i) {\n            sep[i\
    \ + 1] += sep[i];\n        }\n        std::vector<int> c = sep;\n        for (const\
    \ E &e : edges) {\n            csr[c[e.from]++] = e;\n            if (!DIRECTED)\
    \ {\n                csr[c[e.to]++] = E{e.to, e.from, e.id, e.weight};\n     \
    \       }\n        }\n        built = true;\n    }\n    Adjacency operator[](int\
    \ v) {\n        assert(built && 0 <= v && v < n);\n        return Adjacency{csr.begin()\
    \ + sep[v], csr.begin() + sep[v + 1]};\n    }\n    ConstAdjacency operator[](int\
    \ v) const {\n        assert(built && 0 <= v && v < n);\n        return ConstAdjacency{csr.begin()\
    \ + sep[v], csr.begin() + sep[v + 1]};\n    }\n};\n#line 3 \"graph/two_edge_connected_components.hpp\"\
    \ntemplate <typename T>\nstd::vector<int> two_edge_connected_components(const\
    \ Graph<T> &g) {\n    std::vector<int> comp(g.v(), -1);\n    int cc = 0;\n   \
    \ std::vector<int> ord(g.v(), -1), low(g.v(), -1), vs;\n    int t = 0;\n    auto\
    \ dfs = [&](auto dfs, int v, int p) -> void {\n        ord[v] = low[v] = t++;\n\
    \        vs.push_back(v);\n        bool pf = false;\n        for (const Edge<T>\
    \ &e : g[v]) {\n            if (ord[e.to] == -1) {\n                dfs(dfs, e.to,\
    \ v);\n                if (low[e.to] < low[v]) {\n                    low[v] =\
    \ low[e.to];\n                }\n            } else if (e.to == p && !pf) {\n\
    \                pf = true;\n            } else {\n                if (ord[e.to]\
    \ < low[v]) {\n                    low[v] = ord[e.to];\n                }\n  \
    \          }\n        }\n        if (ord[v] == low[v]) {\n            while (comp[v]\
    \ == -1) {\n                comp[vs.back()] = cc;\n                vs.pop_back();\n\
    \            }\n            ++cc;\n        }\n    };\n    for (int i = 0; i <\
    \ g.v(); ++i) {\n        if (comp[i] == -1) {\n            dfs(dfs, i, -1);\n\
    \        }\n    }\n    return comp;\n}\n"
  code: "#pragma once\n#include \"graph.hpp\"\ntemplate <typename T>\nstd::vector<int>\
    \ two_edge_connected_components(const Graph<T> &g) {\n    std::vector<int> comp(g.v(),\
    \ -1);\n    int cc = 0;\n    std::vector<int> ord(g.v(), -1), low(g.v(), -1),\
    \ vs;\n    int t = 0;\n    auto dfs = [&](auto dfs, int v, int p) -> void {\n\
    \        ord[v] = low[v] = t++;\n        vs.push_back(v);\n        bool pf = false;\n\
    \        for (const Edge<T> &e : g[v]) {\n            if (ord[e.to] == -1) {\n\
    \                dfs(dfs, e.to, v);\n                if (low[e.to] < low[v]) {\n\
    \                    low[v] = low[e.to];\n                }\n            } else\
    \ if (e.to == p && !pf) {\n                pf = true;\n            } else {\n\
    \                if (ord[e.to] < low[v]) {\n                    low[v] = ord[e.to];\n\
    \                }\n            }\n        }\n        if (ord[v] == low[v]) {\n\
    \            while (comp[v] == -1) {\n                comp[vs.back()] = cc;\n\
    \                vs.pop_back();\n            }\n            ++cc;\n        }\n\
    \    };\n    for (int i = 0; i < g.v(); ++i) {\n        if (comp[i] == -1) {\n\
    \            dfs(dfs, i, -1);\n        }\n    }\n    return comp;\n}"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.hpp
  requiredBy: []
  timestamp: '2024-01-14 18:28:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_connected_components.hpp
layout: document
redirect_from:
- /library/graph/two_edge_connected_components.hpp
- /library/graph/two_edge_connected_components.hpp.html
title: graph/two_edge_connected_components.hpp
---
