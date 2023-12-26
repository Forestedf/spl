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
  bundledCode: "#line 2 \"data_structure/starry_sky_tree.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <typename T>\nclass StarrySkyTree {\n    int old_len;\n\
    \    int len;\n    std::vector<T> nodes;\n\n    static int ceil2(int n) {\n  \
    \      int l = 1;\n        while (l < n) {\n            l <<= 1;\n        }\n\
    \        return l;\n    }\n\n    void balance(int idx) {\n        T mx = std::max(nodes[idx\
    \ << 1], nodes[idx << 1 | 1]);\n        nodes[idx] += mx;\n        nodes[idx <<\
    \ 1] -= mx;\n        nodes[idx << 1 | 1] -= mx;\n    }\n\npublic:\n    StarrySkyTree(int\
    \ n) : old_len(n), len(ceil2(n)), nodes(len << 1, T(0)) {}\n\n    void add(int\
    \ l, int r, T v) {\n        assert(l >= 0 && l <= r && r <= old_len);\n      \
    \  l += len;\n        r += len;\n        int l_ = l;\n        int r_ = r;\n  \
    \      while (l < r) {\n            if (l & 1) {\n                nodes[l++] +=\
    \ v;\n            }\n            if (r & 1) {\n                nodes[--r] += v;\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  for (int i = l_ >> 1; i > 0; i >>= 1) {\n            balance(i);\n        }\n\
    \        for (int i = (r_ - 1) >> 1; i > 0; i >>= 1) {\n            balance(i);\n\
    \        }\n    }\n\n    T all_max() const { return nodes[1]; }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass StarrySkyTree {\n    int old_len;\n    int len;\n    std::vector<T>\
    \ nodes;\n\n    static int ceil2(int n) {\n        int l = 1;\n        while (l\
    \ < n) {\n            l <<= 1;\n        }\n        return l;\n    }\n\n    void\
    \ balance(int idx) {\n        T mx = std::max(nodes[idx << 1], nodes[idx << 1\
    \ | 1]);\n        nodes[idx] += mx;\n        nodes[idx << 1] -= mx;\n        nodes[idx\
    \ << 1 | 1] -= mx;\n    }\n\npublic:\n    StarrySkyTree(int n) : old_len(n), len(ceil2(n)),\
    \ nodes(len << 1, T(0)) {}\n\n    void add(int l, int r, T v) {\n        assert(l\
    \ >= 0 && l <= r && r <= old_len);\n        l += len;\n        r += len;\n   \
    \     int l_ = l;\n        int r_ = r;\n        while (l < r) {\n            if\
    \ (l & 1) {\n                nodes[l++] += v;\n            }\n            if (r\
    \ & 1) {\n                nodes[--r] += v;\n            }\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        for (int i = l_ >> 1; i > 0; i >>= 1)\
    \ {\n            balance(i);\n        }\n        for (int i = (r_ - 1) >> 1; i\
    \ > 0; i >>= 1) {\n            balance(i);\n        }\n    }\n\n    T all_max()\
    \ const { return nodes[1]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/starry_sky_tree.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/starry_sky_tree.hpp
layout: document
redirect_from:
- /library/data_structure/starry_sky_tree.hpp
- /library/data_structure/starry_sky_tree.hpp.html
title: data_structure/starry_sky_tree.hpp
---
