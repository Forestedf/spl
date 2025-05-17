---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_affine_point_get.test.cpp
    title: data_structure/test/range_affine_point_get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/dual_segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename MonoidFunc>\nclass\
    \ DualSegmentTree {\npublic:\n    using Func = typename MonoidFunc::Func;\n\n\
    private:\n    int old_length;\n    int lg;\n    int length;\n    std::vector<Func>\
    \ funcs;\n\n    static int lg2(int n) {\n        int x = 1;\n        int l = 0;\n\
    \        while (x < n) {\n            x <<= 1;\n            ++l;\n        }\n\
    \        return l;\n    }\n\n    void push(int idx) {\n        funcs[idx << 1]\
    \ = MonoidFunc::composite(funcs[idx], funcs[idx << 1]);\n        funcs[idx <<\
    \ 1 | 1] = MonoidFunc::composite(funcs[idx], funcs[idx << 1 | 1]);\n        funcs[idx]\
    \ = MonoidFunc::func_id();\n    }\n\npublic:\n    DualSegmentTree(int n)\n   \
    \     : old_length(n),\n          lg(lg2(n)),\n          length(1 << lg),\n  \
    \        funcs(length << 1, MonoidFunc::func_id()) {\n        assert(n >= 0);\n\
    \    }\n\n    Func get(int idx) {\n        assert(idx >= 0 && idx < old_length);\n\
    \        idx += length;\n        for (int i = lg; i > 0; --i) {\n            push(idx\
    \ >> i);\n        }\n        return funcs[idx];\n    }\n\n    void apply(int l,\
    \ int r, const Func &func) {\n        assert(l >= 0 && l <= r && r <= old_length);\n\
    \        if (l == r) {\n            return;\n        }\n        l += length;\n\
    \        r += length;\n        int _l = l;\n        int _r = r;\n        for (int\
    \ i = lg; i > 0; --i) {\n            push(_l >> i);\n            push((_r - 1)\
    \ >> i);\n        }\n        while (l < r) {\n            if (l & 1) {\n     \
    \           funcs[l] = MonoidFunc::composite(func, funcs[l]);\n              \
    \  ++l;\n            }\n            if (r & 1) {\n                --r;\n     \
    \           funcs[r] = MonoidFunc::composite(func, funcs[r]);\n            }\n\
    \            l >>= 1;\n            r >>= 1;\n        }\n    }\n};\n\ntemplate\
    \ <typename MonoidFunc>\nclass DualSegmentTreeWithValues {\npublic:\n    using\
    \ Value = typename MonoidFunc::Value;\n    using Func = typename MonoidFunc::Func;\n\
    \nprivate:\n    int n;\n    std::vector<Value> values;\n    DualSegmentTree<MonoidFunc>\
    \ seg;\n    \npublic:\n    DualSegmentTreeWithValues(std::vector<Value> vals)\
    \ : n((int)vals.size()), values(std::move(vals)), seg(n) {}\n    template <typename\
    \ F>\n    DualSegmentTreeWithValues(int n, F f) : n(n), values(n, MonoidFunc::id()),\
    \ seg(n) {\n        for (int i = 0; i < n; ++i) {\n            values[i] = f(i);\n\
    \        }\n    }\n    \n    void apply(int l, int r, const Func &f) {\n     \
    \   seg.apply(l, r, f);\n    }\n    \n    Value get(int idx) {\n        Func f\
    \ = seg.get(idx);\n        return MonoidFunc::apply(f, values[idx]);\n    }\n\
    };\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename MonoidFunc>\nclass DualSegmentTree {\npublic:\n    using\
    \ Func = typename MonoidFunc::Func;\n\nprivate:\n    int old_length;\n    int\
    \ lg;\n    int length;\n    std::vector<Func> funcs;\n\n    static int lg2(int\
    \ n) {\n        int x = 1;\n        int l = 0;\n        while (x < n) {\n    \
    \        x <<= 1;\n            ++l;\n        }\n        return l;\n    }\n\n \
    \   void push(int idx) {\n        funcs[idx << 1] = MonoidFunc::composite(funcs[idx],\
    \ funcs[idx << 1]);\n        funcs[idx << 1 | 1] = MonoidFunc::composite(funcs[idx],\
    \ funcs[idx << 1 | 1]);\n        funcs[idx] = MonoidFunc::func_id();\n    }\n\n\
    public:\n    DualSegmentTree(int n)\n        : old_length(n),\n          lg(lg2(n)),\n\
    \          length(1 << lg),\n          funcs(length << 1, MonoidFunc::func_id())\
    \ {\n        assert(n >= 0);\n    }\n\n    Func get(int idx) {\n        assert(idx\
    \ >= 0 && idx < old_length);\n        idx += length;\n        for (int i = lg;\
    \ i > 0; --i) {\n            push(idx >> i);\n        }\n        return funcs[idx];\n\
    \    }\n\n    void apply(int l, int r, const Func &func) {\n        assert(l >=\
    \ 0 && l <= r && r <= old_length);\n        if (l == r) {\n            return;\n\
    \        }\n        l += length;\n        r += length;\n        int _l = l;\n\
    \        int _r = r;\n        for (int i = lg; i > 0; --i) {\n            push(_l\
    \ >> i);\n            push((_r - 1) >> i);\n        }\n        while (l < r) {\n\
    \            if (l & 1) {\n                funcs[l] = MonoidFunc::composite(func,\
    \ funcs[l]);\n                ++l;\n            }\n            if (r & 1) {\n\
    \                --r;\n                funcs[r] = MonoidFunc::composite(func,\
    \ funcs[r]);\n            }\n            l >>= 1;\n            r >>= 1;\n    \
    \    }\n    }\n};\n\ntemplate <typename MonoidFunc>\nclass DualSegmentTreeWithValues\
    \ {\npublic:\n    using Value = typename MonoidFunc::Value;\n    using Func =\
    \ typename MonoidFunc::Func;\n\nprivate:\n    int n;\n    std::vector<Value> values;\n\
    \    DualSegmentTree<MonoidFunc> seg;\n    \npublic:\n    DualSegmentTreeWithValues(std::vector<Value>\
    \ vals) : n((int)vals.size()), values(std::move(vals)), seg(n) {}\n    template\
    \ <typename F>\n    DualSegmentTreeWithValues(int n, F f) : n(n), values(n, MonoidFunc::id()),\
    \ seg(n) {\n        for (int i = 0; i < n; ++i) {\n            values[i] = f(i);\n\
    \        }\n    }\n    \n    void apply(int l, int r, const Func &f) {\n     \
    \   seg.apply(l, r, f);\n    }\n    \n    Value get(int idx) {\n        Func f\
    \ = seg.get(idx);\n        return MonoidFunc::apply(f, values[idx]);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2025-05-17 23:14:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/range_affine_point_get.test.cpp
documentation_of: data_structure/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/dual_segment_tree.hpp
- /library/data_structure/dual_segment_tree.hpp.html
title: data_structure/dual_segment_tree.hpp
---
