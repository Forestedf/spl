---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_set_range_composite.test.cpp
    title: data_structure/test/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n#line 2 \"data_structure/operations.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n#line 6 \"data_structure/operations.hpp\"\
    \n\ntemplate <typename T>\nstruct Add {\n    using Value = T;\n    static Value\
    \ id() { return T(0); }\n    static Value op(const Value &lhs, const Value &rhs)\
    \ { return lhs + rhs; }\n    static Value inv(const Value &x) { return -x; }\n\
    };\n\ntemplate <typename T>\nstruct Mul {\n    using Value = T;\n    static Value\
    \ id() { return Value(1); }\n    static Value op(const Value &lhs, const Value\
    \ &rhs) { return lhs * rhs; }\n    static Value inv(const Value &x) { return Value(1)\
    \ / x; }\n};\n\ntemplate <typename T>\nstruct Min {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
    \    using Value = T;\n    static Value id() { return std::numeric_limits<T>::max();\
    \ }\n    static Value op(const Value &lhs, const Value &rhs) {\n        return\
    \ std::min(lhs, rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Max {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
    \    using Value = T;\n    static Value id() { return std::numeric_limits<Value>::min();\
    \ }\n    static Value op(const Value &lhs, const Value &rhs) {\n        return\
    \ std::max(lhs, rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Xor {\n    using\
    \ Value = T;\n    static Value id() { return T(0); }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) { return lhs ^ rhs; }\n    static Value inv(const\
    \ Value &x) { return x; }\n};\n\ntemplate <typename Monoid>\nstruct Reversible\
    \ {\n    using Value = std::pair<typename Monoid::Value, typename Monoid::Value>;\n\
    \    static Value id() { return Value(Monoid::id(), Monoid::id()); }\n    static\
    \ Value op(const Value &v1, const Value &v2) {\n        return Value(Monoid::op(v1.first,\
    \ v2.first),\n                     Monoid::op(v2.second, v1.second));\n    }\n\
    };\n#line 7 \"data_structure/segment_tree.hpp\"\n\ntemplate <typename Monoid>\n\
    class SegmentTree {\npublic:\n    using Value = typename Monoid::Value;\n\nprivate:\n\
    \    int old_length;\n    int length;\n    std::vector<Value> node;\n\n    static\
    \ int ceil2(int n) {\n        int l = 1;\n        while (l < n) {\n          \
    \  l <<= 1;\n        }\n        return l;\n    }\n\npublic:\n    SegmentTree(int\
    \ n)\n        : old_length(n),\n          length(ceil2(old_length)),\n       \
    \   node(length << 1, Monoid::id()) {\n        assert(n >= 0);\n    }\n\n    SegmentTree(const\
    \ std::vector<Value> &v)\n        : old_length((int)v.size()),\n          length(ceil2(old_length)),\n\
    \          node(length << 1, Monoid::id()) {\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = v[i];\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    template <typename F>\n    SegmentTree(int\
    \ n, const F &f)\n        : old_length(n), length(ceil2(n)), node(length << 1,\
    \ Monoid::id()) {\n        assert(n >= 0);\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = f(i);\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    const Value &operator[](int idx)\
    \ const {\n        assert(idx >= 0 && idx < old_length);\n        return node[idx\
    \ + length];\n    }\n\n    void update(int idx, Value val) {\n        assert(idx\
    \ >= 0 && idx < old_length);\n        idx += length;\n        node[idx] = std::move(val);\n\
    \        while (idx != 1) {\n            idx >>= 1;\n            node[idx] = Monoid::op(node[idx\
    \ << 1], node[idx << 1 | 1]);\n        }\n    }\n\n    Value prod(int l, int r)\
    \ const {\n        assert(l >= 0 && l <= r && r <= old_length);\n        Value\
    \ prodl = Monoid::id();\n        Value prodr = Monoid::id();\n        l += length;\n\
    \        r += length;\n        while (l != r) {\n            if (l & 1) {\n  \
    \              prodl = Monoid::op(prodl, node[l++]);\n            }\n        \
    \    if (r & 1) {\n                prodr = Monoid::op(node[--r], prodr);\n   \
    \         }\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ Monoid::op(prodl, prodr);\n    }\n\n    Value all_prod() const { return node[1];\
    \ }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"operations.hpp\"\n\ntemplate <typename Monoid>\nclass SegmentTree {\n\
    public:\n    using Value = typename Monoid::Value;\n\nprivate:\n    int old_length;\n\
    \    int length;\n    std::vector<Value> node;\n\n    static int ceil2(int n)\
    \ {\n        int l = 1;\n        while (l < n) {\n            l <<= 1;\n     \
    \   }\n        return l;\n    }\n\npublic:\n    SegmentTree(int n)\n        :\
    \ old_length(n),\n          length(ceil2(old_length)),\n          node(length\
    \ << 1, Monoid::id()) {\n        assert(n >= 0);\n    }\n\n    SegmentTree(const\
    \ std::vector<Value> &v)\n        : old_length((int)v.size()),\n          length(ceil2(old_length)),\n\
    \          node(length << 1, Monoid::id()) {\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = v[i];\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    template <typename F>\n    SegmentTree(int\
    \ n, const F &f)\n        : old_length(n), length(ceil2(n)), node(length << 1,\
    \ Monoid::id()) {\n        assert(n >= 0);\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = f(i);\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    const Value &operator[](int idx)\
    \ const {\n        assert(idx >= 0 && idx < old_length);\n        return node[idx\
    \ + length];\n    }\n\n    void update(int idx, Value val) {\n        assert(idx\
    \ >= 0 && idx < old_length);\n        idx += length;\n        node[idx] = std::move(val);\n\
    \        while (idx != 1) {\n            idx >>= 1;\n            node[idx] = Monoid::op(node[idx\
    \ << 1], node[idx << 1 | 1]);\n        }\n    }\n\n    Value prod(int l, int r)\
    \ const {\n        assert(l >= 0 && l <= r && r <= old_length);\n        Value\
    \ prodl = Monoid::id();\n        Value prodr = Monoid::id();\n        l += length;\n\
    \        r += length;\n        while (l != r) {\n            if (l & 1) {\n  \
    \              prodl = Monoid::op(prodl, node[l++]);\n            }\n        \
    \    if (r & 1) {\n                prodr = Monoid::op(node[--r], prodr);\n   \
    \         }\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ Monoid::op(prodl, prodr);\n    }\n\n    Value all_prod() const { return node[1];\
    \ }\n};\n"
  dependsOn:
  - data_structure/operations.hpp
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/point_set_range_composite.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: data_structure/segment_tree.hpp
---
