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
  bundledCode: "#line 2 \"other/mo.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <vector>\n\nclass MoManager {\n    int n, q, buc;\n\
    \    std::vector<int> l, r;\n\npublic:\n    MoManager(int n, int q) : n(n), q(q),\
    \ buc(0), l(), r() {\n        assert(n >= 0);\n        assert(q >= 0);\n     \
    \   buc = std::max(1, (int)std::round(std::sqrt(3) * n /\n                   \
    \                       std::max(1., std::sqrt(2 * q))));\n        l.reserve(q);\n\
    \        r.reserve(q);\n    }\n    void add_query(int l_, int r_) {\n        assert(0\
    \ <= l_ && l_ <= r_ && r_ <= n);\n        assert((int)l.size() < q);\n       \
    \ l.push_back(l_);\n        r.push_back(r_);\n    }\n    template <typename F1,\
    \ typename F2, typename F3, typename F4, typename F5>\n    void run(F1 add_left,\
    \ F2 add_right, F3 remove_left, F4 remove_right,\n             F5 answer) {\n\
    \        std::vector<int> idx(q);\n        for (int i = 0; i < q; ++i) {\n   \
    \         idx[i] = i;\n        }\n        std::sort(idx.begin(), idx.end(), [&](int\
    \ i, int j) -> bool {\n            if (l[i] / buc != l[j] / buc) {\n         \
    \       return l[i] < l[j];\n            }\n            if (l[i] / buc % 2 ==\
    \ 0) {\n                return r[i] < r[j];\n            }\n            return\
    \ r[j] > r[i];\n        });\n        int ll = 0, rr = 0;\n        for (int i :\
    \ idx) {\n            while (ll > l[i]) {\n                add_left(--ll);\n \
    \           }\n            while (rr < r[i]) {\n                add_right(rr++);\n\
    \            }\n            while (ll < l[i]) {\n                remove_left(ll++);\n\
    \            }\n            while (rr > r[i]) {\n                remove_right(--rr);\n\
    \            }\n            answer(i);\n        }\n    }\n    template <typename\
    \ F1, typename F2, typename F3>\n    void run(F1 add, F2 remove, F3 answer) {\n\
    \        run(add, add, remove, remove, answer);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <vector>\n\nclass MoManager {\n    int n, q, buc;\n    std::vector<int>\
    \ l, r;\n\npublic:\n    MoManager(int n, int q) : n(n), q(q), buc(0), l(), r()\
    \ {\n        assert(n >= 0);\n        assert(q >= 0);\n        buc = std::max(1,\
    \ (int)std::round(std::sqrt(3) * n /\n                                       \
    \   std::max(1., std::sqrt(2 * q))));\n        l.reserve(q);\n        r.reserve(q);\n\
    \    }\n    void add_query(int l_, int r_) {\n        assert(0 <= l_ && l_ <=\
    \ r_ && r_ <= n);\n        assert((int)l.size() < q);\n        l.push_back(l_);\n\
    \        r.push_back(r_);\n    }\n    template <typename F1, typename F2, typename\
    \ F3, typename F4, typename F5>\n    void run(F1 add_left, F2 add_right, F3 remove_left,\
    \ F4 remove_right,\n             F5 answer) {\n        std::vector<int> idx(q);\n\
    \        for (int i = 0; i < q; ++i) {\n            idx[i] = i;\n        }\n \
    \       std::sort(idx.begin(), idx.end(), [&](int i, int j) -> bool {\n      \
    \      if (l[i] / buc != l[j] / buc) {\n                return l[i] < l[j];\n\
    \            }\n            if (l[i] / buc % 2 == 0) {\n                return\
    \ r[i] < r[j];\n            }\n            return r[j] > r[i];\n        });\n\
    \        int ll = 0, rr = 0;\n        for (int i : idx) {\n            while (ll\
    \ > l[i]) {\n                add_left(--ll);\n            }\n            while\
    \ (rr < r[i]) {\n                add_right(rr++);\n            }\n           \
    \ while (ll < l[i]) {\n                remove_left(ll++);\n            }\n   \
    \         while (rr > r[i]) {\n                remove_right(--rr);\n         \
    \   }\n            answer(i);\n        }\n    }\n    template <typename F1, typename\
    \ F2, typename F3>\n    void run(F1 add, F2 remove, F3 answer) {\n        run(add,\
    \ add, remove, remove, answer);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: other/mo.hpp
  requiredBy: []
  timestamp: '2025-05-10 22:14:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/mo.hpp
layout: document
redirect_from:
- /library/other/mo.hpp
- /library/other/mo.hpp.html
title: other/mo.hpp
---
