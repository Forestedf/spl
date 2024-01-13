---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: number_theory/test/frac_binsearch_stress.test.cpp
    title: number_theory/test/frac_binsearch_stress.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/frac_binsearch.hpp\"\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n\n// f :: I -> I -> bool\ntemplate <typename\
    \ I, typename F>\nstd::pair<I, I> get_lim_true(I bound, F f) {\n    assert(bound\
    \ >= 1);\n    std::pair<I, I> ok(0, 1), ng(1, 0);\n    if (!f(0, 1)) {\n     \
    \   std::swap(ok, ng);\n    }\n    while (true) {\n        std::pair<I, I> now(ok.first\
    \ + ng.first, ok.second + ng.second);\n        bool rt = f(now.first, now.second);\n\
    \        std::pair<I, I> &from = (rt ? ok : ng), &to = (rt ? ng : ok);\n     \
    \   I l = 1, r = 2;\n        while (f(from.first + to.first * r, from.second +\
    \ to.second * r) == rt) {\n            l *= 2;\n            r *= 2;\n        \
    \    if (std::max(from.first + to.first * l, from.second + to.second * l) > bound)\
    \ {\n                if (rt) {\n                    I t = l;\n               \
    \     if (to.first != 0) {\n                        t = std::min(t, (bound - from.first)\
    \ / to.first);\n                    }\n                    if (to.second != 0)\
    \ {\n                        t = std::min(t, (bound - from.second) / to.second);\n\
    \                    }\n                    return std::pair<I, I>(from.first\
    \ + to.first * t, from.second + to.second * t);\n                } else {\n  \
    \                  return ok;\n                }\n            }\n        }\n \
    \       while (r - l > 1) {\n            I mid = (l + r) / 2;\n            std::pair<I,\
    \ I> nxt(from.first + to.first * mid, from.second + to.second * mid);\n      \
    \      if (std::max(nxt.first, nxt.second) <= bound && f(nxt.first, nxt.second)\
    \ == rt) {\n                l = mid;\n            } else {\n                r\
    \ = mid;\n            }\n        }\n        if (std::max(from.first + to.first\
    \ * r, from.second + to.second * r) > bound) {\n            if (rt) {\n      \
    \          return std::pair<I, I>(from.first + to.first * l, from.second + to.second\
    \ * l);\n            } else {\n                return to;\n            }\n   \
    \     }\n        from.first += to.first * l;\n        from.second += to.second\
    \ * l;\n    }\n    assert(false);\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    \n// f :: I -> I -> bool\ntemplate <typename I, typename F>\nstd::pair<I, I> get_lim_true(I\
    \ bound, F f) {\n    assert(bound >= 1);\n    std::pair<I, I> ok(0, 1), ng(1,\
    \ 0);\n    if (!f(0, 1)) {\n        std::swap(ok, ng);\n    }\n    while (true)\
    \ {\n        std::pair<I, I> now(ok.first + ng.first, ok.second + ng.second);\n\
    \        bool rt = f(now.first, now.second);\n        std::pair<I, I> &from =\
    \ (rt ? ok : ng), &to = (rt ? ng : ok);\n        I l = 1, r = 2;\n        while\
    \ (f(from.first + to.first * r, from.second + to.second * r) == rt) {\n      \
    \      l *= 2;\n            r *= 2;\n            if (std::max(from.first + to.first\
    \ * l, from.second + to.second * l) > bound) {\n                if (rt) {\n  \
    \                  I t = l;\n                    if (to.first != 0) {\n      \
    \                  t = std::min(t, (bound - from.first) / to.first);\n       \
    \             }\n                    if (to.second != 0) {\n                 \
    \       t = std::min(t, (bound - from.second) / to.second);\n                \
    \    }\n                    return std::pair<I, I>(from.first + to.first * t,\
    \ from.second + to.second * t);\n                } else {\n                  \
    \  return ok;\n                }\n            }\n        }\n        while (r -\
    \ l > 1) {\n            I mid = (l + r) / 2;\n            std::pair<I, I> nxt(from.first\
    \ + to.first * mid, from.second + to.second * mid);\n            if (std::max(nxt.first,\
    \ nxt.second) <= bound && f(nxt.first, nxt.second) == rt) {\n                l\
    \ = mid;\n            } else {\n                r = mid;\n            }\n    \
    \    }\n        if (std::max(from.first + to.first * r, from.second + to.second\
    \ * r) > bound) {\n            if (rt) {\n                return std::pair<I,\
    \ I>(from.first + to.first * l, from.second + to.second * l);\n            } else\
    \ {\n                return to;\n            }\n        }\n        from.first\
    \ += to.first * l;\n        from.second += to.second * l;\n    }\n    assert(false);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/frac_binsearch.hpp
  requiredBy: []
  timestamp: '2024-01-10 11:46:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - number_theory/test/frac_binsearch_stress.test.cpp
documentation_of: number_theory/frac_binsearch.hpp
layout: document
redirect_from:
- /library/number_theory/frac_binsearch.hpp
- /library/number_theory/frac_binsearch.hpp.html
title: number_theory/frac_binsearch.hpp
---
