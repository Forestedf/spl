---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/dsl_2_g.test.cpp
    title: data_structure/test/dsl_2_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/range_add_range_sum.hpp\"\n\n#line 2 \"data_structure/fenwick_tree.hpp\"\
    \n\n#include <cassert>\n#include <vector>\n#line 2 \"data_structure/operations.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n#include <utility>\n\ntemplate <typename\
    \ T>\nstruct Add {\n    using Value = T;\n    static Value id() { return T(0);\
    \ }\n    static Value op(const Value &lhs, const Value &rhs) { return lhs + rhs;\
    \ }\n    static Value inv(const Value &x) { return -x; }\n};\n\ntemplate <typename\
    \ T>\nstruct Mul {\n    using Value = T;\n    static Value id() { return Value(1);\
    \ }\n    static Value op(const Value &lhs, const Value &rhs) { return lhs * rhs;\
    \ }\n    static Value inv(const Value &x) { return Value(1) / x; }\n};\n\ntemplate\
    \ <typename T>\nstruct Min {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
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
    };\n#line 6 \"data_structure/fenwick_tree.hpp\"\n\ntemplate <typename CommutativeGroup>\n\
    class FenwickTree {\npublic:\n    using Value = typename CommutativeGroup::Value;\n\
    \nprivate:\n    std::vector<Value> data;\n\npublic:\n    FenwickTree(int n) :\
    \ data(n, CommutativeGroup::id()) {}\n\n    void add(int idx, const Value &x)\
    \ {\n        assert(idx >= 0 && idx < (int)data.size());\n        for (; idx <\
    \ (int)data.size(); idx |= idx + 1) {\n            data[idx] = CommutativeGroup::op(data[idx],\
    \ x);\n        }\n    }\n\n    Value sum(int r) const {\n        assert(r >= 0\
    \ && r <= (int)data.size());\n        Value ret = CommutativeGroup::id();\n  \
    \      for (; r > 0; r &= r - 1) {\n            ret = CommutativeGroup::op(ret,\
    \ data[r - 1]);\n        }\n        return ret;\n    }\n\n    Value sum(int l,\
    \ int r) const {\n        assert(l >= 0 && l <= r && r <= (int)data.size());\n\
    \        return CommutativeGroup::op(sum(r), CommutativeGroup::inv(sum(l)));\n\
    \    }\n};\n\ntemplate <typename T>\nusing FenwickTreeAdd = FenwickTree<Add<T>>;\n\
    #line 4 \"data_structure/range_add_range_sum.hpp\"\n\ntemplate <typename T>\n\
    class RangeAddRangeSum {\n    int n;\n    FenwickTree<Add<T>> ft0;\n    FenwickTree<Add<T>>\
    \ ft1;\n\npublic:\n    RangeAddRangeSum(int n) : n(n), ft0(n + 1), ft1(n + 1)\
    \ {}\n\n    void add(int l, int r, const T &v) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        ft0.add(l, v);\n        ft0.add(r, -v);\n        ft1.add(l,\
    \ -T(l) * v);\n        ft1.add(r, T(r) * v);\n    }\n\n    T sum(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        return T(r) *\
    \ ft0.sum(r) + ft1.sum(r) - T(l) * ft0.sum(l) - ft1.sum(l);\n    }\n};\n"
  code: "#pragma once\n\n#include \"fenwick_tree.hpp\"\n\ntemplate <typename T>\n\
    class RangeAddRangeSum {\n    int n;\n    FenwickTree<Add<T>> ft0;\n    FenwickTree<Add<T>>\
    \ ft1;\n\npublic:\n    RangeAddRangeSum(int n) : n(n), ft0(n + 1), ft1(n + 1)\
    \ {}\n\n    void add(int l, int r, const T &v) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        ft0.add(l, v);\n        ft0.add(r, -v);\n        ft1.add(l,\
    \ -T(l) * v);\n        ft1.add(r, T(r) * v);\n    }\n\n    T sum(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= n);\n        return T(r) *\
    \ ft0.sum(r) + ft1.sum(r) - T(l) * ft0.sum(l) - ft1.sum(l);\n    }\n};"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  - data_structure/operations.hpp
  isVerificationFile: false
  path: data_structure/range_add_range_sum.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/dsl_2_g.test.cpp
documentation_of: data_structure/range_add_range_sum.hpp
layout: document
redirect_from:
- /library/data_structure/range_add_range_sum.hpp
- /library/data_structure/range_add_range_sum.hpp.html
title: data_structure/range_add_range_sum.hpp
---
