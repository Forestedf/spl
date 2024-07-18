---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/rectangle_sum.hpp
    title: data_structure/rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"data_structure/test/rectangle_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#define FAST_IO\n\n#line\
    \ 2 \"data_structure/fenwick_tree.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    #line 2 \"data_structure/operations.hpp\"\n\n#include <algorithm>\n#include <limits>\n\
    #include <utility>\n\ntemplate <typename T>\nstruct Add {\n    using Value = T;\n\
    \    static Value id() { return T(0); }\n    static Value op(const Value &lhs,\
    \ const Value &rhs) { return lhs + rhs; }\n    static Value inv(const Value &x)\
    \ { return -x; }\n};\n\ntemplate <typename T>\nstruct Mul {\n    using Value =\
    \ T;\n    static Value id() { return Value(1); }\n    static Value op(const Value\
    \ &lhs, const Value &rhs) { return lhs * rhs; }\n    static Value inv(const Value\
    \ &x) { return Value(1) / x; }\n};\n\ntemplate <typename T>\nstruct Min {\n  \
    \  static_assert(std::numeric_limits<T>::is_specialized);\n    using Value = T;\n\
    \    static Value id() { return std::numeric_limits<T>::max(); }\n    static Value\
    \ op(const Value &lhs, const Value &rhs) {\n        return std::min(lhs, rhs);\n\
    \    }\n};\n\ntemplate <typename T>\nstruct Max {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
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
    \ sum;\n            }\n        }\n        return ret;\n    }\n};\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i,\
    \ n) for (i32 i = 0; i < (i32)(n); ++i)\n#define REP3(i, m, n) for (i32 i = (i32)(m);\
    \ i < (i32)(n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)\n\
    #define PER2(i, n) for (i32 i = (i32)(n)-1; i >= 0; --i)\n#define PER3(i, m, n)\
    \ for (i32 i = (i32)(n)-1; i >= (i32)(m); --i)\n#define PER(...) OVERRIDE(__VA_ARGS__,\
    \ PER3, PER2)(__VA_ARGS__)\n#define ALL(x) begin(x), end(x)\n#define LEN(x) (i32)(x.size())\n\
    using namespace std;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\
    using i32 = signed int;\nusing i64 = signed long long;\nusing f64 = double;\n\
    using f80 = long double;\nusing pi = pair<i32, i32>;\nusing pl = pair<i64, i64>;\n\
    template <typename T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV =\
    \ V<V<T>>;\ntemplate <typename T>\nusing VVV = V<V<V<T>>>;\ntemplate <typename\
    \ T>\nusing VVVV = V<V<V<V<T>>>>;\ntemplate <typename T>\nusing PQR = priority_queue<T,\
    \ V<T>, greater<T>>;\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n\
    \    if (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
    }\ntemplate <typename T>\nbool chmax(T &x, const T &y) {\n    if (x < y) {\n \
    \       x = y;\n        return true;\n    }\n    return false;\n}\ntemplate <typename\
    \ T>\ni32 lob(const V<T> &arr, const T &v) {\n    return (i32)(lower_bound(ALL(arr),\
    \ v) - arr.begin());\n}\ntemplate <typename T>\ni32 upb(const V<T> &arr, const\
    \ T &v) {\n    return (i32)(upper_bound(ALL(arr), v) - arr.begin());\n}\ntemplate\
    \ <typename T>\nV<i32> argsort(const V<T> &arr) {\n    V<i32> ret(arr.size());\n\
    \    iota(ALL(ret), 0);\n    sort(ALL(ret), [&](i32 i, i32 j) -> bool {\n    \
    \    if (arr[i] == arr[j]) {\n            return i < j;\n        } else {\n  \
    \          return arr[i] < arr[j];\n        }\n    });\n    return ret;\n}\n#ifdef\
    \ INT128\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n#endif\n[[maybe_unused]]\
    \ constexpr i32 INF = 1000000100;\n[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;\n\
    struct SetUpIO {\n    SetUpIO() {\n#ifdef FAST_IO\n        ios::sync_with_stdio(false);\n\
    \        cin.tie(nullptr);\n#endif\n        cout << fixed << setprecision(15);\n\
    \    }\n} set_up_io;\nvoid scan(char &x) { cin >> x; }\nvoid scan(u32 &x) { cin\
    \ >> x; }\nvoid scan(u64 &x) { cin >> x; }\nvoid scan(i32 &x) { cin >> x; }\n\
    void scan(i64 &x) { cin >> x; }\nvoid scan(string &x) { cin >> x; }\ntemplate\
    \ <typename T>\nvoid scan(V<T> &x) {\n    for (T &ele : x) {\n        scan(ele);\n\
    \    }\n}\nvoid read() {}\ntemplate <typename Head, typename... Tail>\nvoid read(Head\
    \ &head, Tail &...tail) {\n    scan(head);\n    read(tail...);\n}\n#define CHAR(...)\
    \     \\\n    char __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U32(...) \
    \    \\\n    u32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U64(...)   \
    \  \\\n    u64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I32(...)     \\\
    \n    i32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I64(...)     \\\n \
    \   i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define STR(...)        \\\n\
    \    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define VEC(type, name, size)\
    \ \\\n    V<type> name(size);       \\\n    read(name);\n#define VVEC(type, name,\
    \ size1, size2)    \\\n    VV<type> name(size1, V<type>(size2)); \\\n    read(name);\n\
    #line 6 \"data_structure/test/rectangle_sum.test.cpp\"\n\nint main() {\n    I32(n,\
    \ q);\n    RectangleSum<i32, i64> rs;\n    for (int i = 0; i < n; ++i) {\n   \
    \     I32(x, y, w);\n        rs.add_point(x, y, w);\n    }\n    for (int i = 0;\
    \ i < q; ++i) {\n        I32(l, d, r, u);\n        rs.add_query(l, r, d, u);\n\
    \    }\n    V<i64> ret = rs.solve();\n    REP(i, q) {\n        cout << ret[i]\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#define\
    \ FAST_IO\n\n#include \"../../data_structure/rectangle_sum.hpp\"\n#include \"\
    ../../template/template.hpp\"\n\nint main() {\n    I32(n, q);\n    RectangleSum<i32,\
    \ i64> rs;\n    for (int i = 0; i < n; ++i) {\n        I32(x, y, w);\n       \
    \ rs.add_point(x, y, w);\n    }\n    for (int i = 0; i < q; ++i) {\n        I32(l,\
    \ d, r, u);\n        rs.add_query(l, r, d, u);\n    }\n    V<i64> ret = rs.solve();\n\
    \    REP(i, q) {\n        cout << ret[i] << '\\n';\n    }\n}\n"
  dependsOn:
  - data_structure/rectangle_sum.hpp
  - data_structure/fenwick_tree.hpp
  - data_structure/operations.hpp
  - template/template.hpp
  isVerificationFile: true
  path: data_structure/test/rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/rectangle_sum.test.cpp
- /verify/data_structure/test/rectangle_sum.test.cpp.html
title: data_structure/test/rectangle_sum.test.cpp
---
