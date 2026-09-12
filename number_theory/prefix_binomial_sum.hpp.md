---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: number_theory/test/prefix_binomial_sum.stress.test.cpp
    title: number_theory/test/prefix_binomial_sum.stress.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"number_theory/prefix_binomial_sum.hpp\"\n#include <vector>\n\
    template <typename M, int BUCKET = 200>\nclass BinomialPrefixSum {\n    static\
    \ constexpr unsigned B = BUCKET;\n    static constexpr M INV2 = M(2).inv();\n\
    \    std::vector<M> a, b, c;\n    std::vector<std::vector<M>> sums;\n    M _get(unsigned\
    \ n, unsigned k) const {\n        unsigned x = n / B;\n        unsigned y = k\
    \ / B;\n        M ans = sums[y][x];\n        y *= B;\n        x *= B;\n      \
    \  M sub;\n        while (x < n) {\n            sub += a[x] * b[x - y];\n    \
    \        ++x;\n        }\n        ans -= sub * b[y] * INV2;\n        sub = M();\n\
    \        while (y < k) {\n            ++y;\n            sub += b[y] * b[n - y];\n\
    \        }\n        ans += sub * a[n];\n        return ans;\n    }\npublic:\n\
    \    BinomialPrefixSum(int n) : a(n + 1), b(n + 1), c(n + 1), sums(n / (2 * B)\
    \ + 1) {\n        M pr = M::raw(1);\n        for (int i = 0; i <= n; ++i) {\n\
    \            a[i] = pr;\n            pr *= M::raw(i + 1) * INV2;\n        }\n\
    \        pr = M::raw(1);\n        for (int i = 1; i <= n; ++i) {\n           \
    \ pr *= M::raw(i);\n        }\n        pr = pr.inv();\n        b[n] = pr;\n  \
    \      for (int i = n - 1; i >= 0; --i) {\n            pr *= M::raw(i + 1);\n\
    \            b[i] = pr;\n        }\n        c[0] = M::raw(1);\n        for (int\
    \ i = 0; i < n; ++i) {\n            c[i + 1] = c[i] + c[i];\n        }\n     \
    \   for (int i = 0; 2 * B * i <= n; ++i) {\n            sums[i].resize(n / B +\
    \ 1);\n            M s = (M::raw(1) + a[2 * i * B] * b[i * B] * b[i * B]) * INV2;\n\
    \            sums[i][2 * i] = s;\n            int k = 2 * i * B;\n           \
    \ for (int j = 2 * i + 1; B * j <= n; ++j) {\n                M sub;\n       \
    \         for (int iter = 0; iter < B; ++iter) {\n                    sub += a[k]\
    \ * b[k - i * B];\n                    ++k;\n                }\n             \
    \   s -= sub * b[i * B] * INV2;\n                sums[i][j] = s;\n           \
    \ }\n        }\n    }\n    M get(int n, int k) const {\n        if (2 * k > n)\
    \ {\n            M ans = M::raw(1);\n            if (k < n) {\n              \
    \  ans -= _get(n, n - k - 1);\n            }\n            return ans * c[n];\n\
    \        }\n        return _get(n, k) * c[n];\n    }\n};\n"
  code: "#pragma once\n#include <vector>\ntemplate <typename M, int BUCKET = 200>\n\
    class BinomialPrefixSum {\n    static constexpr unsigned B = BUCKET;\n    static\
    \ constexpr M INV2 = M(2).inv();\n    std::vector<M> a, b, c;\n    std::vector<std::vector<M>>\
    \ sums;\n    M _get(unsigned n, unsigned k) const {\n        unsigned x = n /\
    \ B;\n        unsigned y = k / B;\n        M ans = sums[y][x];\n        y *= B;\n\
    \        x *= B;\n        M sub;\n        while (x < n) {\n            sub +=\
    \ a[x] * b[x - y];\n            ++x;\n        }\n        ans -= sub * b[y] * INV2;\n\
    \        sub = M();\n        while (y < k) {\n            ++y;\n            sub\
    \ += b[y] * b[n - y];\n        }\n        ans += sub * a[n];\n        return ans;\n\
    \    }\npublic:\n    BinomialPrefixSum(int n) : a(n + 1), b(n + 1), c(n + 1),\
    \ sums(n / (2 * B) + 1) {\n        M pr = M::raw(1);\n        for (int i = 0;\
    \ i <= n; ++i) {\n            a[i] = pr;\n            pr *= M::raw(i + 1) * INV2;\n\
    \        }\n        pr = M::raw(1);\n        for (int i = 1; i <= n; ++i) {\n\
    \            pr *= M::raw(i);\n        }\n        pr = pr.inv();\n        b[n]\
    \ = pr;\n        for (int i = n - 1; i >= 0; --i) {\n            pr *= M::raw(i\
    \ + 1);\n            b[i] = pr;\n        }\n        c[0] = M::raw(1);\n      \
    \  for (int i = 0; i < n; ++i) {\n            c[i + 1] = c[i] + c[i];\n      \
    \  }\n        for (int i = 0; 2 * B * i <= n; ++i) {\n            sums[i].resize(n\
    \ / B + 1);\n            M s = (M::raw(1) + a[2 * i * B] * b[i * B] * b[i * B])\
    \ * INV2;\n            sums[i][2 * i] = s;\n            int k = 2 * i * B;\n \
    \           for (int j = 2 * i + 1; B * j <= n; ++j) {\n                M sub;\n\
    \                for (int iter = 0; iter < B; ++iter) {\n                    sub\
    \ += a[k] * b[k - i * B];\n                    ++k;\n                }\n     \
    \           s -= sub * b[i * B] * INV2;\n                sums[i][j] = s;\n   \
    \         }\n        }\n    }\n    M get(int n, int k) const {\n        if (2\
    \ * k > n) {\n            M ans = M::raw(1);\n            if (k < n) {\n     \
    \           ans -= _get(n, n - k - 1);\n            }\n            return ans\
    \ * c[n];\n        }\n        return _get(n, k) * c[n];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: number_theory/prefix_binomial_sum.hpp
  requiredBy: []
  timestamp: '2026-09-12 20:53:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - number_theory/test/prefix_binomial_sum.stress.test.cpp
documentation_of: number_theory/prefix_binomial_sum.hpp
layout: document
redirect_from:
- /library/number_theory/prefix_binomial_sum.hpp
- /library/number_theory/prefix_binomial_sum.hpp.html
title: number_theory/prefix_binomial_sum.hpp
---
