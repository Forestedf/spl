---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.hpp
    title: graph/biconnected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/block_cut_tree.hpp
    title: graph/block_cut_tree.hpp
  - icon: ':warning:'
    path: graph/complement_graph_connected_components.hpp
    title: graph/complement_graph_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/connected_components.hpp
    title: graph/connected_components.hpp
  - icon: ':warning:'
    path: graph/dense_dijkstra.hpp
    title: graph/dense_dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.hpp
    title: graph/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: graph/strongly_connected_components.hpp
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: graph/two_edge_connected_components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/ALDS1_11_D.test.cpp
    title: graph/test/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/biconnected_components.test.cpp
    title: graph/test/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/block_cut_tree.test.cpp
    title: graph/test/block_cut_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/jump_on_tree.test.cpp
    title: graph/test/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/lca.test.cpp
    title: graph/test/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/scc.test.cpp
    title: graph/test/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/shortest_path.test.cpp
    title: graph/test/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/two_edge_connected_components.test.cpp
    title: graph/test/two_edge_connected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/vertex_add_path_sum.test.cpp
    title: graph/test/vertex_add_path_sum.test.cpp
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
    \ + sep[v + 1]};\n    }\n};\n"
  code: "#pragma once\n#include <iostream>\n#include <cassert>\n#include <vector>\n\
    template <typename T>\nstruct Edge {\n    using W = T;\n    int from, to, id;\n\
    \    W weight;\n    Edge<T> rev() const {\n        return Edge<T>{to, from, id,\
    \ weight};\n    }\n};\ntemplate <typename T>\nvoid debug(const Edge<T> &e) {\n\
    \    std::cerr << e.from << \" -> \" << e.to << \" id = \" << e.id << std::cerr\
    \ << \" weight = \";\n    debug(e.weight);\n}\ntemplate <typename T = int, bool\
    \ DIR = false>\nclass Graph {\npublic:\n    using E = Edge<T>;\n    using W =\
    \ T;\n    static constexpr bool DIRECTED = DIR;\n    struct Adjacency {\n    \
    \    using Iter = typename std::vector<E>::iterator;\n        Iter be, en;\n \
    \       Iter begin() const { return be; }\n        Iter end() const { return en;\
    \ }\n        int size() const { return (int)std::distance(be, en); }\n       \
    \ E &operator[](int idx) const { return be[idx]; }\n    };\n    struct ConstAdjacency\
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
    \ + sep[v + 1]};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph.hpp
  requiredBy:
  - graph/dijkstra.hpp
  - graph/complement_graph_connected_components.hpp
  - graph/dense_dijkstra.hpp
  - graph/biconnected_components.hpp
  - graph/two_edge_connected_components.hpp
  - graph/strongly_connected_components.hpp
  - graph/heavy_light_decomposition.hpp
  - graph/connected_components.hpp
  - graph/block_cut_tree.hpp
  timestamp: '2024-02-03 17:22:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/lca.test.cpp
  - graph/test/shortest_path.test.cpp
  - graph/test/scc.test.cpp
  - graph/test/block_cut_tree.test.cpp
  - graph/test/biconnected_components.test.cpp
  - graph/test/ALDS1_11_D.test.cpp
  - graph/test/jump_on_tree.test.cpp
  - graph/test/two_edge_connected_components.test.cpp
  - graph/test/vertex_add_path_sum.test.cpp
documentation_of: graph/graph.hpp
layout: document
redirect_from:
- /library/graph/graph.hpp
- /library/graph/graph.hpp.html
title: graph/graph.hpp
---
