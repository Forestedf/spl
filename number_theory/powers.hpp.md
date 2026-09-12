---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/powers.hpp\"\n#include <cassert>\n#include\
    \ <vector>\ntemplate <typename M>\nstruct PowTable {\n    int n;\n    std::vector<M>\
    \ pow;\n    std::vector<M> invpow;\n    PowTable(int n, M r) : n(n), pow(n + 1),\
    \ invpow(n + 1) {\n        assert(n >= 0);\n        M p = M::raw(1);\n       \
    \ for (int i = 0; i <= n; ++i) {\n            pow[i] = p;\n            p *= r;\n\
    \        }\n        if (r.val != 0) {\n            p = M::raw(1);\n          \
    \  M inv = r.inv();\n            for (int i = 0; i <= n; ++i) {\n            \
    \    invpow[i] = p;\n                p *= inv;\n            }\n        }\n   \
    \ }\n    M get(int e) const {\n        return (e < 0 ? invpow[-e] : pow[e]);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\ntemplate <typename M>\n\
    struct PowTable {\n    int n;\n    std::vector<M> pow;\n    std::vector<M> invpow;\n\
    \    PowTable(int n, M r) : n(n), pow(n + 1), invpow(n + 1) {\n        assert(n\
    \ >= 0);\n        M p = M::raw(1);\n        for (int i = 0; i <= n; ++i) {\n \
    \           pow[i] = p;\n            p *= r;\n        }\n        if (r.val !=\
    \ 0) {\n            p = M::raw(1);\n            M inv = r.inv();\n           \
    \ for (int i = 0; i <= n; ++i) {\n                invpow[i] = p;\n           \
    \     p *= inv;\n            }\n        }\n    }\n    M get(int e) const {\n \
    \       return (e < 0 ? invpow[-e] : pow[e]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/powers.hpp
  requiredBy: []
  timestamp: '2026-09-12 20:53:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: number_theory/powers.hpp
layout: document
redirect_from:
- /library/number_theory/powers.hpp
- /library/number_theory/powers.hpp.html
title: number_theory/powers.hpp
---
