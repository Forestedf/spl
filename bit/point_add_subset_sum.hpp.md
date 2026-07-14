---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/random.hpp
    title: template/random.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: bit/test/point_add_subset_sum_test.cpp
    title: bit/test/point_add_subset_sum_test.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"bit/point_add_subset_sum.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <vector>\n#line 2 \"template/random.hpp\"\
    \n#include <chrono>\n#include <random>\n\n#if defined(LOCAL) || defined(FIX_SEED)\n\
    std::mt19937_64 mt(123456789);\n#else\nstd::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    #endif\n\ntemplate <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 7 \"bit/point_add_subset_sum.hpp\"\n\ntemplate <typename\
    \ CommutativeMonoid>\nclass PointAddSubsetSum {\npublic:\n    using Value = typename\
    \ CommutativeMonoid::Value;\n\nprivate:\n    unsigned l, even;\n    std::array<unsigned,\
    \ 4> mask;\n    std::vector<Value> arr;\n\npublic:\n    PointAddSubsetSum(unsigned\
    \ l_) : l((l_ + 1) / 2 * 2), even(0), mask(), arr(1 << l, CommutativeMonoid::id())\
    \ {\n        std::fill(mask.begin(), mask.end(), 0);\n        for (unsigned i\
    \ = 0; i < l; i += 2) {\n            mask[uniform(4)] |= 1u << i;\n          \
    \  even |= 1u << i;\n        }\n    }\n\n    void read_queries(const std::vector<unsigned>\
    \ &add, const std::vector<unsigned> &get) {\n        auto eval = [&] {\n     \
    \       long long cost = 0;\n            for (unsigned elem : add) {\n       \
    \         unsigned lo = elem & even;\n                unsigned hi = (elem >> 1)\
    \ & even;\n                unsigned d0 = ~lo & ~hi & even;\n                unsigned\
    \ d1 = lo & ~hi;\n                unsigned d2 = ~lo & hi;\n                unsigned\
    \ tot = (d0 & (mask[0] | mask[1] | mask[2])) | (d1 & (mask[1] | mask[2] | mask[3]))\
    \ |\n                          (d2 & (mask[0] | mask[2] | mask[3]));\n       \
    \         cost += 1LL << __builtin_popcount(tot);\n            }\n           \
    \ for (unsigned elem : get) {\n                unsigned lo = elem & even;\n  \
    \              unsigned hi = (elem >> 1) & even;\n                unsigned d1\
    \ = lo & ~hi;\n                unsigned d2 = ~lo & hi;\n                unsigned\
    \ d3 = lo & hi;\n                unsigned tot = (d1 & (mask[1] | mask[2] | mask[3]))\
    \ | (d2 & (mask[0] | mask[2] | mask[3])) |\n                          (d3 & (mask[0]\
    \ | mask[1] | mask[3]));\n                cost += 1LL << __builtin_popcount(tot);\n\
    \            }\n            return cost;\n        };\n        fill(ALL(mask),\
    \ 0);\n        for (unsigned i = 0; i < l; i += 2) {\n            long long c[4];\n\
    \            for (int j = 0; j < 4; ++j) {\n                mask[j] ^= 1u << (2\
    \ * i);\n                c[j] = eval();\n                mask[j] ^= 1u << (2 *\
    \ i);\n            }\n            int idx = std::min_element(c, c + 4) - c;\n\
    \            mask[idx] ^= 1u << (2 * i);\n        }\n    }\n\n    void add(unsigned\
    \ idx, Value v) {\n        unsigned lo = idx & even;\n        unsigned hi = (idx\
    \ >> 1) & even;\n        unsigned d0 = ~lo & ~hi & even;\n        unsigned d1\
    \ = lo & ~hi;\n        unsigned d2 = ~lo & hi;\n        unsigned add1 = (mask[0]\
    \ & (d0 | d2)) | ((mask[2] | mask[3]) & d2);\n        unsigned add2 = (mask[1]\
    \ & (d0 | d1)) | ((mask[2] | mask[3]) & d1);\n        unsigned add3 = mask[2]\
    \ & d0;\n        unsigned sub = add1 | (add2 << 1);\n        for (unsigned st\
    \ = add3; st; st = (st - 1) & add3) {\n            unsigned x = idx ^ st ^ (st\
    \ << 1);\n            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n\
    \                arr[x ^ st2] = CommutativeMonoid::op(arr[x ^ st2], v);\n    \
    \        }\n            arr[x] = CommutativeMonoid::op(arr[x], v);\n        }\n\
    \        {\n            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n\
    \                arr[idx ^ st2] = CommutativeMonoid::op(arr[idx ^ st2], v);\n\
    \            }\n            arr[idx] = CommutativeMonoid::op(arr[idx], v);\n \
    \       }\n    }\n\n    Value get(unsigned idx) const {\n        unsigned lo =\
    \ idx & even;\n        unsigned hi = (idx >> 1) & even;\n        unsigned d1 =\
    \ lo & ~hi;\n        unsigned d2 = ~lo & hi;\n        unsigned d3 = lo & hi;\n\
    \        unsigned add1 = (mask[1] & (d1 | d3)) | ((mask[2] | mask[3]) & d1);\n\
    \        unsigned add2 = (mask[0] & (d2 | d3)) | ((mask[2] | mask[3]) & d2);\n\
    \        unsigned add3 = mask[3] & d3;\n        unsigned sub = add1 | (add2 <<\
    \ 1);\n        Value ans = CommutativeMonoid::id();\n        for (unsigned st\
    \ = add3; st; st = (st - 1) & add3) {\n            unsigned x = idx ^ st ^ (st\
    \ << 1);\n            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n\
    \                ans = CommutativeMonoid::op(ans, arr[x ^ st2]);\n           \
    \ }\n            ans = CommutativeMonoid::op(ans, arr[x]);\n        }\n      \
    \  {\n            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n   \
    \             ans = CommutativeMonoid::op(ans, arr[idx ^ st2]);\n            }\n\
    \            ans = CommutativeMonoid::op(ans, arr[idx]);\n        }\n        return\
    \ ans;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <vector>\n#include \"../template/random.hpp\"\n\ntemplate <typename CommutativeMonoid>\n\
    class PointAddSubsetSum {\npublic:\n    using Value = typename CommutativeMonoid::Value;\n\
    \nprivate:\n    unsigned l, even;\n    std::array<unsigned, 4> mask;\n    std::vector<Value>\
    \ arr;\n\npublic:\n    PointAddSubsetSum(unsigned l_) : l((l_ + 1) / 2 * 2), even(0),\
    \ mask(), arr(1 << l, CommutativeMonoid::id()) {\n        std::fill(mask.begin(),\
    \ mask.end(), 0);\n        for (unsigned i = 0; i < l; i += 2) {\n           \
    \ mask[uniform(4)] |= 1u << i;\n            even |= 1u << i;\n        }\n    }\n\
    \n    void read_queries(const std::vector<unsigned> &add, const std::vector<unsigned>\
    \ &get) {\n        auto eval = [&] {\n            long long cost = 0;\n      \
    \      for (unsigned elem : add) {\n                unsigned lo = elem & even;\n\
    \                unsigned hi = (elem >> 1) & even;\n                unsigned d0\
    \ = ~lo & ~hi & even;\n                unsigned d1 = lo & ~hi;\n             \
    \   unsigned d2 = ~lo & hi;\n                unsigned tot = (d0 & (mask[0] | mask[1]\
    \ | mask[2])) | (d1 & (mask[1] | mask[2] | mask[3])) |\n                     \
    \     (d2 & (mask[0] | mask[2] | mask[3]));\n                cost += 1LL << __builtin_popcount(tot);\n\
    \            }\n            for (unsigned elem : get) {\n                unsigned\
    \ lo = elem & even;\n                unsigned hi = (elem >> 1) & even;\n     \
    \           unsigned d1 = lo & ~hi;\n                unsigned d2 = ~lo & hi;\n\
    \                unsigned d3 = lo & hi;\n                unsigned tot = (d1 &\
    \ (mask[1] | mask[2] | mask[3])) | (d2 & (mask[0] | mask[2] | mask[3])) |\n  \
    \                        (d3 & (mask[0] | mask[1] | mask[3]));\n             \
    \   cost += 1LL << __builtin_popcount(tot);\n            }\n            return\
    \ cost;\n        };\n        fill(ALL(mask), 0);\n        for (unsigned i = 0;\
    \ i < l; i += 2) {\n            long long c[4];\n            for (int j = 0; j\
    \ < 4; ++j) {\n                mask[j] ^= 1u << (2 * i);\n                c[j]\
    \ = eval();\n                mask[j] ^= 1u << (2 * i);\n            }\n      \
    \      int idx = std::min_element(c, c + 4) - c;\n            mask[idx] ^= 1u\
    \ << (2 * i);\n        }\n    }\n\n    void add(unsigned idx, Value v) {\n   \
    \     unsigned lo = idx & even;\n        unsigned hi = (idx >> 1) & even;\n  \
    \      unsigned d0 = ~lo & ~hi & even;\n        unsigned d1 = lo & ~hi;\n    \
    \    unsigned d2 = ~lo & hi;\n        unsigned add1 = (mask[0] & (d0 | d2)) |\
    \ ((mask[2] | mask[3]) & d2);\n        unsigned add2 = (mask[1] & (d0 | d1)) |\
    \ ((mask[2] | mask[3]) & d1);\n        unsigned add3 = mask[2] & d0;\n       \
    \ unsigned sub = add1 | (add2 << 1);\n        for (unsigned st = add3; st; st\
    \ = (st - 1) & add3) {\n            unsigned x = idx ^ st ^ (st << 1);\n     \
    \       for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n             \
    \   arr[x ^ st2] = CommutativeMonoid::op(arr[x ^ st2], v);\n            }\n  \
    \          arr[x] = CommutativeMonoid::op(arr[x], v);\n        }\n        {\n\
    \            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n        \
    \        arr[idx ^ st2] = CommutativeMonoid::op(arr[idx ^ st2], v);\n        \
    \    }\n            arr[idx] = CommutativeMonoid::op(arr[idx], v);\n        }\n\
    \    }\n\n    Value get(unsigned idx) const {\n        unsigned lo = idx & even;\n\
    \        unsigned hi = (idx >> 1) & even;\n        unsigned d1 = lo & ~hi;\n \
    \       unsigned d2 = ~lo & hi;\n        unsigned d3 = lo & hi;\n        unsigned\
    \ add1 = (mask[1] & (d1 | d3)) | ((mask[2] | mask[3]) & d1);\n        unsigned\
    \ add2 = (mask[0] & (d2 | d3)) | ((mask[2] | mask[3]) & d2);\n        unsigned\
    \ add3 = mask[3] & d3;\n        unsigned sub = add1 | (add2 << 1);\n        Value\
    \ ans = CommutativeMonoid::id();\n        for (unsigned st = add3; st; st = (st\
    \ - 1) & add3) {\n            unsigned x = idx ^ st ^ (st << 1);\n           \
    \ for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n                ans\
    \ = CommutativeMonoid::op(ans, arr[x ^ st2]);\n            }\n            ans\
    \ = CommutativeMonoid::op(ans, arr[x]);\n        }\n        {\n            for\
    \ (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {\n                ans = CommutativeMonoid::op(ans,\
    \ arr[idx ^ st2]);\n            }\n            ans = CommutativeMonoid::op(ans,\
    \ arr[idx]);\n        }\n        return ans;\n    }\n};\n"
  dependsOn:
  - template/random.hpp
  isVerificationFile: false
  path: bit/point_add_subset_sum.hpp
  requiredBy:
  - bit/test/point_add_subset_sum_test.cpp
  timestamp: '2026-07-14 21:24:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/point_add_subset_sum.hpp
layout: document
redirect_from:
- /library/bit/point_add_subset_sum.hpp
- /library/bit/point_add_subset_sum.hpp.html
title: bit/point_add_subset_sum.hpp
---
