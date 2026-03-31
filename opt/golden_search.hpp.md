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
  bundledCode: "#line 2 \"opt/golden_search.hpp\"\n#include <cassert>\n#include <utility>\n\
    #include <functional>\n\ntemplate <typename F, typename I, typename Comp = std::less<>>\n\
    auto golden_search(const F &f, I mn, I mx, Comp comp = Comp()) -> std::pair<I,\
    \ decltype(f(mn))> {\n    using V = decltype(f(mn));\n    assert(mn <= mx);\n\
    \    I x0, x1, x2;\n    {\n        x0 = mn - 1;\n        I s = 1, t = 1;\n   \
    \     while (x0 + s + t <= mx) {\n            I u = s + t;\n            s = t;\n\
    \            t = u;\n        }\n        x1 = x0 + s + t;\n        x2 = x0 + s;\n\
    \    }\n    V fx2 = f(x2);\n    V fx3 = 0;\n    while (2 * x2 != x0 + x1) {\n\
    \        I x3 = x0 + x1 - x2;\n        if (x3 > mx) {\n            x1 = x0;\n\
    \            x0 = x3;\n        } else {\n            fx3 = f(x3);\n          \
    \  if (comp(fx2, fx3)) {\n                x1 = x0;\n                x0 = x3;\n\
    \            } else {\n                x0 = x2;\n                x2 = x3;\n  \
    \              fx2 = fx3;\n            }\n        }\n    }\n    return std::pair<I,\
    \ V>(x2, fx2);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <functional>\n\
    \ntemplate <typename F, typename I, typename Comp = std::less<>>\nauto golden_search(const\
    \ F &f, I mn, I mx, Comp comp = Comp()) -> std::pair<I, decltype(f(mn))> {\n \
    \   using V = decltype(f(mn));\n    assert(mn <= mx);\n    I x0, x1, x2;\n   \
    \ {\n        x0 = mn - 1;\n        I s = 1, t = 1;\n        while (x0 + s + t\
    \ <= mx) {\n            I u = s + t;\n            s = t;\n            t = u;\n\
    \        }\n        x1 = x0 + s + t;\n        x2 = x0 + s;\n    }\n    V fx2 =\
    \ f(x2);\n    V fx3 = 0;\n    while (2 * x2 != x0 + x1) {\n        I x3 = x0 +\
    \ x1 - x2;\n        if (x3 > mx) {\n            x1 = x0;\n            x0 = x3;\n\
    \        } else {\n            fx3 = f(x3);\n            if (comp(fx2, fx3)) {\n\
    \                x1 = x0;\n                x0 = x3;\n            } else {\n  \
    \              x0 = x2;\n                x2 = x3;\n                fx2 = fx3;\n\
    \            }\n        }\n    }\n    return std::pair<I, V>(x2, fx2);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: opt/golden_search.hpp
  requiredBy: []
  timestamp: '2026-03-31 19:23:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: opt/golden_search.hpp
layout: document
redirect_from:
- /library/opt/golden_search.hpp
- /library/opt/golden_search.hpp.html
title: opt/golden_search.hpp
---
