---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/1891.test.cpp
    title: data_structure/test/1891.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree_xor_range.hpp\"\n\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename Monoid>\nclass SegmentTreeXorRange\
    \ {\npublic:\n    using Value = typename Monoid::Value;\n\nprivate:\n    static\
    \ int floor_log2(int n) { return 31 - __builtin_clz(n); }\n\n    int depth;\n\
    \    std::vector<std::vector<Value>> node;\n\npublic:\n    SegmentTreeXorRange(const\
    \ std::vector<Value> &a)\n        : depth(floor_log2((int)a.size())), node(2 *\
    \ (int)a.size()) {\n        assert(!a.empty());\n        assert((int)a.size()\
    \ == (1 << depth));\n        for (int i = 0; i < (int)a.size(); ++i) {\n     \
    \       node[a.size() + i] = {a[i]};\n        }\n        for (int i = (int)a.size()\
    \ - 1; i > 0; --i) {\n            int k = (int)node[2 * i].size();\n         \
    \   node[i].resize(2 * k);\n            for (int j = 0; j < k; ++j) {\n      \
    \          node[i][j] = Monoid::op(node[2 * i][j], node[2 * i + 1][j]);\n    \
    \            node[i][j + k] = Monoid::op(node[2 * i + 1][j], node[2 * i][j]);\n\
    \            }\n        }\n    }\n\n    Value prod(int l, int r, int x) const\
    \ {\n        assert(l >= 0 && l <= r && r <= (1 << depth));\n        int d = depth;\n\
    \        int nodel_prefix = l;\n        int noder_prefix = r;\n        l += 1\
    \ << depth;\n        r += 1 << depth;\n        Value lp = Monoid::id();\n    \
    \    Value rp = Monoid::id();\n        while (l < r) {\n            int x_upper\
    \ = x >> (depth - d);\n            int x_lower = x ^ (x_upper << (depth - d));\n\
    \            if (l % 2 == 1) {\n                int nodei = (x_upper ^ nodel_prefix)\
    \ + (1 << d);\n                lp = Monoid::op(lp, node[nodei][x_lower]);\n  \
    \              ++l;\n                ++nodel_prefix;\n            }\n        \
    \    if (r % 2 == 1) {\n                --r;\n                --noder_prefix;\n\
    \                int nodei = (x_upper ^ noder_prefix) + (1 << d);\n          \
    \      rp = Monoid::op(node[nodei][x_lower], rp);\n            }\n           \
    \ --d;\n            l /= 2;\n            nodel_prefix /= 2;\n            r /=\
    \ 2;\n            noder_prefix /= 2;\n        }\n        return Monoid::op(lp,\
    \ rp);\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ Monoid>\nclass SegmentTreeXorRange {\npublic:\n    using Value = typename Monoid::Value;\n\
    \nprivate:\n    static int floor_log2(int n) { return 31 - __builtin_clz(n); }\n\
    \n    int depth;\n    std::vector<std::vector<Value>> node;\n\npublic:\n    SegmentTreeXorRange(const\
    \ std::vector<Value> &a)\n        : depth(floor_log2((int)a.size())), node(2 *\
    \ (int)a.size()) {\n        assert(!a.empty());\n        assert((int)a.size()\
    \ == (1 << depth));\n        for (int i = 0; i < (int)a.size(); ++i) {\n     \
    \       node[a.size() + i] = {a[i]};\n        }\n        for (int i = (int)a.size()\
    \ - 1; i > 0; --i) {\n            int k = (int)node[2 * i].size();\n         \
    \   node[i].resize(2 * k);\n            for (int j = 0; j < k; ++j) {\n      \
    \          node[i][j] = Monoid::op(node[2 * i][j], node[2 * i + 1][j]);\n    \
    \            node[i][j + k] = Monoid::op(node[2 * i + 1][j], node[2 * i][j]);\n\
    \            }\n        }\n    }\n\n    Value prod(int l, int r, int x) const\
    \ {\n        assert(l >= 0 && l <= r && r <= (1 << depth));\n        int d = depth;\n\
    \        int nodel_prefix = l;\n        int noder_prefix = r;\n        l += 1\
    \ << depth;\n        r += 1 << depth;\n        Value lp = Monoid::id();\n    \
    \    Value rp = Monoid::id();\n        while (l < r) {\n            int x_upper\
    \ = x >> (depth - d);\n            int x_lower = x ^ (x_upper << (depth - d));\n\
    \            if (l % 2 == 1) {\n                int nodei = (x_upper ^ nodel_prefix)\
    \ + (1 << d);\n                lp = Monoid::op(lp, node[nodei][x_lower]);\n  \
    \              ++l;\n                ++nodel_prefix;\n            }\n        \
    \    if (r % 2 == 1) {\n                --r;\n                --noder_prefix;\n\
    \                int nodei = (x_upper ^ noder_prefix) + (1 << d);\n          \
    \      rp = Monoid::op(node[nodei][x_lower], rp);\n            }\n           \
    \ --d;\n            l /= 2;\n            nodel_prefix /= 2;\n            r /=\
    \ 2;\n            noder_prefix /= 2;\n        }\n        return Monoid::op(lp,\
    \ rp);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree_xor_range.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/1891.test.cpp
documentation_of: data_structure/segment_tree_xor_range.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree_xor_range.hpp
- /library/data_structure/segment_tree_xor_range.hpp.html
title: data_structure/segment_tree_xor_range.hpp
---
