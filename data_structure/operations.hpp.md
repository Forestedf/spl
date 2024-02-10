---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':warning:'
    path: data_structure/range_add_point_get.hpp
    title: data_structure/range_add_point_get.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_add_range_sum.hpp
    title: data_structure/range_add_range_sum.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: data_structure/segment_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/dsl_2_g.test.cpp
    title: data_structure/test/dsl_2_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_add_range_sum.test.cpp
    title: data_structure/test/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_add_rectangle_sum.test.cpp
    title: data_structure/test/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_set_range_composite.test.cpp
    title: data_structure/test/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/rectangle_sum.test.cpp
    title: data_structure/test/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/vertex_add_path_sum.test.cpp
    title: graph/test/vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/operations.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n#include <utility>\n\ntemplate <typename T>\nstruct Add {\n\
    \    using Value = T;\n    static Value id() { return T(0); }\n    static Value\
    \ op(const Value &lhs, const Value &rhs) { return lhs + rhs; }\n    static Value\
    \ inv(const Value &x) { return -x; }\n};\n\ntemplate <typename T>\nstruct Mul\
    \ {\n    using Value = T;\n    static Value id() { return Value(1); }\n    static\
    \ Value op(const Value &lhs, const Value &rhs) { return lhs * rhs; }\n    static\
    \ Value inv(const Value &x) { return Value(1) / x; }\n};\n\ntemplate <typename\
    \ T>\nstruct Min {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
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
    };\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    \ntemplate <typename T>\nstruct Add {\n    using Value = T;\n    static Value\
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
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/operations.hpp
  requiredBy:
  - data_structure/segment_tree.hpp
  - data_structure/fenwick_tree.hpp
  - data_structure/range_add_point_get.hpp
  - data_structure/range_add_range_sum.hpp
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/vertex_add_path_sum.test.cpp
  - data_structure/test/rectangle_sum.test.cpp
  - data_structure/test/dsl_2_g.test.cpp
  - data_structure/test/point_add_range_sum.test.cpp
  - data_structure/test/point_set_range_composite.test.cpp
  - data_structure/test/point_add_rectangle_sum.test.cpp
documentation_of: data_structure/operations.hpp
layout: document
redirect_from:
- /library/data_structure/operations.hpp
- /library/data_structure/operations.hpp.html
title: data_structure/operations.hpp
---
