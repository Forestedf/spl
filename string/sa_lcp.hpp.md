---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: data_structure/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/sa_lcp.hpp\"\n#include <atcoder/string>\n#line 2\
    \ \"data_structure/sparse_table.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n#include <functional>\n\ntemplate <typename\
    \ T, typename F = std::less<T>>\nclass SparseTable {\n    std::vector<std::vector<T>>\
    \ table;\n    int s;\n    const F f;\n\n    int log2(int n) const {\n        return\
    \ 31 - __builtin_clz(n);\n    }\n    \n    T min2(const T &x, const T &y) const\
    \ {\n        if (f(x, y)) {\n            return x;\n        } else {\n       \
    \     return y;\n        }\n    }\n\npublic:\n    SparseTable(std::vector<T> arr,\
    \ const F &f = F()) : s((int) arr.size()), f(f) {\n        if (s == 0) {\n   \
    \         return;\n        }\n        int m = log2(s);\n        table.resize(m\
    \ + 1);\n        table[0] = std::move(arr);\n        for (int i = 1; i <= m; ++i)\
    \ {\n            int w = 1 << i;\n            table[i].resize(s - w + 1);\n  \
    \          for (int j = 0; j < (int) table[i].size(); ++j) {\n               \
    \ table[i][j] = min2(table[i - 1][j], table[i - 1][j + (w >> 1)]);\n         \
    \   }\n        }\n    }\n\n    int size() const {\n        return s;\n    }\n\n\
    \    // not empty\n    T min(int l, int r) const {\n        assert(l >= 0 && l\
    \ < r && r <= s);\n        int m = log2(r - l);\n        return min2(table[m][l],\
    \ table[m][r - (1 << m)]);\n    }\n};\n\n#line 4 \"string/sa_lcp.hpp\"\n\ntemplate\
    \ <typename Cont>\nstruct StringSaLcp {\n    Cont s;\n    std::vector<int> sa,\
    \ lcp, rev;\n    SparseTable<int> sp;\n\n    StringSaLcp(const Cont &s)\n    \
    \    : s(s),\n          sa(atcoder::suffix_array(s)),\n          lcp(atcoder::lcp_array(s,\
    \ sa)),\n          rev(s.size()),\n          sp(lcp) {\n        for (int i = 0;\
    \ i < (int)s.size(); ++i) {\n            rev[sa[i]] = i;\n        }\n    }\n\n\
    \    // lcp(s[i:], s[j:])\n    int get_lcp(int i, int j) const {\n        assert(0\
    \ <= i && i <= (int)s.size());\n        assert(0 <= j && j <= (int)s.size());\n\
    \        if (i == (int)s.size() || j == (int)s.size()) {\n            return 0;\n\
    \        }\n        if (i == j) {\n            return (int)s.size() - i;\n   \
    \     }\n        i = rev[i];\n        j = rev[j];\n        if (i > j) {\n    \
    \        std::swap(i, j);\n        }\n        return sp.min(i, j);\n    }\n\n\
    \    // lcp(s[l0:r0], s[l1:r1])\n    int get_lcp(int l0, int r0, int l1, int r1)\
    \ const {\n        assert(0 <= l0 && l0 <= r0 && r0 <= (int)s.size());\n     \
    \   assert(0 <= l1 && l1 <= r1 && r1 <= (int)s.size());\n        if (l0 == r0\
    \ || l1 == r1) {\n            return 0;\n        }\n        return std::min({get_lcp(l0,\
    \ l1), r0 - l0, r1 - l1});\n    }\n\n    int cmp(int l0, int r0, int l1, int r1)\
    \ const {\n        assert(0 <= l0 && l0 <= r0 && r0 <= (int)s.size());\n     \
    \   assert(0 <= l1 && l1 <= r1 && r1 <= (int)s.size());\n        int lc = get_lcp(l0,\
    \ r0, l1, r1);\n        if (lc == r0 - l0 && lc == r1 - l1) {\n            return\
    \ 0;\n        }\n        if (lc == r0 - l0 || (lc != r1 - l1 && s[l0 + lc] < s[l1\
    \ + lc])) {\n            return -1;\n        } else {\n            return 1;\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <atcoder/string>\n#include \"../data_structure/sparse_table.hpp\"\
    \n\ntemplate <typename Cont>\nstruct StringSaLcp {\n    Cont s;\n    std::vector<int>\
    \ sa, lcp, rev;\n    SparseTable<int> sp;\n\n    StringSaLcp(const Cont &s)\n\
    \        : s(s),\n          sa(atcoder::suffix_array(s)),\n          lcp(atcoder::lcp_array(s,\
    \ sa)),\n          rev(s.size()),\n          sp(lcp) {\n        for (int i = 0;\
    \ i < (int)s.size(); ++i) {\n            rev[sa[i]] = i;\n        }\n    }\n\n\
    \    // lcp(s[i:], s[j:])\n    int get_lcp(int i, int j) const {\n        assert(0\
    \ <= i && i <= (int)s.size());\n        assert(0 <= j && j <= (int)s.size());\n\
    \        if (i == (int)s.size() || j == (int)s.size()) {\n            return 0;\n\
    \        }\n        if (i == j) {\n            return (int)s.size() - i;\n   \
    \     }\n        i = rev[i];\n        j = rev[j];\n        if (i > j) {\n    \
    \        std::swap(i, j);\n        }\n        return sp.min(i, j);\n    }\n\n\
    \    // lcp(s[l0:r0], s[l1:r1])\n    int get_lcp(int l0, int r0, int l1, int r1)\
    \ const {\n        assert(0 <= l0 && l0 <= r0 && r0 <= (int)s.size());\n     \
    \   assert(0 <= l1 && l1 <= r1 && r1 <= (int)s.size());\n        if (l0 == r0\
    \ || l1 == r1) {\n            return 0;\n        }\n        return std::min({get_lcp(l0,\
    \ l1), r0 - l0, r1 - l1});\n    }\n\n    int cmp(int l0, int r0, int l1, int r1)\
    \ const {\n        assert(0 <= l0 && l0 <= r0 && r0 <= (int)s.size());\n     \
    \   assert(0 <= l1 && l1 <= r1 && r1 <= (int)s.size());\n        int lc = get_lcp(l0,\
    \ r0, l1, r1);\n        if (lc == r0 - l0 && lc == r1 - l1) {\n            return\
    \ 0;\n        }\n        if (lc == r0 - l0 || (lc != r1 - l1 && s[l0 + lc] < s[l1\
    \ + lc])) {\n            return -1;\n        } else {\n            return 1;\n\
    \        }\n    }\n};"
  dependsOn:
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: string/sa_lcp.hpp
  requiredBy: []
  timestamp: '2024-02-04 18:18:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/sa_lcp.hpp
layout: document
redirect_from:
- /library/string/sa_lcp.hpp
- /library/string/sa_lcp.hpp.html
title: string/sa_lcp.hpp
---
