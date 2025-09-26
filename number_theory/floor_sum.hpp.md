---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number_theory/test/sum_of_floor_of_linear.test.cpp
    title: number_theory/test/sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/floor_sum.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n// Be careful about overflow\ntemplate <typename I, typename O>\n\
    O floor_sum(I l, I r, I a, I b, I m) {\n    assert(l <= r && 1 <= m);\n    O ans\
    \ = 0;\n    b += l * a;\n    I n = r - l;\n    if (a < 0) {\n        I a2 = a\
    \ % m + m;\n        ans += ((n & 1) ? O((n - 1) / 2) * O(n) : O(n / 2) * O(n -\
    \ 1)) * ((O(a) - O(a2)) / O(m));\n        a = a2;\n    }\n    if (b < 0) {\n \
    \       I b2 = b % m + m;\n        ans += (O(b) - O(b2)) / O(m) * O(n);\n    \
    \    b = b2;\n    }\n    while (n) {\n        if (a >= m) {\n            ans +=\
    \ ((n & 1) ? O((n - 1) / 2) * O(n) : O(n / 2) * O(n - 1)) * (O(a) / O(m));\n \
    \           a %= m;\n        }\n        if (b >= m) {\n            ans += O(b)\
    \ / O(m) * O(n);\n            b %= m;\n        }\n        I mx = a * n + b;\n\
    \        if (mx < m) {\n            break;\n        }\n        n = mx / m;\n \
    \       b = mx % m;\n        std::swap(a, m);\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n// Be careful about\
    \ overflow\ntemplate <typename I, typename O>\nO floor_sum(I l, I r, I a, I b,\
    \ I m) {\n    assert(l <= r && 1 <= m);\n    O ans = 0;\n    b += l * a;\n   \
    \ I n = r - l;\n    if (a < 0) {\n        I a2 = a % m + m;\n        ans += ((n\
    \ & 1) ? O((n - 1) / 2) * O(n) : O(n / 2) * O(n - 1)) * ((O(a) - O(a2)) / O(m));\n\
    \        a = a2;\n    }\n    if (b < 0) {\n        I b2 = b % m + m;\n       \
    \ ans += (O(b) - O(b2)) / O(m) * O(n);\n        b = b2;\n    }\n    while (n)\
    \ {\n        if (a >= m) {\n            ans += ((n & 1) ? O((n - 1) / 2) * O(n)\
    \ : O(n / 2) * O(n - 1)) * (O(a) / O(m));\n            a %= m;\n        }\n  \
    \      if (b >= m) {\n            ans += O(b) / O(m) * O(n);\n            b %=\
    \ m;\n        }\n        I mx = a * n + b;\n        if (mx < m) {\n          \
    \  break;\n        }\n        n = mx / m;\n        b = mx % m;\n        std::swap(a,\
    \ m);\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/floor_sum.hpp
  requiredBy: []
  timestamp: '2025-09-26 20:38:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/sum_of_floor_of_linear.test.cpp
documentation_of: number_theory/floor_sum.hpp
layout: document
redirect_from:
- /library/number_theory/floor_sum.hpp
- /library/number_theory/floor_sum.hpp.html
title: number_theory/floor_sum.hpp
---
