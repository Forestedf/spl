---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/frequency_table_of_tree_distance.hpp
    title: graph/frequency_table_of_tree_distance.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: graph/test/frequency_table_of_tree_distance.test.cpp
    title: graph/test/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ + sep[v + 1]};\n    }\n};\n#line 3 \"graph/centroid_decomposition.hpp\"\nclass\
    \ CentroidDecomposition {\n    Graph<int, true> to;\n    std::vector<bool> used;\n\
    \    std::vector<int> size;\n    int first;\n    \n    template <typename T>\n\
    \    void dfs(const Graph<T> &g, int v, int p) {\n        size[v] = 1;\n     \
    \   for (const Edge<T> &e : g[v]) {\n            if (e.to != p && !used[e.to])\
    \ {\n                dfs(g, e.to, v);\n                size[v] += size[e.to];\n\
    \            }\n        }\n    }\n    \n    template <typename T>\n    int find_centroid(const\
    \ Graph<T> &g, int v) {\n        dfs(g, v, -1);\n        int sz = size[v];\n \
    \       int p = -1;\n        while (true) {\n            bool ok = true;\n   \
    \         for (const Edge<T> &e : g[v]) {\n                if (e.to == p || used[e.to])\
    \ {\n                    continue;\n                }\n                if (size[e.to]\
    \ > sz / 2) {\n                    p = v;\n                    v = e.to;\n   \
    \                 ok = false;\n                    break;\n                }\n\
    \            }\n            if (ok) {\n                break;\n            }\n\
    \        }\n        return v;\n    }\n    \n    template <typename T>\n    int\
    \ decompose(const Graph<T> &g, int v) {\n        int cent = find_centroid(g, v);\n\
    \        used[cent] = true;\n        for (const Edge<T> &e : g[cent]) {\n    \
    \        if (!used[e.to]) {\n                to.add_edge(cent, decompose(g, e.to));\n\
    \            }\n        }\n        return cent;\n    }\n    \npublic:\n    template\
    \ <typename T>\n    CentroidDecomposition(const Graph<T> &g) : to(g.v()), used(g.v(),\
    \ false), size(g.v(), 0) {\n        first = decompose(g, 0);\n        to.build();\n\
    \    }\n    \n    int first_centroid() const {\n        return first;\n    }\n\
    \    typename Graph<int, true>::ConstAdjacency operator[](int v) const {\n   \
    \     return to[v];\n    }\n    const Graph<int, true> &get_tree() const {\n \
    \       return to;\n    }\n};\n"
  code: "#pragma once\n#include \"graph.hpp\"\nclass CentroidDecomposition {\n   \
    \ Graph<int, true> to;\n    std::vector<bool> used;\n    std::vector<int> size;\n\
    \    int first;\n    \n    template <typename T>\n    void dfs(const Graph<T>\
    \ &g, int v, int p) {\n        size[v] = 1;\n        for (const Edge<T> &e : g[v])\
    \ {\n            if (e.to != p && !used[e.to]) {\n                dfs(g, e.to,\
    \ v);\n                size[v] += size[e.to];\n            }\n        }\n    }\n\
    \    \n    template <typename T>\n    int find_centroid(const Graph<T> &g, int\
    \ v) {\n        dfs(g, v, -1);\n        int sz = size[v];\n        int p = -1;\n\
    \        while (true) {\n            bool ok = true;\n            for (const Edge<T>\
    \ &e : g[v]) {\n                if (e.to == p || used[e.to]) {\n             \
    \       continue;\n                }\n                if (size[e.to] > sz / 2)\
    \ {\n                    p = v;\n                    v = e.to;\n             \
    \       ok = false;\n                    break;\n                }\n         \
    \   }\n            if (ok) {\n                break;\n            }\n        }\n\
    \        return v;\n    }\n    \n    template <typename T>\n    int decompose(const\
    \ Graph<T> &g, int v) {\n        int cent = find_centroid(g, v);\n        used[cent]\
    \ = true;\n        for (const Edge<T> &e : g[cent]) {\n            if (!used[e.to])\
    \ {\n                to.add_edge(cent, decompose(g, e.to));\n            }\n \
    \       }\n        return cent;\n    }\n    \npublic:\n    template <typename\
    \ T>\n    CentroidDecomposition(const Graph<T> &g) : to(g.v()), used(g.v(), false),\
    \ size(g.v(), 0) {\n        first = decompose(g, 0);\n        to.build();\n  \
    \  }\n    \n    int first_centroid() const {\n        return first;\n    }\n \
    \   typename Graph<int, true>::ConstAdjacency operator[](int v) const {\n    \
    \    return to[v];\n    }\n    const Graph<int, true> &get_tree() const {\n  \
    \      return to;\n    }\n};\n"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/centroid_decomposition.hpp
  requiredBy:
  - graph/frequency_table_of_tree_distance.hpp
  timestamp: '2025-12-31 19:12:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - graph/test/frequency_table_of_tree_distance.test.cpp
documentation_of: graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph/centroid_decomposition.hpp
- /library/graph/centroid_decomposition.hpp.html
title: graph/centroid_decomposition.hpp
---
