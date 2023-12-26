---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: spl/graph/biconnected_components.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n#define FAST_IO\n#include \"spl/graph/biconnected_components.hpp\"\n#include\
    \ \"spl/template/template.hpp\"\n\nvoid solve() {\n    I32(n, m);\n    Graph<>\
    \ g(n);\n    REP(i, m) {\n        I32(u, v);\n        g.add_edge(u, v);\n    }\n\
    \    g.build();\n    auto bccs = bi_connected_components(g);\n    cout << LEN(bccs)\
    \ << '\\n';\n    for (const auto &bcc : bccs) {\n        cout << LEN(bcc.vertices);\n\
    \        for (i32 v : bcc.vertices) {\n            cout << ' ' << v;\n       \
    \ }\n        cout << '\\n';\n    }\n}\n\nint main() {\n    i32 t = 1;\n    //\
    \ cin >> t;\n    while (t--) {\n        solve();\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: graph/test/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2023-12-26 15:25:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/graph/test/biconnected_components.test.cpp
- /verify/graph/test/biconnected_components.test.cpp.html
title: graph/test/biconnected_components.test.cpp
---
