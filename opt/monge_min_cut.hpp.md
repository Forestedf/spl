---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: opt/test/yuki_119.test.cpp
    title: opt/test/yuki_119.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"opt/monge_min_cut.hpp\"\n#include <atcoder/maxflow>\ntemplate\
    \ <typename T>\nclass MongeMinCut {\n    int n;\n    std::vector<int> k;\n   \
    \ std::vector<int> offset;\n    int s;\n    int t;\n    T all;\n    atcoder::mf_graph<T>\
    \ graph;\n    T big;\n    void add_v(int v, T f0, T f1) {\n        if (f0 <= f1)\
    \ {\n            add_0(f0);\n            graph.add_edge(s, v, f1 - f0);\n    \
    \    } else {\n            add_0(f1);\n            graph.add_edge(v, t, f0 - f1);\n\
    \        }\n    }\n\npublic:\n    MongeMinCut(const std::vector<int> &k, T big)\n\
    \        : n((int)k.size()),\n          k(k),\n          offset(n, 0),\n     \
    \     s(0),\n          t(0),\n          all(0),\n          graph(0),\n       \
    \   big(big) {\n        for (int i = 0; i < n; ++i) {\n            assert(k[i]\
    \ >= 1);\n        }\n        for (int i = 0; i < n - 1; ++i) {\n            offset[i\
    \ + 1] = offset[i] + k[i] - 1;\n        }\n        s = 0;\n        for (int i\
    \ = 0; i < n; ++i) {\n            s += k[i];\n        }\n        t = s + 1;\n\
    \        graph = atcoder::mf_graph<T>(s + 2);\n        for (int i = 0; i < n;\
    \ ++i) {\n            for (int j = 0; j < k[i] - 2; ++j) {\n                graph.add_edge(offset[i]\
    \ + j + 1, offset[i] + j, big);\n            }\n        }\n    }\n    void add_0(T\
    \ v) { all += v; }\n    void add_1(int i, const std::vector<T> &f) {\n       \
    \ assert(0 <= i && i < n && (int)f.size() == k[i]);\n        add_0(f[0]);\n  \
    \      for (int j = 0; j < k[i] - 1; ++j) {\n            add_v(offset[i] + j,\
    \ f[j + 1] - f[j], 0);\n        }\n    }\n    void add_2(int x, int y, std::vector<std::vector<T>>\
    \ f) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n \
    \       assert((int)f.size() == k[x]);\n        for (int i = 0; i < k[x]; ++i)\
    \ {\n            assert((int)f[i].size() == k[y]);\n        }\n        std::vector<T>\
    \ tmp(k[x]);\n        for (int i = 0; i < k[x]; ++i) {\n            tmp[i] = f[i][0];\n\
    \        }\n        add_1(x, tmp);\n        for (int i = 0; i < k[x]; ++i) {\n\
    \            for (int j = 0; j < k[y]; ++j) {\n                f[i][j] -= tmp[i];\n\
    \            }\n        }\n        tmp = f[0];\n        add_1(y, tmp);\n     \
    \   for (int i = 0; i < k[x]; ++i) {\n            for (int j = 0; j < k[y]; ++j)\
    \ {\n                f[i][j] -= tmp[j];\n            }\n        }\n        for\
    \ (int i = 0; i < k[x] - 1; ++i) {\n            for (int j = 0; j < k[y] - 1;\
    \ ++j) {\n                T val = f[i][j] + f[i + 1][j + 1] - f[i + 1][j] - f[i][j\
    \ + 1];\n                assert(val <= 0);\n                add_0(val);\n    \
    \            graph.add_edge(offset[x] + i, offset[y] + j, -val);\n           \
    \     graph.add_edge(s, offset[x] + i, -val);\n            }\n        }\n    }\n\
    \    std::pair<T, std::vector<int>> solve() {\n        T cost = graph.flow(s,\
    \ t) + all;\n        std::vector<bool> cut = graph.min_cut(s);\n        std::vector<int>\
    \ ans(n, 0);\n        for (int i = 0; i < n; ++i) {\n            for (int j =\
    \ 0; j < k[i] - 1; ++j) {\n                if (cut[offset[i] + j]) {\n       \
    \             ++ans[i];\n                }\n            }\n        }\n       \
    \ return std::pair<T, std::vector<int>>(cost, ans);\n    }\n};\n"
  code: "#pragma once\n#include <atcoder/maxflow>\ntemplate <typename T>\nclass MongeMinCut\
    \ {\n    int n;\n    std::vector<int> k;\n    std::vector<int> offset;\n    int\
    \ s;\n    int t;\n    T all;\n    atcoder::mf_graph<T> graph;\n    T big;\n  \
    \  void add_v(int v, T f0, T f1) {\n        if (f0 <= f1) {\n            add_0(f0);\n\
    \            graph.add_edge(s, v, f1 - f0);\n        } else {\n            add_0(f1);\n\
    \            graph.add_edge(v, t, f0 - f1);\n        }\n    }\n\npublic:\n   \
    \ MongeMinCut(const std::vector<int> &k, T big)\n        : n((int)k.size()),\n\
    \          k(k),\n          offset(n, 0),\n          s(0),\n          t(0),\n\
    \          all(0),\n          graph(0),\n          big(big) {\n        for (int\
    \ i = 0; i < n; ++i) {\n            assert(k[i] >= 1);\n        }\n        for\
    \ (int i = 0; i < n - 1; ++i) {\n            offset[i + 1] = offset[i] + k[i]\
    \ - 1;\n        }\n        s = 0;\n        for (int i = 0; i < n; ++i) {\n   \
    \         s += k[i];\n        }\n        t = s + 1;\n        graph = atcoder::mf_graph<T>(s\
    \ + 2);\n        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j\
    \ < k[i] - 2; ++j) {\n                graph.add_edge(offset[i] + j + 1, offset[i]\
    \ + j, big);\n            }\n        }\n    }\n    void add_0(T v) { all += v;\
    \ }\n    void add_1(int i, const std::vector<T> &f) {\n        assert(0 <= i &&\
    \ i < n && (int)f.size() == k[i]);\n        add_0(f[0]);\n        for (int j =\
    \ 0; j < k[i] - 1; ++j) {\n            add_v(offset[i] + j, f[j + 1] - f[j], 0);\n\
    \        }\n    }\n    void add_2(int x, int y, std::vector<std::vector<T>> f)\
    \ {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n    \
    \    assert((int)f.size() == k[x]);\n        for (int i = 0; i < k[x]; ++i) {\n\
    \            assert((int)f[i].size() == k[y]);\n        }\n        std::vector<T>\
    \ tmp(k[x]);\n        for (int i = 0; i < k[x]; ++i) {\n            tmp[i] = f[i][0];\n\
    \        }\n        add_1(x, tmp);\n        for (int i = 0; i < k[x]; ++i) {\n\
    \            for (int j = 0; j < k[y]; ++j) {\n                f[i][j] -= tmp[i];\n\
    \            }\n        }\n        tmp = f[0];\n        add_1(y, tmp);\n     \
    \   for (int i = 0; i < k[x]; ++i) {\n            for (int j = 0; j < k[y]; ++j)\
    \ {\n                f[i][j] -= tmp[j];\n            }\n        }\n        for\
    \ (int i = 0; i < k[x] - 1; ++i) {\n            for (int j = 0; j < k[y] - 1;\
    \ ++j) {\n                T val = f[i][j] + f[i + 1][j + 1] - f[i + 1][j] - f[i][j\
    \ + 1];\n                assert(val <= 0);\n                add_0(val);\n    \
    \            graph.add_edge(offset[x] + i, offset[y] + j, -val);\n           \
    \     graph.add_edge(s, offset[x] + i, -val);\n            }\n        }\n    }\n\
    \    std::pair<T, std::vector<int>> solve() {\n        T cost = graph.flow(s,\
    \ t) + all;\n        std::vector<bool> cut = graph.min_cut(s);\n        std::vector<int>\
    \ ans(n, 0);\n        for (int i = 0; i < n; ++i) {\n            for (int j =\
    \ 0; j < k[i] - 1; ++j) {\n                if (cut[offset[i] + j]) {\n       \
    \             ++ans[i];\n                }\n            }\n        }\n       \
    \ return std::pair<T, std::vector<int>>(cost, ans);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: opt/monge_min_cut.hpp
  requiredBy: []
  timestamp: '2024-03-30 23:06:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - opt/test/yuki_119.test.cpp
documentation_of: opt/monge_min_cut.hpp
layout: document
redirect_from:
- /library/opt/monge_min_cut.hpp
- /library/opt/monge_min_cut.hpp.html
title: opt/monge_min_cut.hpp
---
