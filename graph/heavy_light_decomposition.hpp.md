---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/jump_on_tree.test.cpp
    title: graph/test/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/lca.test.cpp
    title: graph/test/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/heavy_light_decomposition.hpp\"\n#include <algorithm>\n\
    #include <utility>\n#line 2 \"graph/graph.hpp\"\n#include <iostream>\n#include\
    \ <cassert>\n#include <vector>\ntemplate <typename T>\nstruct Edge {\n    using\
    \ W = T;\n    int from, to, id;\n    W weight;\n};\ntemplate <typename T>\nvoid\
    \ debug(const Edge<T> &e) {\n    std::cerr << e.from << \" -> \" << e.to << \"\
    \ id = \" << e.id << \" weight = \";\n    debug(e.weight);\n}\ntemplate <typename\
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
    \ {}\n    int v() const { return n; }\n    int e() const { return m; }\n    void\
    \ add_edge(int from, int to, W weight = 1) {\n        assert(0 <= from && from\
    \ < n && 0 <= to && to < n);\n        edges.emplace_back(E{from, to, m++, weight});\n\
    \    }\n    void build() {\n        sep.assign(n + 1, 0);\n        csr.resize(DIRECTED\
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
    \ + sep[v], csr.begin() + sep[v + 1]};\n    }\n};\n#line 5 \"graph/heavy_light_decomposition.hpp\"\
    \nclass HeavyLightDecomposition {\npublic:\n    std::vector<int> siz, par, hea,\
    \ in, out, dep, rev;\n\nprivate:\n    template <typename T, bool DIR>\n    void\
    \ dfs1(Graph<T, DIR> &g, int v) {\n        if (g[v].size() >= 1 && g[v][0].to\
    \ == par[v]) {\n            std::swap(g[v][0], g[v][g[v].size() - 1]);\n     \
    \   }\n        for (Edge<T> &e : g[v]) {\n            if (e.to != par[v]) {\n\
    \                par[e.to] = v;\n                dfs1(g, e.to);\n            \
    \    siz[v] += siz[e.to];\n                if (siz[e.to] > siz[g[v][0].to]) {\n\
    \                    std::swap(g[v][0], e);\n                }\n            }\n\
    \        }\n    }\n    template <typename T, bool DIR>\n    void dfs2(const Graph<T,\
    \ DIR> &g, int v, int &t) {\n        in[v] = t;\n        rev[t++] = v;\n     \
    \   for (const Edge<T> &e : g[v]) {\n            if (e.to == par[v]) {\n     \
    \           continue;\n            }\n            if (e.to == g[v][0].to) {\n\
    \                hea[e.to] = hea[v];\n            } else {\n                hea[e.to]\
    \ = e.to;\n            }\n            dep[e.to] = dep[v] + 1;\n            dfs2(g,\
    \ e.to, t);\n        }\n        out[v] = t;\n    }\n\npublic:\n    template <typename\
    \ T, bool DIR>\n    HeavyLightDecomposition(Graph<T, DIR> &g, int root = 0)\n\
    \        : siz(g.v(), 1),\n          par(g.v(), root),\n          hea(g.v(), root),\n\
    \          in(g.v(), 0),\n          out(g.v(), 0),\n          dep(g.v(), 0),\n\
    \          rev(g.v(), 0) {\n        assert(0 <= root && root < g.v());\n     \
    \   dfs1(g, root);\n        int t = 0;\n        dfs2(g, root, t);\n    }\n   \
    \ // par^k\n    int la(int v, int k) const {\n        assert(0 <= v && v < (int)dep.size());\n\
    \        assert(k >= 0);\n        if (k > dep[v]) {\n            return -1;\n\
    \        }\n        while (true) {\n            int u = hea[v];\n            if\
    \ (in[u] + k <= in[v]) {\n                return rev[in[v] - k];\n           \
    \ }\n            k -= in[v] - in[u] + 1;\n            v = par[u];\n        }\n\
    \        return 0;\n    }\n    int lca(int u, int v) const {\n        assert(0\
    \ <= u && u < (int)dep.size());\n        assert(0 <= v && v < (int)dep.size());\n\
    \        while (u != v) {\n            if (in[u] > in[v]) {\n                std::swap(u,\
    \ v);\n            }\n            if (hea[u] == hea[v]) {\n                v =\
    \ u;\n            } else {\n                v = par[hea[v]];\n            }\n\
    \        }\n        return u;\n    }\n    int dist(int u, int v) const {\n   \
    \     assert(0 <= u && u < (int)dep.size());\n        assert(0 <= v && v < (int)dep.size());\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    int jump(int\
    \ u, int v, int k) const {\n        assert(0 <= u && u < (int)dep.size());\n \
    \       assert(0 <= v && v < (int)dep.size());\n        assert(k >= 0);\n    \
    \    int l = lca(u, v);\n        int dis = dep[u] + dep[v] - 2 * dep[l];\n   \
    \     if (k > dis) {\n            return -1;\n        }\n        if (k <= dep[u]\
    \ - dep[l]) {\n            return la(u, k);\n        } else {\n            return\
    \ la(v, dis - k);\n        }\n    }\n    int meet(int u, int v, int w) const {\n\
    \        return lca(u, v) ^ lca(v, w) ^ lca(w, u);\n    }\n    std::vector<std::pair<int,\
    \ int>> path(int u, int v, bool edge) const {\n        assert(0 <= u && u < (int)dep.size());\n\
    \        assert(0 <= v && v < (int)dep.size());\n        std::vector<std::pair<int,\
    \ int>> fromu, fromv;\n        bool rev = false;\n        while (true) {\n   \
    \         if (u == v && edge) {\n                break;\n            }\n     \
    \       if (in[u] > in[v]) {\n                std::swap(u, v);\n             \
    \   std::swap(fromu, fromv);\n                rev ^= true;\n            }\n  \
    \          if (hea[u] == hea[v]) {\n                fromv.emplace_back(in[v],\
    \ in[u] + (int)edge);\n                v = u;\n                break;\n      \
    \      } else {\n                fromv.emplace_back(in[v], in[hea[v]]);\n    \
    \            v = par[hea[v]];\n            }\n        }\n        if (rev) {\n\
    \            std::swap(fromu, fromv);\n        }\n        std::reverse(fromv.begin(),\
    \ fromv.end());\n        fromu.reserve(fromv.size());\n        for (auto [x, y]\
    \ : fromv) {\n            fromu.emplace_back(y, x);\n        }\n        return\
    \ fromu;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include \"graph.hpp\"\
    \nclass HeavyLightDecomposition {\npublic:\n    std::vector<int> siz, par, hea,\
    \ in, out, dep, rev;\n\nprivate:\n    template <typename T, bool DIR>\n    void\
    \ dfs1(Graph<T, DIR> &g, int v) {\n        if (g[v].size() >= 1 && g[v][0].to\
    \ == par[v]) {\n            std::swap(g[v][0], g[v][g[v].size() - 1]);\n     \
    \   }\n        for (Edge<T> &e : g[v]) {\n            if (e.to != par[v]) {\n\
    \                par[e.to] = v;\n                dfs1(g, e.to);\n            \
    \    siz[v] += siz[e.to];\n                if (siz[e.to] > siz[g[v][0].to]) {\n\
    \                    std::swap(g[v][0], e);\n                }\n            }\n\
    \        }\n    }\n    template <typename T, bool DIR>\n    void dfs2(const Graph<T,\
    \ DIR> &g, int v, int &t) {\n        in[v] = t;\n        rev[t++] = v;\n     \
    \   for (const Edge<T> &e : g[v]) {\n            if (e.to == par[v]) {\n     \
    \           continue;\n            }\n            if (e.to == g[v][0].to) {\n\
    \                hea[e.to] = hea[v];\n            } else {\n                hea[e.to]\
    \ = e.to;\n            }\n            dep[e.to] = dep[v] + 1;\n            dfs2(g,\
    \ e.to, t);\n        }\n        out[v] = t;\n    }\n\npublic:\n    template <typename\
    \ T, bool DIR>\n    HeavyLightDecomposition(Graph<T, DIR> &g, int root = 0)\n\
    \        : siz(g.v(), 1),\n          par(g.v(), root),\n          hea(g.v(), root),\n\
    \          in(g.v(), 0),\n          out(g.v(), 0),\n          dep(g.v(), 0),\n\
    \          rev(g.v(), 0) {\n        assert(0 <= root && root < g.v());\n     \
    \   dfs1(g, root);\n        int t = 0;\n        dfs2(g, root, t);\n    }\n   \
    \ // par^k\n    int la(int v, int k) const {\n        assert(0 <= v && v < (int)dep.size());\n\
    \        assert(k >= 0);\n        if (k > dep[v]) {\n            return -1;\n\
    \        }\n        while (true) {\n            int u = hea[v];\n            if\
    \ (in[u] + k <= in[v]) {\n                return rev[in[v] - k];\n           \
    \ }\n            k -= in[v] - in[u] + 1;\n            v = par[u];\n        }\n\
    \        return 0;\n    }\n    int lca(int u, int v) const {\n        assert(0\
    \ <= u && u < (int)dep.size());\n        assert(0 <= v && v < (int)dep.size());\n\
    \        while (u != v) {\n            if (in[u] > in[v]) {\n                std::swap(u,\
    \ v);\n            }\n            if (hea[u] == hea[v]) {\n                v =\
    \ u;\n            } else {\n                v = par[hea[v]];\n            }\n\
    \        }\n        return u;\n    }\n    int dist(int u, int v) const {\n   \
    \     assert(0 <= u && u < (int)dep.size());\n        assert(0 <= v && v < (int)dep.size());\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n    int jump(int\
    \ u, int v, int k) const {\n        assert(0 <= u && u < (int)dep.size());\n \
    \       assert(0 <= v && v < (int)dep.size());\n        assert(k >= 0);\n    \
    \    int l = lca(u, v);\n        int dis = dep[u] + dep[v] - 2 * dep[l];\n   \
    \     if (k > dis) {\n            return -1;\n        }\n        if (k <= dep[u]\
    \ - dep[l]) {\n            return la(u, k);\n        } else {\n            return\
    \ la(v, dis - k);\n        }\n    }\n    int meet(int u, int v, int w) const {\n\
    \        return lca(u, v) ^ lca(v, w) ^ lca(w, u);\n    }\n    std::vector<std::pair<int,\
    \ int>> path(int u, int v, bool edge) const {\n        assert(0 <= u && u < (int)dep.size());\n\
    \        assert(0 <= v && v < (int)dep.size());\n        std::vector<std::pair<int,\
    \ int>> fromu, fromv;\n        bool rev = false;\n        while (true) {\n   \
    \         if (u == v && edge) {\n                break;\n            }\n     \
    \       if (in[u] > in[v]) {\n                std::swap(u, v);\n             \
    \   std::swap(fromu, fromv);\n                rev ^= true;\n            }\n  \
    \          if (hea[u] == hea[v]) {\n                fromv.emplace_back(in[v],\
    \ in[u] + (int)edge);\n                v = u;\n                break;\n      \
    \      } else {\n                fromv.emplace_back(in[v], in[hea[v]]);\n    \
    \            v = par[hea[v]];\n            }\n        }\n        if (rev) {\n\
    \            std::swap(fromu, fromv);\n        }\n        std::reverse(fromv.begin(),\
    \ fromv.end());\n        fromu.reserve(fromv.size());\n        for (auto [x, y]\
    \ : fromv) {\n            fromu.emplace_back(y, x);\n        }\n        return\
    \ fromu;\n    }\n};"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2023-12-28 18:43:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/jump_on_tree.test.cpp
  - graph/test/lca.test.cpp
documentation_of: graph/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/graph/heavy_light_decomposition.hpp
- /library/graph/heavy_light_decomposition.hpp.html
title: graph/heavy_light_decomposition.hpp
---
