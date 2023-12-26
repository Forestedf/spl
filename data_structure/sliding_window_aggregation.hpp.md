---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/queue_operate_all_composite.test.cpp
    title: data_structure/test/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sliding_window_aggregation.hpp\"\n\n#include\
    \ <cassert>\n#include <stack>\n#include <utility>\n\ntemplate <typename Monoid>\n\
    class SlidingWindowAggregation {\npublic:\n    using Value = typename Monoid::Value;\n\
    \nprivate:\n    std::stack<Value> st0;\n    std::stack<Value> st1;\n    Value\
    \ st1_prod;\n\npublic:\n    SlidingWindowAggregation()\n        : st0({Monoid::id()}),\
    \ st1({Monoid::id()}), st1_prod(Monoid::id()) {}\n\n    void push(Value val) {\n\
    \        st1_prod = Monoid::op(st1_prod, val);\n        st1.emplace(std::move(val));\n\
    \    }\n\n    void pop() {\n        if (st0.size() == 1) {\n            while\
    \ (st1.size() > 1) {\n                st0.emplace(Monoid::op(st1.top(), st0.top()));\n\
    \                st1.pop();\n            }\n            st1_prod = Monoid::id();\n\
    \        }\n        st0.pop();\n    }\n\n    int size() const { return (int)(st0.size()\
    \ + st1.size() - 2); }\n\n    bool empty() const { return size() == 0; }\n\n \
    \   Value prod() const { return Monoid::op(st0.top(), st1_prod); }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <stack>\n#include <utility>\n\
    \ntemplate <typename Monoid>\nclass SlidingWindowAggregation {\npublic:\n    using\
    \ Value = typename Monoid::Value;\n\nprivate:\n    std::stack<Value> st0;\n  \
    \  std::stack<Value> st1;\n    Value st1_prod;\n\npublic:\n    SlidingWindowAggregation()\n\
    \        : st0({Monoid::id()}), st1({Monoid::id()}), st1_prod(Monoid::id()) {}\n\
    \n    void push(Value val) {\n        st1_prod = Monoid::op(st1_prod, val);\n\
    \        st1.emplace(std::move(val));\n    }\n\n    void pop() {\n        if (st0.size()\
    \ == 1) {\n            while (st1.size() > 1) {\n                st0.emplace(Monoid::op(st1.top(),\
    \ st0.top()));\n                st1.pop();\n            }\n            st1_prod\
    \ = Monoid::id();\n        }\n        st0.pop();\n    }\n\n    int size() const\
    \ { return (int)(st0.size() + st1.size() - 2); }\n\n    bool empty() const { return\
    \ size() == 0; }\n\n    Value prod() const { return Monoid::op(st0.top(), st1_prod);\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sliding_window_aggregation.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/queue_operate_all_composite.test.cpp
documentation_of: data_structure/sliding_window_aggregation.hpp
layout: document
redirect_from:
- /library/data_structure/sliding_window_aggregation.hpp
- /library/data_structure/sliding_window_aggregation.hpp.html
title: data_structure/sliding_window_aggregation.hpp
---
