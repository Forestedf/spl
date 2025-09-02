---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/random.hpp
    title: template/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/bipartitematching.test.cpp
    title: graph/test/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bipartite_matching.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <utility>\n#include <vector>\n#line 2\
    \ \"template/random.hpp\"\n#include <chrono>\n#include <random>\n\n#if defined(LOCAL)\
    \ || defined(FIX_SEED)\nstd::mt19937_64 mt(123456789);\n#else\nstd::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n#endif\n\n\
    template <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 8 \"graph/bipartite_matching.hpp\"\n\nstd::pair<std::vector<int>,\
    \ std::vector<int>> bipartite_matching(\n    int l, int r, std::vector<std::pair<int,\
    \ int>> &es) {\n    std::shuffle(es.begin(), es.end(), mt);\n    std::vector<int>\
    \ rank(l + 1, 0);\n    for (auto [u, v] : es) {\n        ++rank[u];\n    }\n \
    \   for (int i = 0; i < l; ++i) {\n        rank[i + 1] += rank[i];\n    }\n  \
    \  std::vector<int> to(es.size(), 0);\n    for (auto [u, v] : es) {\n        to[--rank[u]]\
    \ = v;\n    }\n\n    std::vector<int> ml(l, -1), mr(r, -1);\n    std::vector<int>\
    \ que(l);\n    std::vector<int> dist(l, -1), vis(l, -1);\n    int stamp = 0;\n\
    \n    auto bfs = [&]() -> bool {\n        std::fill(dist.begin(), dist.end(),\
    \ -1);\n        bool ret = false;\n        int ql = 0, qr = 0;\n        for (int\
    \ i = 0; i < l; ++i) {\n            if (ml[i] == -1) {\n                que[qr++]\
    \ = i;\n                dist[i] = 0;\n            }\n        }\n        while\
    \ (ql < qr) {\n            int u = que[ql++];\n            for (int i = rank[u];\
    \ i < rank[u + 1]; ++i) {\n                int v = to[i];\n                if\
    \ (mr[v] == -1) {\n                    ret = true;\n                } else {\n\
    \                    int w = mr[v];\n                    if (dist[w] == -1) {\n\
    \                        que[qr++] = w;\n                        dist[w] = dist[u]\
    \ + 1;\n                    }\n                }\n            }\n        }\n \
    \       return ret;\n    };\n\n    auto dfs = [&](auto dfs, int u) -> bool {\n\
    \        vis[u] = stamp;\n        for (int i = rank[u]; i < rank[u + 1]; ++i)\
    \ {\n            int v = to[i];\n            int w = mr[v];\n            if (w\
    \ == -1 ||\n                (vis[w] != stamp && dist[w] == dist[u] + 1 && dfs(dfs,\
    \ w))) {\n                ml[u] = v;\n                mr[v] = u;\n           \
    \     return true;\n            }\n        }\n        return false;\n    };\n\n\
    \    for (;; ++stamp) {\n        if (!bfs()) {\n            break;\n        }\n\
    \        for (int i = 0; i < l; ++i) {\n            if (ml[i] == -1) {\n     \
    \           dfs(dfs, i);\n            }\n        }\n    }\n\n    return std::make_pair(ml,\
    \ mr);\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n#include \"../template/random.hpp\"\n\n\
    std::pair<std::vector<int>, std::vector<int>> bipartite_matching(\n    int l,\
    \ int r, std::vector<std::pair<int, int>> &es) {\n    std::shuffle(es.begin(),\
    \ es.end(), mt);\n    std::vector<int> rank(l + 1, 0);\n    for (auto [u, v] :\
    \ es) {\n        ++rank[u];\n    }\n    for (int i = 0; i < l; ++i) {\n      \
    \  rank[i + 1] += rank[i];\n    }\n    std::vector<int> to(es.size(), 0);\n  \
    \  for (auto [u, v] : es) {\n        to[--rank[u]] = v;\n    }\n\n    std::vector<int>\
    \ ml(l, -1), mr(r, -1);\n    std::vector<int> que(l);\n    std::vector<int> dist(l,\
    \ -1), vis(l, -1);\n    int stamp = 0;\n\n    auto bfs = [&]() -> bool {\n   \
    \     std::fill(dist.begin(), dist.end(), -1);\n        bool ret = false;\n  \
    \      int ql = 0, qr = 0;\n        for (int i = 0; i < l; ++i) {\n          \
    \  if (ml[i] == -1) {\n                que[qr++] = i;\n                dist[i]\
    \ = 0;\n            }\n        }\n        while (ql < qr) {\n            int u\
    \ = que[ql++];\n            for (int i = rank[u]; i < rank[u + 1]; ++i) {\n  \
    \              int v = to[i];\n                if (mr[v] == -1) {\n          \
    \          ret = true;\n                } else {\n                    int w =\
    \ mr[v];\n                    if (dist[w] == -1) {\n                        que[qr++]\
    \ = w;\n                        dist[w] = dist[u] + 1;\n                    }\n\
    \                }\n            }\n        }\n        return ret;\n    };\n\n\
    \    auto dfs = [&](auto dfs, int u) -> bool {\n        vis[u] = stamp;\n    \
    \    for (int i = rank[u]; i < rank[u + 1]; ++i) {\n            int v = to[i];\n\
    \            int w = mr[v];\n            if (w == -1 ||\n                (vis[w]\
    \ != stamp && dist[w] == dist[u] + 1 && dfs(dfs, w))) {\n                ml[u]\
    \ = v;\n                mr[v] = u;\n                return true;\n           \
    \ }\n        }\n        return false;\n    };\n\n    for (;; ++stamp) {\n    \
    \    if (!bfs()) {\n            break;\n        }\n        for (int i = 0; i <\
    \ l; ++i) {\n            if (ml[i] == -1) {\n                dfs(dfs, i);\n  \
    \          }\n        }\n    }\n\n    return std::make_pair(ml, mr);\n}\n"
  dependsOn:
  - template/random.hpp
  isVerificationFile: false
  path: graph/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2025-09-02 15:29:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/bipartitematching.test.cpp
documentation_of: graph/bipartite_matching.hpp
layout: document
redirect_from:
- /library/graph/bipartite_matching.hpp
- /library/graph/bipartite_matching.hpp.html
title: graph/bipartite_matching.hpp
---
