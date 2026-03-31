---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/range_tree.hpp
    title: data_structure/range_tree.hpp
  - icon: ':question:'
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
  bundledCode: "#line 1 \"data_structure/test/rectangle_sum_range_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#define FAST_IO\n\
    \n#line 2 \"data_structure/operations.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n#include <utility>\n\ntemplate <typename T>\nstruct Add {\n    using\
    \ Value = T;\n    static Value id() { return T(0); }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) { return lhs + rhs; }\n    static Value inv(const\
    \ Value &x) { return -x; }\n};\n\ntemplate <typename T>\nstruct Mul {\n    using\
    \ Value = T;\n    static Value id() { return Value(1); }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) { return lhs * rhs; }\n    static Value inv(const\
    \ Value &x) { return Value(1) / x; }\n};\n\ntemplate <typename T>\nstruct Min\
    \ {\n    static_assert(std::numeric_limits<T>::is_specialized);\n    using Value\
    \ = T;\n    static Value id() { return std::numeric_limits<T>::max(); }\n    static\
    \ Value op(const Value &lhs, const Value &rhs) {\n        return std::min(lhs,\
    \ rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Max {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
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
    };\n#line 2 \"data_structure/range_tree.hpp\"\n\n#line 4 \"data_structure/range_tree.hpp\"\
    \n#include <vector>\n#include <tuple>\n\ntemplate <typename Coordinate, typename\
    \ CommutativeGroup>\nclass RangeTree {\npublic:\n    using Value = typename CommutativeGroup::Value;\n\
    \nprivate:\n    struct Node {\n        std::vector<Coordinate> ys;\n        std::vector<Value>\
    \ cum;\n\n        Value sum(Coordinate yl, Coordinate yr) const {\n          \
    \  int yli =\n                (int)(std::lower_bound(ys.begin(), ys.end(), yl)\
    \ - ys.begin());\n            int yri =\n                (int)(std::lower_bound(ys.begin(),\
    \ ys.end(), yr) - ys.begin());\n            return CommutativeGroup::op(CommutativeGroup::inv(cum[yli]),\n\
    \                                        cum[yri]);\n        }\n    };\n\n   \
    \ static void dedup(std::vector<Coordinate> &xs) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \    }\n    static int index(const std::vector<Coordinate> &xs, int x) {\n   \
    \     return (int)(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin());\n\
    \    }\n\n    std::vector<Node> nodes;\n    std::vector<Coordinate> xs;\n\npublic:\n\
    \    RangeTree(const std::vector<std::tuple<Coordinate, Coordinate, Value>> &pts)\n\
    \        : nodes(), xs() {\n        xs.reserve(pts.size());\n        for (const\
    \ auto &[x, _y, _w] : pts) {\n            xs.push_back(x);\n        }\n      \
    \  dedup(xs);\n        nodes.resize(xs.size());\n        for (const auto &[x,\
    \ y, _w] : pts) {\n            int xi = index(xs, x);\n            for (; xi <\
    \ (int)xs.size(); xi |= xi + 1) {\n                nodes[xi].ys.push_back(y);\n\
    \            }\n        }\n        for (Node &node : nodes) {\n            dedup(node.ys);\n\
    \            node.cum.resize(node.ys.size() + 1, CommutativeGroup::id());\n  \
    \      }\n        for (const auto &[x, y, w] : pts) {\n            int xi = index(xs,\
    \ x);\n            for (; xi < (int)xs.size(); xi |= xi + 1) {\n             \
    \   int yi = index(nodes[xi].ys, y);\n                nodes[xi].cum[yi + 1] =\n\
    \                    CommutativeGroup::op(nodes[xi].cum[yi + 1], w);\n       \
    \     }\n        }\n        for (Node &node : nodes) {\n            for (int i\
    \ = 1; i < (int)node.cum.size(); ++i) {\n                node.cum[i] =\n     \
    \               CommutativeGroup::op(node.cum[i - 1], node.cum[i]);\n        \
    \    }\n        }\n    }\n\n    Value sum(Coordinate xr, Coordinate yl, Coordinate\
    \ yr) const {\n        int xri = index(xs, xr);\n        Value s = CommutativeGroup::id();\n\
    \        for (; xri > 0; xri &= xri - 1) {\n            s = CommutativeGroup::op(s,\
    \ nodes[xri - 1].sum(yl, yr));\n        }\n        return s;\n    }\n\n    Value\
    \ sum(Coordinate xl, Coordinate xr, Coordinate yl,\n              Coordinate yr)\
    \ const {\n        Value l = sum(xl, yl, yr), r = sum(xr, yl, yr);\n        return\
    \ CommutativeGroup::op(r, CommutativeGroup::inv(l));\n    }\n};\n#line 2 \"template/template.hpp\"\
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
    void scan(i64 &x) { cin >> x; }\nvoid scan(f64 &x) { cin >> x; }\nvoid scan(string\
    \ &x) { cin >> x; }\ntemplate <typename T>\nvoid scan(V<T> &x) {\n    for (T &ele\
    \ : x) {\n        scan(ele);\n    }\n}\nvoid read() {}\ntemplate <typename Head,\
    \ typename... Tail>\nvoid read(Head &head, Tail &...tail) {\n    scan(head);\n\
    \    read(tail...);\n}\n#define CHAR(...)     \\\n    char __VA_ARGS__; \\\n \
    \   read(__VA_ARGS__);\n#define U32(...)     \\\n    u32 __VA_ARGS__; \\\n   \
    \ read(__VA_ARGS__);\n#define U64(...)     \\\n    u64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n\
    #define I32(...)     \\\n    i32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define\
    \ I64(...)     \\\n    i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define F64(...)\
    \     \\\n    f64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define STR(...)  \
    \      \\\n    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define VEC(type,\
    \ name, size) \\\n    V<type> name(size);       \\\n    read(name);\n#define VVEC(type,\
    \ name, size1, size2)    \\\n    VV<type> name(size1, V<type>(size2)); \\\n  \
    \  read(name);\n#line 7 \"data_structure/test/rectangle_sum_range_tree.test.cpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    V<tuple<i32, i32, i64>>\
    \ pts(n);\n    for (auto &[x, y, w] : pts) {\n        cin >> x >> y >> w;\n  \
    \  }\n    RangeTree<i32, Add<i64>> range_tree(pts);\n    REP(qi, q) {\n      \
    \  i32 l, d, r, u;\n        cin >> l >> d >> r >> u;\n        cout << range_tree.sum(l,\
    \ r, d, u) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#define\
    \ FAST_IO\n\n#include \"../../data_structure/operations.hpp\"\n#include \"../../data_structure/range_tree.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nint main() {\n    i32 n, q;\n  \
    \  cin >> n >> q;\n    V<tuple<i32, i32, i64>> pts(n);\n    for (auto &[x, y,\
    \ w] : pts) {\n        cin >> x >> y >> w;\n    }\n    RangeTree<i32, Add<i64>>\
    \ range_tree(pts);\n    REP(qi, q) {\n        i32 l, d, r, u;\n        cin >>\
    \ l >> d >> r >> u;\n        cout << range_tree.sum(l, r, d, u) << '\\n';\n  \
    \  }\n}\n"
  dependsOn:
  - data_structure/operations.hpp
  - data_structure/range_tree.hpp
  - template/template.hpp
  isVerificationFile: true
  path: data_structure/test/rectangle_sum_range_tree.test.cpp
  requiredBy: []
  timestamp: '2025-06-28 10:05:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/rectangle_sum_range_tree.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/rectangle_sum_range_tree.test.cpp
- /verify/data_structure/test/rectangle_sum_range_tree.test.cpp.html
title: data_structure/test/rectangle_sum_range_tree.test.cpp
---
