---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../convolution/lcm_convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n#include\
    \ \"../../convolution/lcm_convolution.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../template/fastio.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nvoid solve() {\n    using M = ModInt<998244353>;\n    i32 n;\n    rd.read(n);\n\
    \    V<M> a(n + 1), b(n + 1);\n    REP(i, 1, n + 1) {\n        rd.read(a[i].val);\n\
    \    }\n    REP(i, 1, n + 1) {\n        rd.read(b[i].val);\n    }\n    V<M> c\
    \ = lcm_convolution(a, b);\n    REP(i, 1, n + 1) {\n        wr.write(c[i].val);\n\
    \        if (i != n) {\n            wr.write(' ');\n        }\n    }\n    wr.writeln();\n\
    }\n\nint main() {\n    i32 t = 1;\n    // cin >> t;\n    while (t--) {\n     \
    \   solve();\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: convolution/test/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: convolution/test/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/convolution/test/lcm_convolution.test.cpp
- /verify/convolution/test/lcm_convolution.test.cpp.html
title: convolution/test/lcm_convolution.test.cpp
---
