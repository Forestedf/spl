---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/cartesian_tree.hpp
    title: data_structure/cartesian_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"data_structure/test/cartesian_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#define FAST_IO\n\n#line\
    \ 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#define OVERRIDE(a, b,\
    \ c, d, ...) d\n#define REP2(i, n) for (i32 i = 0; i < (i32)(n); ++i)\n#define\
    \ REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)\n#define REP(...) OVERRIDE(__VA_ARGS__,\
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
    \ \\\n    read(name);\n#line 2 \"data_structure/cartesian_tree.hpp\"\n\n#line\
    \ 4 \"data_structure/cartesian_tree.hpp\"\n\ntemplate <typename T, typename Compare\
    \ = std::less<T>>\nstd::vector<int> cartesian_tree(const std::vector<T> &a, Compare\
    \ comp = Compare()) {\n    std::vector<int> stc;\n    std::vector<int> par(a.size(),\
    \ -1);\n    for (int i = 0; i < a.size(); ++i) {\n        while (stc.size() >=\
    \ 2 && comp(a[i], a[stc.back()])) {\n            if (comp(a[i], a[stc[stc.size()\
    \ - 2]])) {\n                par[stc.back()] = stc[stc.size() - 2];\n        \
    \    } else {\n                par[stc.back()] = i;\n            }\n         \
    \   stc.pop_back();\n        }\n        if (stc.size() == 1 && comp(a[i], a[stc.back()]))\
    \ {\n            par[stc.back()] = i;\n            stc.pop_back();\n        }\n\
    \        stc.push_back(i);\n    }\n    while (stc.size() >= 2) {\n        par[stc.back()]\
    \ = stc[stc.size() - 2];\n        stc.pop_back();\n    }\n    return par;\n}\n\
    #line 6 \"data_structure/test/cartesian_tree.test.cpp\"\n\nint main() {\n    i32\
    \ n;\n    cin >> n;\n    V<i32> a(n);\n    REP(i, n) {\n        cin >> a[i];\n\
    \    }\n    V<i32> p = cartesian_tree(a);\n    REP(i, n) {\n        cout << (p[i]\
    \ == -1 ? i : p[i]) << \" \\n\"[i + 1 == n];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n#define\
    \ FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../data_structure/cartesian_tree.hpp\"\
    \n\nint main() {\n    i32 n;\n    cin >> n;\n    V<i32> a(n);\n    REP(i, n) {\n\
    \        cin >> a[i];\n    }\n    V<i32> p = cartesian_tree(a);\n    REP(i, n)\
    \ {\n        cout << (p[i] == -1 ? i : p[i]) << \" \\n\"[i + 1 == n];\n    }\n\
    }"
  dependsOn:
  - template/template.hpp
  - data_structure/cartesian_tree.hpp
  isVerificationFile: true
  path: data_structure/test/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-13 18:43:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/cartesian_tree.test.cpp
- /verify/data_structure/test/cartesian_tree.test.cpp.html
title: data_structure/test/cartesian_tree.test.cpp
---
