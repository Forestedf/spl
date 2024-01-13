---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/general_range_tree.hpp
    title: data_structure/general_range_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"data_structure/test/point_add_rectangle_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    #define FAST_IO\n\n#line 2 \"data_structure/fenwick_tree.hpp\"\n\n#include <cassert>\n\
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
    #line 2 \"data_structure/general_range_tree.hpp\"\n\n#line 6 \"data_structure/general_range_tree.hpp\"\
    \n\ntemplate <typename T>\nclass GRangeTree {\n    std::vector<T> xs;\n    std::vector<std::pair<T,\
    \ int>> arr;\n    std::vector<int> rngs;\n\n    static bool compare_by_first(const\
    \ std::pair<T, int> &p0,\n                                 const std::pair<T,\
    \ int> &p1) {\n        return p0.first < p1.first;\n    }\n\npublic:\n    GRangeTree(const\
    \ std::vector<std::pair<T, T>> &pts) : xs(), arr(), rngs() {\n        xs.reserve(pts.size());\n\
    \        for (const auto &[x, _y] : pts) {\n            xs.push_back(x);\n   \
    \     }\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        int xs_sz = (int)xs.size();\n        std::vector<std::vector<std::pair<T,\
    \ int>>> nodes(2 * xs_sz);\n        for (int i = 0; i < (int)pts.size(); ++i)\
    \ {\n            int xi =\n                (int)(std::lower_bound(xs.begin(),\
    \ xs.end(), pts[i].first) -\n                      xs.begin());\n            nodes[xs_sz\
    \ + xi].emplace_back(pts[i].second, i);\n        }\n        for (int i = xs_sz;\
    \ i < 2 * xs_sz; ++i) {\n            std::sort(nodes[i].begin(), nodes[i].end(),\
    \ compare_by_first);\n        }\n        for (int i = xs_sz - 1; i > 0; --i) {\n\
    \            nodes[i].reserve(nodes[2 * i].size() + nodes[2 * i + 1].size());\n\
    \            std::merge(nodes[2 * i].begin(), nodes[2 * i].end(),\n          \
    \             nodes[2 * i + 1].begin(), nodes[2 * i + 1].end(),\n            \
    \           std::back_inserter(nodes[i]), compare_by_first);\n        }\n    \
    \    int tot = 0;\n        for (int i = 1; i < 2 * xs_sz; ++i) {\n           \
    \ tot += (int)nodes[i].size();\n        }\n        arr.reserve(tot);\n       \
    \ for (int i = 1; i < 2 * xs_sz; ++i) {\n            for (auto ele : nodes[i])\
    \ {\n                arr.emplace_back(ele);\n            }\n        }\n      \
    \  rngs.resize(2 * xs_sz, 0);\n        for (int i = 1; i < 2 * xs_sz; ++i) {\n\
    \            rngs[i] = rngs[i - 1] + (int)nodes[i].size();\n        }\n    }\n\
    \n    int size() const { return (int)arr.size(); }\n    int operator[](int i)\
    \ const { return arr[i].second; }\n\n    // [xl, xr), [yl, yr)\n    std::vector<std::pair<int,\
    \ int>> rectangle(T xl, T xr, T yl, T yr) const {\n        int xli =\n       \
    \     (int)(std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin());\n      \
    \  int xri =\n            (int)(std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin());\n\
    \        std::vector<std::pair<int, int>> ret;\n        xli += (int)xs.size();\n\
    \        xri += (int)xs.size();\n        while (xli < xri) {\n            if (xli\
    \ % 2 == 1) {\n                int l = rngs[xli - 1];\n                int r =\
    \ rngs[xli];\n                ret.emplace_back(\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yl, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()),\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yr, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()));\n                ++xli;\n          \
    \  }\n            if (xri % 2 == 1) {\n                --xri;\n              \
    \  int l = rngs[xri - 1];\n                int r = rngs[xri];\n              \
    \  ret.emplace_back(\n                    (int)(std::lower_bound(arr.begin() +\
    \ l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yl, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()),\n                    (int)(std::lower_bound(arr.begin()\
    \ + l, arr.begin() + r,\n                                           std::pair<T,\
    \ int>(yr, 0),\n                                           compare_by_first) -\n\
    \                          arr.begin()));\n            }\n            xli /= 2;\n\
    \            xri /= 2;\n        }\n        return ret;\n    }\n};\n#line 1 \"\
    template/template.hpp\"\n#include <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d,\
    \ ...) d\n#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)\n#define REP3(i,\
    \ m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__,\
    \ REP3, REP2)(__VA_ARGS__)\n#define PER2(i, n) for (i32 i = (i32)(n)-1; i >= 0;\
    \ --i)\n#define PER3(i, m, n) for (i32 i = (i32)(n)-1; i >= (i32)(m); --i)\n#define\
    \ PER(...) OVERRIDE(__VA_ARGS__, PER3, PER2)(__VA_ARGS__)\n#define ALL(x) begin(x),\
    \ end(x)\n#define LEN(x) (i32)(x.size())\nusing namespace std;\nusing u32 = unsigned\
    \ int;\nusing u64 = unsigned long long;\nusing i32 = signed int;\nusing i64 =\
    \ signed long long;\nusing f64 = double;\nusing f80 = long double;\nusing pi =\
    \ pair<i32, i32>;\nusing pl = pair<i64, i64>;\ntemplate <typename T>\nusing V\
    \ = vector<T>;\ntemplate <typename T>\nusing VV = V<V<T>>;\ntemplate <typename\
    \ T>\nusing VVV = V<V<V<T>>>;\ntemplate <typename T>\nusing VVVV = V<V<V<V<T>>>>;\n\
    template <typename T>\nusing PQR = priority_queue<T, V<T>, greater<T>>;\ntemplate\
    \ <typename T>\nbool chmin(T &x, const T &y) {\n    if (x > y) {\n        x =\
    \ y;\n        return true;\n    }\n    return false;\n}\ntemplate <typename T>\n\
    bool chmax(T &x, const T &y) {\n    if (x < y) {\n        x = y;\n        return\
    \ true;\n    }\n    return false;\n}\ntemplate <typename T>\ni32 lob(const V<T>\
    \ &arr, const T &v) {\n    return (i32)(lower_bound(ALL(arr), v) - arr.begin());\n\
    }\ntemplate <typename T>\ni32 upb(const V<T> &arr, const T &v) {\n    return (i32)(upper_bound(ALL(arr),\
    \ v) - arr.begin());\n}\ntemplate <typename T>\nV<i32> argsort(const V<T> &arr)\
    \ {\n    V<i32> ret(arr.size());\n    iota(ALL(ret), 0);\n    sort(ALL(ret), [&](i32\
    \ i, i32 j) -> bool {\n        if (arr[i] == arr[j]) {\n            return i <\
    \ j;\n        } else {\n            return arr[i] < arr[j];\n        }\n    });\n\
    \    return ret;\n}\n#ifdef INT128\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n\
    #endif\n[[maybe_unused]] constexpr i32 INF = 1000000100;\n[[maybe_unused]] constexpr\
    \ i64 INF64 = 3000000000000000100;\nstruct SetUpIO {\n    SetUpIO() {\n#ifdef\
    \ FAST_IO\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n#endif\n\
    \        cout << fixed << setprecision(15);\n    }\n} set_up_io;\nvoid scan(char\
    \ &x) { cin >> x; }\nvoid scan(u32 &x) { cin >> x; }\nvoid scan(u64 &x) { cin\
    \ >> x; }\nvoid scan(i32 &x) { cin >> x; }\nvoid scan(i64 &x) { cin >> x; }\n\
    void scan(string &x) { cin >> x; }\ntemplate <typename T>\nvoid scan(V<T> &x)\
    \ {\n    for (T &ele : x) {\n        scan(ele);\n    }\n}\nvoid read() {}\ntemplate\
    \ <typename Head, typename... Tail>\nvoid read(Head &head, Tail &...tail) {\n\
    \    scan(head);\n    read(tail...);\n}\n#define CHAR(...)     \\\n    char __VA_ARGS__;\
    \ \\\n    read(__VA_ARGS__);\n#define U32(...)     \\\n    u32 __VA_ARGS__; \\\
    \n    read(__VA_ARGS__);\n#define U64(...)     \\\n    u64 __VA_ARGS__; \\\n \
    \   read(__VA_ARGS__);\n#define I32(...)     \\\n    i32 __VA_ARGS__; \\\n   \
    \ read(__VA_ARGS__);\n#define I64(...)     \\\n    i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n\
    #define STR(...)        \\\n    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n\
    #define VEC(type, name, size) \\\n    V<type> name(size);       \\\n    read(name);\n\
    #define VVEC(type, name, size1, size2)    \\\n    VV<type> name(size1, V<type>(size2));\
    \ \\\n    read(name);\n#line 7 \"data_structure/test/point_add_rectangle_sum.test.cpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    V<i32> x(n), y(n), w(n);\n\
    \    REP(i, n) { cin >> x[i] >> y[i] >> w[i]; }\n    V<tuple<i32, i32, i32, i32,\
    \ i32>> queries(q);\n    for (auto &[type, a, b, c, d] : queries) {\n        cin\
    \ >> type;\n        if (type == 0) {\n            cin >> a >> b >> c;\n      \
    \      d = 0;\n        } else {\n            cin >> a >> b >> c >> d;\n      \
    \  }\n    }\n    i32 pct = n;\n    for (const auto &[type, _a, _b, _c, _d] : queries)\
    \ {\n        if (type == 0) {\n            ++pct;\n        }\n    }\n    V<pi>\
    \ pts;\n    pts.reserve(pct);\n    REP(i, n) { pts.emplace_back(x[i], y[i]); }\n\
    \    for (const auto &[type, a, b, c, d] : queries) {\n        if (type == 0)\
    \ {\n            pts.emplace_back(a, b);\n        }\n    }\n    GRangeTree rt(pts);\n\
    \    VV<i32> upd_pct(pct - n);\n    REP(i, rt.size()) {\n        if (rt[i] >=\
    \ n) {\n            upd_pct[rt[i] - n].push_back(i);\n        }\n    }\n    FenwickTree<Add<i64>>\
    \ ft(rt.size());\n    REP(i, rt.size()) {\n        if (rt[i] < n) {\n        \
    \    ft.add(i, w[rt[i]]);\n        }\n    }\n    i32 it = 0;\n    for (const auto\
    \ &[type, a, b, c, d] : queries) {\n        if (type == 0) {\n            for\
    \ (i32 upd : upd_pct[it++]) {\n                ft.add(upd, c);\n            }\n\
    \        } else {\n            i64 ans = 0;\n            for (auto [l, r] : rt.rectangle(a,\
    \ c, b, d)) {\n                ans += ft.sum(l, r);\n            }\n         \
    \   cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#define FAST_IO\n\n#include \"../../data_structure/fenwick_tree.hpp\"\n#include\
    \ \"../../data_structure/general_range_tree.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    V<i32> x(n), y(n), w(n);\n\
    \    REP(i, n) { cin >> x[i] >> y[i] >> w[i]; }\n    V<tuple<i32, i32, i32, i32,\
    \ i32>> queries(q);\n    for (auto &[type, a, b, c, d] : queries) {\n        cin\
    \ >> type;\n        if (type == 0) {\n            cin >> a >> b >> c;\n      \
    \      d = 0;\n        } else {\n            cin >> a >> b >> c >> d;\n      \
    \  }\n    }\n    i32 pct = n;\n    for (const auto &[type, _a, _b, _c, _d] : queries)\
    \ {\n        if (type == 0) {\n            ++pct;\n        }\n    }\n    V<pi>\
    \ pts;\n    pts.reserve(pct);\n    REP(i, n) { pts.emplace_back(x[i], y[i]); }\n\
    \    for (const auto &[type, a, b, c, d] : queries) {\n        if (type == 0)\
    \ {\n            pts.emplace_back(a, b);\n        }\n    }\n    GRangeTree rt(pts);\n\
    \    VV<i32> upd_pct(pct - n);\n    REP(i, rt.size()) {\n        if (rt[i] >=\
    \ n) {\n            upd_pct[rt[i] - n].push_back(i);\n        }\n    }\n    FenwickTree<Add<i64>>\
    \ ft(rt.size());\n    REP(i, rt.size()) {\n        if (rt[i] < n) {\n        \
    \    ft.add(i, w[rt[i]]);\n        }\n    }\n    i32 it = 0;\n    for (const auto\
    \ &[type, a, b, c, d] : queries) {\n        if (type == 0) {\n            for\
    \ (i32 upd : upd_pct[it++]) {\n                ft.add(upd, c);\n            }\n\
    \        } else {\n            i64 ans = 0;\n            for (auto [l, r] : rt.rectangle(a,\
    \ c, b, d)) {\n                ans += ft.sum(l, r);\n            }\n         \
    \   cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  - data_structure/operations.hpp
  - data_structure/general_range_tree.hpp
  - template/template.hpp
  isVerificationFile: true
  path: data_structure/test/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-13 18:43:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/point_add_rectangle_sum.test.cpp
- /verify/data_structure/test/point_add_rectangle_sum.test.cpp.html
title: data_structure/test/point_add_rectangle_sum.test.cpp
---
