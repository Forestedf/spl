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
    path: data_structure/test/rectangle_sum.test.cpp
    title: data_structure/test/rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n#line 2 \"data_structure/operations.hpp\"\n\n#include <algorithm>\n\
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
    #line 4 \"data_structure/rectangle_sum.hpp\"\ntemplate <typename C, typename V>\n\
    class RectangleSum {\n    struct Point {\n        C x, y;\n        V v;\n    };\n\
    \    struct Query {\n        C xl, xr, yl, yr;\n        int idx;\n    };\n   \
    \ std::vector<Point> pts;\n    std::vector<Query> qrs;\npublic:\n    RectangleSum()\
    \ : pts(), qrs() {}\n    void add_point(C x, C y, V v) {\n        pts.emplace_back(Point{x,\
    \ y, v});\n    }\n    void add_query(C xl, C xr, C yl, C yr) {\n        qrs.emplace_back(Query{xl,\
    \ xr, yl, yr, (int)qrs.size()});\n    }\n    std::vector<V> solve() {\n      \
    \  std::sort(pts.begin(), pts.end(), [](const Point &p0, const Point &p1) -> bool\
    \ {\n            return p0.x < p1.x;\n        });\n        struct Q {\n      \
    \      C x, d, u;\n            int id;\n            bool is_positive;\n      \
    \  };\n        std::vector<Q> q_;\n        q_.reserve(2 * qrs.size());\n     \
    \   for (const Query &qr : qrs) {\n            q_.push_back(Q{qr.xl, qr.yl, qr.yr,\
    \ qr.idx, false});\n            q_.push_back(Q{qr.xr, qr.yl, qr.yr, qr.idx, true});\n\
    \        }\n        std::sort(q_.begin(), q_.end(), [](const Q &q0, const Q &q1)\
    \ -> bool {\n            return q0.x < q1.x;\n        });\n        std::vector<C>\
    \ ys;\n        ys.reserve(pts.size());\n        for (const Point &p : pts) {\n\
    \            ys.push_back(p.y);\n        }\n        std::sort(ys.begin(), ys.end());\n\
    \        ys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n        FenwickTreeAdd<V>\
    \ fw((int)ys.size());\n        std::vector<V> ret(qrs.size(), 0);\n        typename\
    \ std::vector<Point>::iterator it = pts.begin();\n        for (const Q &q : q_)\
    \ {\n            while (it != pts.end() && it->x < q.x) {\n                int\
    \ y = (int)(std::lower_bound(ys.begin(), ys.end(), it->y) - ys.begin());\n   \
    \             fw.add(y, it->v);\n                ++it;\n            }\n      \
    \      int d = (int)(std::lower_bound(ys.begin(), ys.end(), q.d) - ys.begin());\n\
    \            int u = (int)(std::lower_bound(ys.begin(), ys.end(), q.u) - ys.begin());\n\
    \            V sum = fw.sum(d, u);\n            if (q.is_positive) {\n       \
    \         ret[q.id] += sum;\n            } else {\n                ret[q.id] -=\
    \ sum;\n            }\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"fenwick_tree.hpp\"\n#include <algorithm>\ntemplate\
    \ <typename C, typename V>\nclass RectangleSum {\n    struct Point {\n       \
    \ C x, y;\n        V v;\n    };\n    struct Query {\n        C xl, xr, yl, yr;\n\
    \        int idx;\n    };\n    std::vector<Point> pts;\n    std::vector<Query>\
    \ qrs;\npublic:\n    RectangleSum() : pts(), qrs() {}\n    void add_point(C x,\
    \ C y, V v) {\n        pts.emplace_back(Point{x, y, v});\n    }\n    void add_query(C\
    \ xl, C xr, C yl, C yr) {\n        qrs.emplace_back(Query{xl, xr, yl, yr, (int)qrs.size()});\n\
    \    }\n    std::vector<V> solve() {\n        std::sort(pts.begin(), pts.end(),\
    \ [](const Point &p0, const Point &p1) -> bool {\n            return p0.x < p1.x;\n\
    \        });\n        struct Q {\n            C x, d, u;\n            int id;\n\
    \            bool is_positive;\n        };\n        std::vector<Q> q_;\n     \
    \   q_.reserve(2 * qrs.size());\n        for (const Query &qr : qrs) {\n     \
    \       q_.push_back(Q{qr.xl, qr.yl, qr.yr, qr.idx, false});\n            q_.push_back(Q{qr.xr,\
    \ qr.yl, qr.yr, qr.idx, true});\n        }\n        std::sort(q_.begin(), q_.end(),\
    \ [](const Q &q0, const Q &q1) -> bool {\n            return q0.x < q1.x;\n  \
    \      });\n        std::vector<C> ys;\n        ys.reserve(pts.size());\n    \
    \    for (const Point &p : pts) {\n            ys.push_back(p.y);\n        }\n\
    \        std::sort(ys.begin(), ys.end());\n        ys.erase(std::unique(ys.begin(),\
    \ ys.end()), ys.end());\n        FenwickTreeAdd<V> fw((int)ys.size());\n     \
    \   std::vector<V> ret(qrs.size(), 0);\n        typename std::vector<Point>::iterator\
    \ it = pts.begin();\n        for (const Q &q : q_) {\n            while (it !=\
    \ pts.end() && it->x < q.x) {\n                int y = (int)(std::lower_bound(ys.begin(),\
    \ ys.end(), it->y) - ys.begin());\n                fw.add(y, it->v);\n       \
    \         ++it;\n            }\n            int d = (int)(std::lower_bound(ys.begin(),\
    \ ys.end(), q.d) - ys.begin());\n            int u = (int)(std::lower_bound(ys.begin(),\
    \ ys.end(), q.u) - ys.begin());\n            V sum = fw.sum(d, u);\n         \
    \   if (q.is_positive) {\n                ret[q.id] += sum;\n            } else\
    \ {\n                ret[q.id] -= sum;\n            }\n        }\n        return\
    \ ret;\n    }\n};"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  - data_structure/operations.hpp
  isVerificationFile: false
  path: data_structure/rectangle_sum.hpp
  requiredBy: []
  timestamp: '2024-03-29 10:57:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - data_structure/test/rectangle_sum.test.cpp
documentation_of: data_structure/rectangle_sum.hpp
layout: document
redirect_from:
- /library/data_structure/rectangle_sum.hpp
- /library/data_structure/rectangle_sum.hpp.html
title: data_structure/rectangle_sum.hpp
---
