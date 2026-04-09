---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: graph/graph.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dynamic_tree_dp.hpp
    title: graph/dynamic_tree_dp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: graph/test/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/static_top_tree.hpp\"\n#include <algorithm>\n#include\
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
    \ + sep[v + 1]};\n    }\n};\n#line 5 \"graph/static_top_tree.hpp\"\n\nclass StaticTopTree\
    \ {\npublic:\n    enum class NodeType {\n        AddEdge,\n        AddVertex,\n\
    \        Compress,\n        Rake\n    };\n    struct Node {\n        NodeType\
    \ ty;\n        int par, lch, rch;\n    };\n\n    std::vector<Node> nodes;\n  \
    \  int stt_root;\n\n    template <typename T, bool DIR>\n    StaticTopTree(Graph<T,\
    \ DIR> &g, int root = 0) {\n        assert(0 <= root && root < g.v());\n     \
    \   nodes.reserve(3 * g.v());\n        dfs(g, root, -1);\n        nodes.resize(g.v(),\
    \ Node{NodeType::AddVertex, -1, -1, -1});\n        stt_root = compress(g, root,\
    \ -1).second;\n    }\n\nprivate:\n    template <typename T, bool DIR>\n    int\
    \ dfs(Graph<T, DIR> &g, int v, int p) {\n        int sz = 1, mx = 0;\n       \
    \ for (Edge<T> &e : g[v]) {\n            if (e.to == p) {\n                continue;\n\
    \            }\n            int t = dfs(g, e.to, v);\n            if (mx < t)\
    \ {\n                mx = t;\n                swap(g[v][0], e);\n            }\n\
    \            sz += t;\n        }\n        return sz;\n    }\n    int make_node(NodeType\
    \ ty, int lch, int rch) {\n        int v = (int)nodes.size();\n        nodes.emplace_back(Node{ty,\
    \ -1, lch, rch});\n        if (lch != -1) {\n            nodes[lch].par = v;\n\
    \        }\n        if (rch != -1) {\n            nodes[rch].par = v;\n      \
    \  }\n        return v;\n    }\n    void merge(std::vector<std::pair<int, int>>\
    \ &path) {\n        auto [xf, xs] = path.back();\n        path.pop_back();\n \
    \       auto [yf, ys] = path.back();\n        path.pop_back();\n        path.emplace_back(std::max(xf,\
    \ yf) + 1, make_node(NodeType::Compress, ys, xs));\n    }\n    template <typename\
    \ T, bool DIR>\n    std::pair<int, int> compress(const Graph<T, DIR> &g, int v,\
    \ int p) {\n        std::vector<std::pair<int, int>> path;\n        while (true)\
    \ {\n            path.emplace_back(rake(g, v, p));\n            while (true) {\n\
    \                int l = (int)path.size();\n                if (l >= 3 && (path[l\
    \ - 3].first == path[l - 2].first || path[l - 3].first <= path[l - 1].first))\
    \ {\n                    std::pair<int, int> t = path.back();\n              \
    \      path.pop_back();\n                    merge(path);\n                  \
    \  path.emplace_back(t);\n                } else if (l >= 2 && path[l - 2].first\
    \ <= path[l - 1].first) {\n                    merge(path);\n                }\
    \ else {\n                    break;\n                }\n            }\n     \
    \       if (g[v].size() == 0 || g[v][0].to == p) {\n                break;\n \
    \           }\n            p = v;\n            v = g[v][0].to;\n        }\n  \
    \      while (path.size() >= 2) {\n            merge(path);\n        }\n     \
    \   auto [xf, xs] = path.back();\n        int z = make_node(NodeType::AddEdge,\
    \ xs, -1);\n        return std::pair<int, int>(xf + 1, z);\n    }\n    template\
    \ <typename T, bool DIR>\n    std::pair<int, int> rake(const Graph<T, DIR> &g,\
    \ int v, int p) {\n        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,\
    \ int>>, std::greater<>> pq;\n        for (int i = 1; i < (int)g[v].size(); ++i)\
    \ {\n            const Edge<T> &e = g[v][i];\n            if (e.to == p) {\n \
    \               continue;\n            }\n            pq.emplace(compress(g, e.to,\
    \ v));\n        }\n        if (pq.empty()) {\n            return std::pair<int,\
    \ int>(0, v);\n        }\n        while (pq.size() >= 2) {\n            auto [xf,\
    \ xs] = pq.top();\n            pq.pop();\n            auto [yf, ys] = pq.top();\n\
    \            pq.pop();\n            pq.emplace(std::max(xf, yf) + 1, make_node(NodeType::Rake,\
    \ xs, ys));\n        }\n        auto [rf, rs] = pq.top();\n        nodes[v].lch\
    \ = rs;\n        nodes[rs].par = v;\n        return std::pair<int, int>(rf + 1,\
    \ v);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <queue>\n#include \"graph.hpp\"\
    \n\nclass StaticTopTree {\npublic:\n    enum class NodeType {\n        AddEdge,\n\
    \        AddVertex,\n        Compress,\n        Rake\n    };\n    struct Node\
    \ {\n        NodeType ty;\n        int par, lch, rch;\n    };\n\n    std::vector<Node>\
    \ nodes;\n    int stt_root;\n\n    template <typename T, bool DIR>\n    StaticTopTree(Graph<T,\
    \ DIR> &g, int root = 0) {\n        assert(0 <= root && root < g.v());\n     \
    \   nodes.reserve(3 * g.v());\n        dfs(g, root, -1);\n        nodes.resize(g.v(),\
    \ Node{NodeType::AddVertex, -1, -1, -1});\n        stt_root = compress(g, root,\
    \ -1).second;\n    }\n\nprivate:\n    template <typename T, bool DIR>\n    int\
    \ dfs(Graph<T, DIR> &g, int v, int p) {\n        int sz = 1, mx = 0;\n       \
    \ for (Edge<T> &e : g[v]) {\n            if (e.to == p) {\n                continue;\n\
    \            }\n            int t = dfs(g, e.to, v);\n            if (mx < t)\
    \ {\n                mx = t;\n                swap(g[v][0], e);\n            }\n\
    \            sz += t;\n        }\n        return sz;\n    }\n    int make_node(NodeType\
    \ ty, int lch, int rch) {\n        int v = (int)nodes.size();\n        nodes.emplace_back(Node{ty,\
    \ -1, lch, rch});\n        if (lch != -1) {\n            nodes[lch].par = v;\n\
    \        }\n        if (rch != -1) {\n            nodes[rch].par = v;\n      \
    \  }\n        return v;\n    }\n    void merge(std::vector<std::pair<int, int>>\
    \ &path) {\n        auto [xf, xs] = path.back();\n        path.pop_back();\n \
    \       auto [yf, ys] = path.back();\n        path.pop_back();\n        path.emplace_back(std::max(xf,\
    \ yf) + 1, make_node(NodeType::Compress, ys, xs));\n    }\n    template <typename\
    \ T, bool DIR>\n    std::pair<int, int> compress(const Graph<T, DIR> &g, int v,\
    \ int p) {\n        std::vector<std::pair<int, int>> path;\n        while (true)\
    \ {\n            path.emplace_back(rake(g, v, p));\n            while (true) {\n\
    \                int l = (int)path.size();\n                if (l >= 3 && (path[l\
    \ - 3].first == path[l - 2].first || path[l - 3].first <= path[l - 1].first))\
    \ {\n                    std::pair<int, int> t = path.back();\n              \
    \      path.pop_back();\n                    merge(path);\n                  \
    \  path.emplace_back(t);\n                } else if (l >= 2 && path[l - 2].first\
    \ <= path[l - 1].first) {\n                    merge(path);\n                }\
    \ else {\n                    break;\n                }\n            }\n     \
    \       if (g[v].size() == 0 || g[v][0].to == p) {\n                break;\n \
    \           }\n            p = v;\n            v = g[v][0].to;\n        }\n  \
    \      while (path.size() >= 2) {\n            merge(path);\n        }\n     \
    \   auto [xf, xs] = path.back();\n        int z = make_node(NodeType::AddEdge,\
    \ xs, -1);\n        return std::pair<int, int>(xf + 1, z);\n    }\n    template\
    \ <typename T, bool DIR>\n    std::pair<int, int> rake(const Graph<T, DIR> &g,\
    \ int v, int p) {\n        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,\
    \ int>>, std::greater<>> pq;\n        for (int i = 1; i < (int)g[v].size(); ++i)\
    \ {\n            const Edge<T> &e = g[v][i];\n            if (e.to == p) {\n \
    \               continue;\n            }\n            pq.emplace(compress(g, e.to,\
    \ v));\n        }\n        if (pq.empty()) {\n            return std::pair<int,\
    \ int>(0, v);\n        }\n        while (pq.size() >= 2) {\n            auto [xf,\
    \ xs] = pq.top();\n            pq.pop();\n            auto [yf, ys] = pq.top();\n\
    \            pq.pop();\n            pq.emplace(std::max(xf, yf) + 1, make_node(NodeType::Rake,\
    \ xs, ys));\n        }\n        auto [rf, rs] = pq.top();\n        nodes[v].lch\
    \ = rs;\n        nodes[rs].par = v;\n        return std::pair<int, int>(rf + 1,\
    \ v);\n    }\n};\n"
  dependsOn:
  - graph/graph.hpp
  isVerificationFile: false
  path: graph/static_top_tree.hpp
  requiredBy:
  - graph/dynamic_tree_dp.hpp
  timestamp: '2026-04-09 11:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: graph/static_top_tree.hpp
layout: document
redirect_from:
- /library/graph/static_top_tree.hpp
- /library/graph/static_top_tree.hpp.html
title: graph/static_top_tree.hpp
---
