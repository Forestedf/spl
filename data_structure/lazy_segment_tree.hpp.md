---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_affine_range_sum.test.cpp
    title: data_structure/test/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/lazy_segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename MonoidFunc>\nclass\
    \ LazySegmentTree {\npublic:\n    using Value = typename MonoidFunc::Value;\n\
    \    using Func = typename MonoidFunc::Func;\n\nprivate:\n    int old_length;\n\
    \    int lg;\n    int length;\n    std::vector<Value> values;\n    std::vector<Func>\
    \ funcs;\n\n    static int lg2(int n) {\n        int x = 1;\n        int l = 0;\n\
    \        while (x < n) {\n            x <<= 1;\n            ++l;\n        }\n\
    \        return l;\n    }\n\n    void _apply(int idx, const Func &func) {\n  \
    \      values[idx] = MonoidFunc::apply(func, values[idx]);\n        funcs[idx]\
    \ = MonoidFunc::composite(func, funcs[idx]);\n    }\n\n    void push(int idx)\
    \ {\n        _apply(idx << 1, funcs[idx]);\n        _apply(idx << 1 | 1, funcs[idx]);\n\
    \        funcs[idx] = MonoidFunc::func_id();\n    }\n\n    void recalc_values(int\
    \ idx) {\n        values[idx] = MonoidFunc::op(values[idx << 1], values[idx <<\
    \ 1 | 1]);\n    }\n\npublic:\n    LazySegmentTree(int n)\n        : old_length(n),\n\
    \          lg(lg2(n)),\n          length(1 << lg),\n          values(length <<\
    \ 1, MonoidFunc::id()),\n          funcs(length << 1, MonoidFunc::func_id()) {\n\
    \        assert(n >= 0);\n    }\n\n    LazySegmentTree(const std::vector<Value>\
    \ &v)\n        : old_length((int)v.size()),\n          lg(lg2(old_length)),\n\
    \          length(1 << lg),\n          values(length << 1, MonoidFunc::id()),\n\
    \          funcs(length << 1, MonoidFunc::func_id()) {\n        for (int i = 0;\
    \ i < old_length; ++i) {\n            values[i + length] = v[i];\n        }\n\
    \        for (int i = length - 1; i > 0; --i) {\n            recalc_values(i);\n\
    \        }\n    }\n\n    template <typename F>\n    LazySegmentTree(int n, const\
    \ F &f)\n        : old_length(n),\n          lg(lg2(n)),\n          length(1 <<\
    \ lg),\n          values(length << 1, MonoidFunc::id()),\n          funcs(length\
    \ << 1, MonoidFunc::func_id()) {\n        for (int i = 0; i < old_length; ++i)\
    \ {\n            values[i + length] = f(i);\n        }\n        for (int i = length\
    \ - 1; i > 0; --i) {\n            recalc_values(i);\n        }\n    }\n\n    void\
    \ update(int idx, Value val) {\n        assert(idx >= 0 && idx < old_length);\n\
    \        idx += length;\n        for (int i = lg; i > 0; --i) {\n            push(idx\
    \ >> i);\n        }\n        values[idx] = std::move(val);\n        while (idx\
    \ >>= 1) {\n            recalc_values(idx);\n        }\n    }\n\n    void apply(int\
    \ l, int r, const Func &func) {\n        assert(l >= 0 && l <= r && r <= old_length);\n\
    \        if (l == r) {\n            return;\n        }\n        l += length;\n\
    \        r += length;\n        int _l = l;\n        int _r = r;\n        for (int\
    \ i = lg; i > 0; --i) {\n            push(_l >> i);\n            push((_r - 1)\
    \ >> i);\n        }\n        while (l < r) {\n            if (l & 1) {\n     \
    \           _apply(l++, func);\n            }\n            if (r & 1) {\n    \
    \            _apply(--r, func);\n            }\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        for (int i = 1; i <= lg; ++i) {\n         \
    \   if ((_l >> i << i) != _l) {\n                recalc_values(_l >> i);\n   \
    \         }\n            if ((_r >> i << i) != _r) {\n                recalc_values((_r\
    \ - 1) >> i);\n            }\n        }\n    }\n\n    Value prod(int l, int r)\
    \ {\n        assert(l >= 0 && l <= r && r <= old_length);\n        if (l == r)\
    \ {\n            return MonoidFunc::id();\n        }\n        l += length;\n \
    \       r += length;\n        for (int i = lg; i > 0; --i) {\n            push(l\
    \ >> i);\n            push((r - 1) >> i);\n        }\n        Value lp = MonoidFunc::id();\n\
    \        Value rp = MonoidFunc::id();\n        while (l < r) {\n            if\
    \ (l & 1) {\n                lp = MonoidFunc::op(lp, values[l++]);\n         \
    \   }\n            if (r & 1) {\n                rp = MonoidFunc::op(values[--r],\
    \ rp);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return MonoidFunc::op(lp, rp);\n    }\n\n    Value all_prod() const {\
    \ return values[1]; }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename MonoidFunc>\nclass LazySegmentTree {\npublic:\n    using\
    \ Value = typename MonoidFunc::Value;\n    using Func = typename MonoidFunc::Func;\n\
    \nprivate:\n    int old_length;\n    int lg;\n    int length;\n    std::vector<Value>\
    \ values;\n    std::vector<Func> funcs;\n\n    static int lg2(int n) {\n     \
    \   int x = 1;\n        int l = 0;\n        while (x < n) {\n            x <<=\
    \ 1;\n            ++l;\n        }\n        return l;\n    }\n\n    void _apply(int\
    \ idx, const Func &func) {\n        values[idx] = MonoidFunc::apply(func, values[idx]);\n\
    \        funcs[idx] = MonoidFunc::composite(func, funcs[idx]);\n    }\n\n    void\
    \ push(int idx) {\n        _apply(idx << 1, funcs[idx]);\n        _apply(idx <<\
    \ 1 | 1, funcs[idx]);\n        funcs[idx] = MonoidFunc::func_id();\n    }\n\n\
    \    void recalc_values(int idx) {\n        values[idx] = MonoidFunc::op(values[idx\
    \ << 1], values[idx << 1 | 1]);\n    }\n\npublic:\n    LazySegmentTree(int n)\n\
    \        : old_length(n),\n          lg(lg2(n)),\n          length(1 << lg),\n\
    \          values(length << 1, MonoidFunc::id()),\n          funcs(length << 1,\
    \ MonoidFunc::func_id()) {\n        assert(n >= 0);\n    }\n\n    LazySegmentTree(const\
    \ std::vector<Value> &v)\n        : old_length((int)v.size()),\n          lg(lg2(old_length)),\n\
    \          length(1 << lg),\n          values(length << 1, MonoidFunc::id()),\n\
    \          funcs(length << 1, MonoidFunc::func_id()) {\n        for (int i = 0;\
    \ i < old_length; ++i) {\n            values[i + length] = v[i];\n        }\n\
    \        for (int i = length - 1; i > 0; --i) {\n            recalc_values(i);\n\
    \        }\n    }\n\n    template <typename F>\n    LazySegmentTree(int n, const\
    \ F &f)\n        : old_length(n),\n          lg(lg2(n)),\n          length(1 <<\
    \ lg),\n          values(length << 1, MonoidFunc::id()),\n          funcs(length\
    \ << 1, MonoidFunc::func_id()) {\n        for (int i = 0; i < old_length; ++i)\
    \ {\n            values[i + length] = f(i);\n        }\n        for (int i = length\
    \ - 1; i > 0; --i) {\n            recalc_values(i);\n        }\n    }\n\n    void\
    \ update(int idx, Value val) {\n        assert(idx >= 0 && idx < old_length);\n\
    \        idx += length;\n        for (int i = lg; i > 0; --i) {\n            push(idx\
    \ >> i);\n        }\n        values[idx] = std::move(val);\n        while (idx\
    \ >>= 1) {\n            recalc_values(idx);\n        }\n    }\n\n    void apply(int\
    \ l, int r, const Func &func) {\n        assert(l >= 0 && l <= r && r <= old_length);\n\
    \        if (l == r) {\n            return;\n        }\n        l += length;\n\
    \        r += length;\n        int _l = l;\n        int _r = r;\n        for (int\
    \ i = lg; i > 0; --i) {\n            push(_l >> i);\n            push((_r - 1)\
    \ >> i);\n        }\n        while (l < r) {\n            if (l & 1) {\n     \
    \           _apply(l++, func);\n            }\n            if (r & 1) {\n    \
    \            _apply(--r, func);\n            }\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        for (int i = 1; i <= lg; ++i) {\n         \
    \   if ((_l >> i << i) != _l) {\n                recalc_values(_l >> i);\n   \
    \         }\n            if ((_r >> i << i) != _r) {\n                recalc_values((_r\
    \ - 1) >> i);\n            }\n        }\n    }\n\n    Value prod(int l, int r)\
    \ {\n        assert(l >= 0 && l <= r && r <= old_length);\n        if (l == r)\
    \ {\n            return MonoidFunc::id();\n        }\n        l += length;\n \
    \       r += length;\n        for (int i = lg; i > 0; --i) {\n            push(l\
    \ >> i);\n            push((r - 1) >> i);\n        }\n        Value lp = MonoidFunc::id();\n\
    \        Value rp = MonoidFunc::id();\n        while (l < r) {\n            if\
    \ (l & 1) {\n                lp = MonoidFunc::op(lp, values[l++]);\n         \
    \   }\n            if (r & 1) {\n                rp = MonoidFunc::op(values[--r],\
    \ rp);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return MonoidFunc::op(lp, rp);\n    }\n\n    Value all_prod() const {\
    \ return values[1]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/range_affine_range_sum.test.cpp
documentation_of: data_structure/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_segment_tree.hpp
- /library/data_structure/lazy_segment_tree.hpp.html
title: data_structure/lazy_segment_tree.hpp
---
