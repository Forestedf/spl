---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/random.hpp
    title: template/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/nazo_bipartitematching.test.cpp
    title: graph/test/nazo_bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/nazo_bipartite_matching.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <queue>\n#include <utility>\n#include <vector>\n\
    #line 2 \"template/random.hpp\"\n#include <chrono>\n#include <random>\n\n#if defined(LOCAL)\
    \ || defined(FIX_SEED)\nstd::mt19937_64 mt(123456789);\n#else\nstd::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n#endif\n\n\
    template <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 8 \"graph/nazo_bipartite_matching.hpp\"\n\n// heuristic\
    \ version\n// if not shuffle, then hackable\nstd::pair<std::vector<int>, std::vector<int>>\
    \ bipartite_matching(int l, int r, std::vector<std::pair<int, int>> edges) {\n\
    \    std::shuffle(edges.begin(), edges.end(), mt);\n    assert(0 <= l && 0 <=\
    \ r);\n    std::vector<std::vector<int>> g(l);\n    for (auto [u, v] : edges)\
    \ {\n        g[u].push_back(v);\n    }\n    std::vector<int> p(l, -1), q(r, -1);\n\
    \    while (true) {\n        std::vector<int> par(l, -1), root(l, -1);\n     \
    \   std::queue<int> que;\n        for (int i = 0; i < l; ++i) {\n            if\
    \ (p[i] == -1) {\n                que.push(i);\n                root[i] = i;\n\
    \            }\n        }\n        bool upd = false;\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            if\
    \ (p[root[v]] != -1) {\n                continue;\n            }\n           \
    \ for (int u : g[v]) {\n                if (q[u] == -1) {\n                  \
    \  while (u != -1) {\n                        q[u] = v;\n                    \
    \    std::swap(p[v], u);\n                        v = par[v];\n              \
    \      }\n                    upd = true;\n                    break;\n      \
    \          }\n                int u_ = q[u];\n                if (par[u_] == -1)\
    \ {\n                    root[u_] = root[v];\n                    par[u_] = v;\n\
    \                    que.push(u_);\n                }\n            }\n       \
    \ }\n        if (!upd) {\n            break;\n        }\n    }\n    return std::make_pair(p,\
    \ q);\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n#include \"../template/random.hpp\"\n\n\
    // heuristic version\n// if not shuffle, then hackable\nstd::pair<std::vector<int>,\
    \ std::vector<int>> bipartite_matching(int l, int r, std::vector<std::pair<int,\
    \ int>> edges) {\n    std::shuffle(edges.begin(), edges.end(), mt);\n    assert(0\
    \ <= l && 0 <= r);\n    std::vector<std::vector<int>> g(l);\n    for (auto [u,\
    \ v] : edges) {\n        g[u].push_back(v);\n    }\n    std::vector<int> p(l,\
    \ -1), q(r, -1);\n    while (true) {\n        std::vector<int> par(l, -1), root(l,\
    \ -1);\n        std::queue<int> que;\n        for (int i = 0; i < l; ++i) {\n\
    \            if (p[i] == -1) {\n                que.push(i);\n               \
    \ root[i] = i;\n            }\n        }\n        bool upd = false;\n        while\
    \ (!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            if (p[root[v]] != -1) {\n                continue;\n            }\n\
    \            for (int u : g[v]) {\n                if (q[u] == -1) {\n       \
    \             while (u != -1) {\n                        q[u] = v;\n         \
    \               std::swap(p[v], u);\n                        v = par[v];\n   \
    \                 }\n                    upd = true;\n                    break;\n\
    \                }\n                int u_ = q[u];\n                if (par[u_]\
    \ == -1) {\n                    root[u_] = root[v];\n                    par[u_]\
    \ = v;\n                    que.push(u_);\n                }\n            }\n\
    \        }\n        if (!upd) {\n            break;\n        }\n    }\n    return\
    \ std::make_pair(p, q);\n}\n"
  dependsOn:
  - template/random.hpp
  isVerificationFile: false
  path: graph/nazo_bipartite_matching.hpp
  requiredBy: []
  timestamp: '2025-09-02 15:29:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/nazo_bipartitematching.test.cpp
documentation_of: graph/nazo_bipartite_matching.hpp
layout: document
redirect_from:
- /library/graph/nazo_bipartite_matching.hpp
- /library/graph/nazo_bipartite_matching.hpp.html
title: graph/nazo_bipartite_matching.hpp
---
