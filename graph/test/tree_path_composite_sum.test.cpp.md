---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/rerooting.hpp
    title: graph/rerooting.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.18/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: spl/graph/graph.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n#define FAST_IO\n#include \"../../graph/rerooting.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../template/fastio.hpp\"\
    \n\nusing M = ModInt<998244353>;\n\nvoid solve() {\n    i32 n;\n    rd.read(n);\n\
    \    V<M> a(n);\n    REP(i, n) {\n        rd.read(a[i].val);\n    }\n    V<pair<M,\
    \ M>> fs(n - 1);\n    Graph<> g(n);\n    REP(i, n - 1) {\n        i32 u, v;\n\
    \        rd.read(u, v, fs[i].first.val, fs[i].second.val);\n        g.add_edge(u,\
    \ v);\n    }\n    g.build();\n    \n    // sum, cnt\n    using Data = pair<M,\
    \ M>;\n    auto rake = [](Data x, Data y) {\n        return Data(x.first + y.first,\
    \ x.second + y.second);\n    };\n    auto add_vertex = [&](Data x, int v) -> Data\
    \ {\n        return Data(x.first + a[v], x.second + M(1));\n    };\n    auto add_edge\
    \ = [&](Data x, int v, int nr, int e) -> Data {\n        auto [a, b] = fs[e];\n\
    \        return Data(x.first * a + x.second * b, x.second);\n    };\n    Data\
    \ id;\n    \n    RerootingDP<Data> dp(g, rake, add_vertex, add_edge, id);\n  \
    \  REP(i, n) {\n        M ans = dp[i].first;\n        wr.writeln(ans.val);\n \
    \   }\n}\n\nint main() {\n    i32 t = 1;\n    // cin >> t;\n    while (t--) {\n\
    \        solve();\n    }\n}\n"
  dependsOn:
  - graph/rerooting.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - template/template.hpp
  - template/fastio.hpp
  isVerificationFile: true
  path: graph/test/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2026-11-13 18:06:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/graph/test/tree_path_composite_sum.test.cpp
- /verify/graph/test/tree_path_composite_sum.test.cpp.html
title: graph/test/tree_path_composite_sum.test.cpp
---
