---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: data_structure/union_find.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"data_structure/test/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n#define FAST_IO\n\n#line 2 \"\
    data_structure/union_find.hpp\"\n\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nclass UnionFind {\n    std::vector<int> par;\n\n    int _root(int\
    \ v) {\n        if (par[v] < 0) {\n            return v;\n        } else {\n \
    \           return par[v] = _root(par[v]);\n        }\n    }\n\npublic:\n    UnionFind(int\
    \ n) : par(n, -1) {}\n\n    int root(int v) {\n        assert(v >= 0 && v < (int)par.size());\n\
    \        return _root(v);\n    }\n\n    int size(int v) {\n        assert(v >=\
    \ 0 && v < (int)par.size());\n        return -par[_root(v)];\n    }\n\n    bool\
    \ unite(int u, int v) {\n        assert(u >= 0 && u < (int)par.size() && v >=\
    \ 0 && v < (int)par.size());\n        u = _root(u);\n        v = _root(v);\n \
    \       if (u == v) {\n            return false;\n        }\n        if (par[u]\
    \ < par[v]) {\n            std::swap(u, v);\n        }\n        par[v] += par[u];\n\
    \        par[u] = v;\n        return true;\n    }\n\n    bool same(int u, int\
    \ v) {\n        assert(u >= 0 && u < (int)par.size() && v >= 0 && v < (int)par.size());\n\
    \        return _root(u) == _root(v);\n    }\n};\n#line 1 \"template/template.hpp\"\
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
    \       \\\n    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U32(...)\
    \     \\\n    u32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define U64(...)  \
    \   \\\n    u64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I32(...)    \
    \ \\\n    i32 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define I64(...)     \\\
    \n    i64 __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define STR(...)        \\\n\
    \    string __VA_ARGS__; \\\n    read(__VA_ARGS__);\n#define VEC(type, name, size)\
    \ \\\n    V<type> name(size);       \\\n    read(name);\n#define VVEC(type, name,\
    \ size1, size2)    \\\n    VV<type> name(size1, V<type>(size2)); \\\n    read(name);\n\
    #line 6 \"data_structure/test/unionfind.test.cpp\"\n\nint main() {\n    i32 n,\
    \ q;\n    cin >> n >> q;\n    UnionFind uf(n);\n    REP(qi, q) {\n        i32\
    \ t;\n        cin >> t;\n        if (t == 0) {\n            i32 u, v;\n      \
    \      cin >> u >> v;\n            uf.unite(u, v);\n        } else {\n       \
    \     i32 u, v;\n            cin >> u >> v;\n            cout << uf.same(u, v)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#define FAST_IO\n\
    \n#include \"../../data_structure/union_find.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n  \
    \  REP(qi, q) {\n        i32 t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          i32 u, v;\n            cin >> u >> v;\n            uf.unite(u, v);\n\
    \        } else {\n            i32 u, v;\n            cin >> u >> v;\n       \
    \     cout << uf.same(u, v) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - data_structure/union_find.hpp
  - template/template.hpp
  isVerificationFile: true
  path: data_structure/test/unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-12-26 16:56:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/unionfind.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/unionfind.test.cpp
- /verify/data_structure/test/unionfind.test.cpp.html
title: data_structure/test/unionfind.test.cpp
---
