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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../convolution/lcm_convolution.hpp\"\n#include \"../../template/random.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nusing M = ModInt<998244353>;\n\n\
    V<M> naive_convolution(const V<M> &a, const V<M> &b) {\n    V<M> ret(max(LEN(a),\
    \ LEN(b)));\n    REP(i, 1, LEN(a)) REP(j, 1, LEN(b)) {\n        i64 tmp = lcm(i64(i),\
    \ i64(j));\n        if (tmp < LEN(ret)) {\n            ret[tmp] += a[i] * b[j];\n\
    \        }\n    }\n    return ret;\n}\n\nvoid test() {\n    constexpr i32 NM_MAX\
    \ = 500;\n    i32 n = uniform(NM_MAX + 1);\n    i32 m = uniform(NM_MAX + 1);\n\
    \    V<M> a(n), b(m);\n    REP(i, n) { a[i].val = uniform(M::get_mod()); }\n \
    \   REP(i, m) { b[i].val = uniform(M::get_mod()); }\n    V<M> c = naive_convolution(a,\
    \ b);\n    V<M> d = lcm_convolution(a, b);\n    assert(c == d);\n}\n\nvoid small_test()\
    \ {\n    constexpr i32 NM_MAX = 10;\n    i32 n = uniform(NM_MAX + 1);\n    i32\
    \ m = uniform(NM_MAX + 1);\n    V<M> a(n), b(m);\n    REP(i, n) { a[i].val = uniform(M::get_mod());\
    \ }\n    REP(i, m) { b[i].val = uniform(M::get_mod()); }\n    V<M> c = naive_convolution(a,\
    \ b);\n    V<M> d = lcm_convolution(a, b);\n    assert(c == d);\n}\n\nvoid zero_test()\
    \ {\n    constexpr i32 NM_MAX = 5;\n    REP(n, NM_MAX + 1) REP(m, NM_MAX + 1)\
    \ {\n        V<M> a(n), b(m);\n        REP(i, n) { a[i].val = uniform(M::get_mod());\
    \ }\n        REP(i, m) { b[i].val = uniform(M::get_mod()); }\n        V<M> c =\
    \ naive_convolution(a, b);\n        V<M> d = lcm_convolution(a, b);\n        assert(c\
    \ == d);\n    }\n}\n\nint main() {\n    constexpr i32 ITER = 1000;\n    REP(i,\
    \ ITER) {\n        test();\n        small_test();\n    }\n    zero_test();\n \
    \   cout << \"Hello World\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: convolution/test/lcm_convolution.stress.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: convolution/test/lcm_convolution.stress.test.cpp
layout: document
redirect_from:
- /verify/convolution/test/lcm_convolution.stress.test.cpp
- /verify/convolution/test/lcm_convolution.stress.test.cpp.html
title: convolution/test/lcm_convolution.stress.test.cpp
---
