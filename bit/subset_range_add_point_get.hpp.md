---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/random.hpp
    title: template/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: bit/test/subset_range_add_point_get.test.cpp
    title: bit/test/subset_range_add_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"bit/subset_range_add_point_get.hpp\"\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n#line 2 \"template/random.hpp\"\n#include\
    \ <chrono>\n#include <random>\n\n#if defined(LOCAL) || defined(FIX_SEED)\nstd::mt19937_64\
    \ mt(123456789);\n#else\nstd::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    #endif\n\ntemplate <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 6 \"bit/subset_range_add_point_get.hpp\"\ntemplate <typename\
    \ T>\nclass SubsetRangeAddPointGet {\n    unsigned l, ty0, ty1, ty2;\n    std::vector<T>\
    \ arr;\n\n    static long long eval(unsigned ty0, unsigned ty1, unsigned ty2,\n\
    \                          const std::vector<std::pair<unsigned, unsigned>> &add,\n\
    \                          const std::vector<unsigned> &get) {\n        long long\
    \ cost = 0;\n        for (auto [low, high] : add) {\n            unsigned tot\
    \ = ty0 & (low ^ high);\n            tot |= ty1 & low;\n            tot |= ty2\
    \ & high;\n            cost += 1LL << __builtin_popcount(tot);\n        }\n  \
    \      for (unsigned idx : get) {\n            unsigned tot = (ty1 & ~idx) | (ty2\
    \ & idx);\n            cost += 1LL << __builtin_popcount(tot);\n        }\n  \
    \      return cost;\n    }\n\npublic:\n    SubsetRangeAddPointGet(unsigned l)\
    \ : l(l), ty0(0), ty1(0), ty2(0), arr(1 << l, T()) {\n        for (unsigned i\
    \ = 0; i < l; ++i) {\n            int t = uniform(3);\n            (t == 0 ? ty0\
    \ : (t == 1 ? ty1 : ty2)) += 1u << i;\n        }\n    }\n    void read_queries(const\
    \ std::vector<std::pair<unsigned, unsigned>> &add,\n                      const\
    \ std::vector<unsigned> &get) {\n        ty0 = ty1 = ty2 = 0;\n        for (unsigned\
    \ i = 0; i < l; ++i) {\n            unsigned c0 = eval(ty0 | (1u << i), ty1, ty2,\
    \ add, get);\n            unsigned c1 = eval(ty0, ty1 | (1u << i), ty2, add, get);\n\
    \            unsigned c2 = eval(ty0, ty1, ty2 | (1u << i), add, get);\n      \
    \      unsigned c = std::min({c0, c1, c2});\n            (c0 == c ? ty0 : (c1\
    \ == c ? ty1 : ty2)) |= 1u << i;\n        }\n    }\n    void add(unsigned low,\
    \ unsigned high, T v) {\n        assert((low | high) == high);\n        assert(high\
    \ < (1u << l));\n        unsigned tot = ty0 & (low ^ high);\n        tot |= ty1\
    \ & low;\n        tot |= ty2 & ~high;\n        unsigned base = ty0 & low;\n  \
    \      base |= ty1 & (low ^ high);\n        base |= ty2 & low;\n        unsigned\
    \ q = (ty1 & low) | (ty2 & ~high);\n        T mv = -v;\n        if (__builtin_parity(ty1\
    \ & low)) {\n            std::swap(v, mv);\n        }\n        for (unsigned st\
    \ = tot; st; st = (st - 1) & tot) {\n            arr[base | st] += (__builtin_parity(q\
    \ & st) ? mv : v);\n        }\n        arr[base] += v;\n    }\n    T get(unsigned\
    \ idx) const {\n        assert(idx < (1u << l));\n        unsigned tot = (ty1\
    \ & ~idx) | (ty2 & idx);\n        unsigned base = (ty0 | ty1) & idx;\n       \
    \ T ans = arr[base];\n        for (unsigned st = tot; st; st = (st - 1) & tot)\
    \ {\n            ans += arr[base | st];\n        }\n        return ans;\n    }\n\
    };\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../template/random.hpp\"\ntemplate <typename T>\nclass SubsetRangeAddPointGet\
    \ {\n    unsigned l, ty0, ty1, ty2;\n    std::vector<T> arr;\n\n    static long\
    \ long eval(unsigned ty0, unsigned ty1, unsigned ty2,\n                      \
    \    const std::vector<std::pair<unsigned, unsigned>> &add,\n                \
    \          const std::vector<unsigned> &get) {\n        long long cost = 0;\n\
    \        for (auto [low, high] : add) {\n            unsigned tot = ty0 & (low\
    \ ^ high);\n            tot |= ty1 & low;\n            tot |= ty2 & high;\n  \
    \          cost += 1LL << __builtin_popcount(tot);\n        }\n        for (unsigned\
    \ idx : get) {\n            unsigned tot = (ty1 & ~idx) | (ty2 & idx);\n     \
    \       cost += 1LL << __builtin_popcount(tot);\n        }\n        return cost;\n\
    \    }\n\npublic:\n    SubsetRangeAddPointGet(unsigned l) : l(l), ty0(0), ty1(0),\
    \ ty2(0), arr(1 << l, T()) {\n        for (unsigned i = 0; i < l; ++i) {\n   \
    \         int t = uniform(3);\n            (t == 0 ? ty0 : (t == 1 ? ty1 : ty2))\
    \ += 1u << i;\n        }\n    }\n    void read_queries(const std::vector<std::pair<unsigned,\
    \ unsigned>> &add,\n                      const std::vector<unsigned> &get) {\n\
    \        ty0 = ty1 = ty2 = 0;\n        for (unsigned i = 0; i < l; ++i) {\n  \
    \          unsigned c0 = eval(ty0 | (1u << i), ty1, ty2, add, get);\n        \
    \    unsigned c1 = eval(ty0, ty1 | (1u << i), ty2, add, get);\n            unsigned\
    \ c2 = eval(ty0, ty1, ty2 | (1u << i), add, get);\n            unsigned c = std::min({c0,\
    \ c1, c2});\n            (c0 == c ? ty0 : (c1 == c ? ty1 : ty2)) |= 1u << i;\n\
    \        }\n    }\n    void add(unsigned low, unsigned high, T v) {\n        assert((low\
    \ | high) == high);\n        assert(high < (1u << l));\n        unsigned tot =\
    \ ty0 & (low ^ high);\n        tot |= ty1 & low;\n        tot |= ty2 & ~high;\n\
    \        unsigned base = ty0 & low;\n        base |= ty1 & (low ^ high);\n   \
    \     base |= ty2 & low;\n        unsigned q = (ty1 & low) | (ty2 & ~high);\n\
    \        T mv = -v;\n        if (__builtin_parity(ty1 & low)) {\n            std::swap(v,\
    \ mv);\n        }\n        for (unsigned st = tot; st; st = (st - 1) & tot) {\n\
    \            arr[base | st] += (__builtin_parity(q & st) ? mv : v);\n        }\n\
    \        arr[base] += v;\n    }\n    T get(unsigned idx) const {\n        assert(idx\
    \ < (1u << l));\n        unsigned tot = (ty1 & ~idx) | (ty2 & idx);\n        unsigned\
    \ base = (ty0 | ty1) & idx;\n        T ans = arr[base];\n        for (unsigned\
    \ st = tot; st; st = (st - 1) & tot) {\n            ans += arr[base | st];\n \
    \       }\n        return ans;\n    }\n};\n"
  dependsOn:
  - template/random.hpp
  isVerificationFile: false
  path: bit/subset_range_add_point_get.hpp
  requiredBy: []
  timestamp: '2026-07-08 16:34:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - bit/test/subset_range_add_point_get.test.cpp
documentation_of: bit/subset_range_add_point_get.hpp
layout: document
redirect_from:
- /library/bit/subset_range_add_point_get.hpp
- /library/bit/subset_range_add_point_get.hpp.html
title: bit/subset_range_add_point_get.hpp
---
