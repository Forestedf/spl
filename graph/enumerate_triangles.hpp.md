---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/enumerate_triangles.test.cpp
    title: graph/test/enumerate_triangles.test.cpp
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
    \ + sep[v + 1]};\n    }\n};\n#line 3 \"graph/enumerate_triangles.hpp\"\n#include\
    \ <algorithm>\n#include <numeric>\n// g: simple\ntemplate <typename T, typename\
    \ F>\nvoid enumerate_triangles(const Graph<T, false> &g, F f) {\n    int n = g.v();\n\
    \    Graph<int, true> h(n);\n    for (int v = 0; v < n; ++v) {\n        for (const\
    \ auto &e : g[v]) {\n            if (v < e.to) {\n                if (g[v].size()\
    \ < g[e.to].size()) {\n                    h.add_edge(v, e.to);\n            \
    \    } else {\n                    h.add_edge(e.to, v);\n                }\n \
    \           }\n        }\n    }\n    h.build();\n    std::vector<bool> mem(n,\
    \ false);\n    for (int v = 0; v < n; ++v) {\n        for (const auto &e : h[v])\
    \ {\n            mem[e.to] = true;\n        }\n        for (const auto &e : h[v])\
    \ {\n            for (const auto &e2 : h[e.to]) {\n                if (mem[e2.to])\
    \ {\n                    f(v, e.to, e2.to);\n                }\n            }\n\
    \        }\n        for (const auto &e : h[v]) {\n            mem[e.to] = false;\n\
    \        }\n    }\n}\n"
  code: "#pragma once\n#include \"graph.hpp\"\n#include <algorithm>\n#include <numeric>\n\
    // g: simple\ntemplate <typename T, typename F>\nvoid enumerate_triangles(const\
    \ Graph<T, false> &g, F f) {\n    int n = g.v();\n    Graph<int, true> h(n);\n\
    \    for (int v = 0; v < n; ++v) {\n        for (const auto &e : g[v]) {\n   \
    \         if (v < e.to) {\n                if (g[v].size() < g[e.to].size()) {\n\
    \                    h.add_edge(v, e.to);\n                } else {\n        \
    \            h.add_edge(e.to, v);\n                }\n            }\n        }\n\
    \    }\n    h.build();\n    std::vector<bool> mem(n, false);\n    for (int v =\
    \ 0; v < n; ++v) {\n        for (const auto &e : h[v]) {\n            mem[e.to]\
    \ = true;\n        }\n        for (const auto &e : h[v]) {\n            for (const\
    \ auto &e2 : h[e.to]) {\n                if (mem[e2.to]) {\n                 \
    \   f(v, e.to, e2.to);\n                }\n            }\n        }\n        for\
    \ (const auto &e : h[v]) {\n            mem[e.to] = false;\n        }\n    }\n\
    }\n"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/enumerate_triangles.hpp
  requiredBy: []
  timestamp: '2025-03-07 19:39:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/enumerate_triangles.test.cpp
documentation_of: graph/enumerate_triangles.hpp
layout: document
redirect_from:
- /library/graph/enumerate_triangles.hpp
- /library/graph/enumerate_triangles.hpp.html
title: graph/enumerate_triangles.hpp
---
