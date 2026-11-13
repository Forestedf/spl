---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/tree_path_composite_sum.test.cpp
    title: graph/test/tree_path_composite_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: spl/graph/graph.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"spl/graph/graph.hpp\"\n\n// rake :: Data -> Data\
    \ -> Data\n// add_vertex :: Data -> int(root) -> Data\n// add_edge :: Data ->\
    \ int(root) -> int(new root) -> int(edge index) -> Data\ntemplate <typename Data>\n\
    class RerootingDP {\n    std::vector<Data> dp;\n    std::vector<Data> edp;\n \
    \   std::vector<int> vs, rank;\n    \npublic:\n    template <typename T, typename\
    \ F1, typename F2, typename F3>\n    RerootingDP(const Graph<T, false> &g, const\
    \ F1 &rake, const F2 &add_vertex, const F3 &add_edge, const Data &id) {\n    \
    \    assert(g.v() >= 1);\n        std::vector<int> par(g.v(), -1), stc;\n    \
    \    vs.reserve(g.v());\n        stc.push_back(0);\n        while (!stc.empty())\
    \ {\n            int v = stc.back();\n            stc.pop_back();\n          \
    \  vs.push_back(v);\n            for (Edge<T> e : g[v]) {\n                if\
    \ (e.to != par[v]) {\n                    par[e.to] = v;\n                   \
    \ stc.push_back(e.to);\n                }\n            }\n        }\n        \n\
    \        rank.resize(g.v() + 1, 0);\n        for (int i = 0; i < g.v(); ++i) {\n\
    \            rank[i + 1] = rank[i] + g[i].size();\n        }\n        \n     \
    \   dp.resize(g.v(), id);\n        edp.resize(rank.back(), id);\n        \n  \
    \      // DP (1st)\n        for (int i = g.v() - 1; i >= 0; --i) {\n         \
    \   int v = vs[i];\n            for (int j = 0; j < g[v].size(); ++j) {\n    \
    \            Edge<T> e = g[v][j];\n                if (e.to == par[v]) {\n   \
    \                 continue;\n                }\n                edp[rank[v] +\
    \ j] = add_edge(add_vertex(dp[e.to], e.to), e.to, v, e.id);\n                dp[v]\
    \ = rake(dp[v], edp[rank[v] + j]);\n            }\n        }\n        \n     \
    \   // DP (2nd)\n        std::vector<Data> trans(g.v(), id);\n        std::vector<Data>\
    \ forw(g.v(), id), bacw(g.v(), id);\n        for (int i = 0; i < g.v(); ++i) {\n\
    \            int v = vs[i];\n            dp[v] = add_vertex(rake(dp[v], trans[v]),\
    \ v);\n            int k = g[v].size();\n            for (int j = 0; j < k; ++j)\
    \ {\n                if (g[v][j].to == par[v]) {\n                    edp[rank[v]\
    \ + j] = trans[v];\n                }\n                forw[j + 1] = rake(forw[j],\
    \ edp[rank[v] + j]);\n            }\n            bacw[k] = id;\n            for\
    \ (int j = k - 1; j >= 0; --j) {\n                bacw[j] = rake(bacw[j + 1],\
    \ edp[rank[v] + j]);\n            }\n            for (int j = 0; j < k; ++j) {\n\
    \                if (int to = g[v][j].to; to != par[v]) {\n                  \
    \  int id = g[v][j].id;\n                    trans[to] = add_edge(add_vertex(rake(forw[j],\
    \ bacw[j + 1]), v), v, to, id);\n                }\n            }\n        }\n\
    \    }\n    \n    const Data &operator[](int v) const {\n        return dp[v];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/rerooting.hpp
  requiredBy: []
  timestamp: '2026-11-13 18:06:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/tree_path_composite_sum.test.cpp
documentation_of: graph/rerooting.hpp
layout: document
redirect_from:
- /library/graph/rerooting.hpp
- /library/graph/rerooting.hpp.html
title: graph/rerooting.hpp
---
