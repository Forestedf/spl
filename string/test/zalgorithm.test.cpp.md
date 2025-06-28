---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"string/test/zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#define FAST_IO\n#line 2 \"string/z_algorithm.hpp\"\n#include <vector>\ntemplate\
    \ <typename Cont>\nstd::vector<int> z_algorithm(const Cont &s) {\n    std::vector<int>\
    \ z(s.size(), s.size());\n    int i = 1, j = 0;\n    while (i < (int)s.size())\
    \ {\n        while (i + j < (int)s.size() && s[i + j] == s[j]) {\n           \
    \ ++j;\n        }\n        z[i] = j;\n        if (j == 0) {\n            ++i;\n\
    \            continue;\n        }\n        int k = 1;\n        while (k < j &&\
    \ k + z[k] < j) {\n            z[i + k] = z[k];\n            ++k;\n        }\n\
    \        i += k;\n        j -= k;\n    }\n    return z;\n}\n#line 2 \"template/template.hpp\"\
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
    \  read(name);\n#line 5 \"string/test/zalgorithm.test.cpp\"\n\nvoid solve() {\n\
    \    STR(s);\n    V<i32> z = z_algorithm(s);\n    REP(i, LEN(s)) { cout << z[i]\
    \ << \" \\n\"[i + 1 == LEN(s)]; }\n}\n\nint main() {\n    i32 t = 1;\n    // cin\
    \ >> t;\n    while (t--) {\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#define FAST_IO\n\
    #include \"../../string/z_algorithm.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nvoid solve() {\n    STR(s);\n    V<i32> z = z_algorithm(s);\n    REP(i, LEN(s))\
    \ { cout << z[i] << \" \\n\"[i + 1 == LEN(s)]; }\n}\n\nint main() {\n    i32 t\
    \ = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n}\n"
  dependsOn:
  - string/z_algorithm.hpp
  - template/template.hpp
  isVerificationFile: true
  path: string/test/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2025-06-28 10:05:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: string/test/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/string/test/zalgorithm.test.cpp
- /verify/string/test/zalgorithm.test.cpp.html
title: string/test/zalgorithm.test.cpp
---
