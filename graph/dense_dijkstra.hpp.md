---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dense_dijkstra.hpp\"\n#include <limits>\n#include\
    \ <queue>\n#line 2 \"graph/graph.hpp\"\n#include <iostream>\n#include <cassert>\n\
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
    \ + sep[v + 1]};\n    }\n};\n#line 5 \"graph/dense_dijkstra.hpp\"\n// (dist, from)\n\
    template <typename T, bool DIR>\nstd::pair<std::vector<T>, std::vector<int>> dense_dijkstra(\n\
    \    const Graph<T, DIR> &g, int s, T inf = std::numeric_limits<T>::max()) {\n\
    \    assert(0 <= s && s < g.v());\n    std::vector<T> dist(g.v(), inf);\n    std::vector<int>\
    \ par(g.v(), -1);\n    std::vector<int> used(g.v(), 0);\n    dist[s] = 0;\n  \
    \  while (true) {\n        T d = inf;\n        int v = -1;\n        for (int i\
    \ = 0; i < g.v(); ++i) {\n            if (!used[i] && dist[i] < d) {\n       \
    \         d = dist[i];\n                v = i;\n            }\n        } \n  \
    \      if (v == -1) {\n            break;\n        }\n        used[v] = 1;\n \
    \       for (const Edge<T> &e : g[v]) {\n            if (d + e.weight < dist[e.to])\
    \ {\n                dist[e.to] = d + e.weight;\n                par[e.to] = v;\n\
    \            }\n        }\n    }\n    return std::make_pair(dist, par);\n}\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include \"graph.hpp\"\
    \n// (dist, from)\ntemplate <typename T, bool DIR>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> dense_dijkstra(\n    const Graph<T, DIR> &g, int s, T inf\
    \ = std::numeric_limits<T>::max()) {\n    assert(0 <= s && s < g.v());\n    std::vector<T>\
    \ dist(g.v(), inf);\n    std::vector<int> par(g.v(), -1);\n    std::vector<int>\
    \ used(g.v(), 0);\n    dist[s] = 0;\n    while (true) {\n        T d = inf;\n\
    \        int v = -1;\n        for (int i = 0; i < g.v(); ++i) {\n            if\
    \ (!used[i] && dist[i] < d) {\n                d = dist[i];\n                v\
    \ = i;\n            }\n        } \n        if (v == -1) {\n            break;\n\
    \        }\n        used[v] = 1;\n        for (const Edge<T> &e : g[v]) {\n  \
    \          if (d + e.weight < dist[e.to]) {\n                dist[e.to] = d +\
    \ e.weight;\n                par[e.to] = v;\n            }\n        }\n    }\n\
    \    return std::make_pair(dist, par);\n}\n"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/dense_dijkstra.hpp
  requiredBy: []
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dense_dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dense_dijkstra.hpp
- /library/graph/dense_dijkstra.hpp.html
title: graph/dense_dijkstra.hpp
---
