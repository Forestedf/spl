---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/primality.hpp
    title: number_theory/primality.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"number_theory/test/primality_test.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/primality_test\"\n#define FAST_IO\n#line 2\
    \ \"number_theory/primality.hpp\"\n\nnamespace primality {\n\nusing u64 = unsigned\
    \ long long;\nusing u128 = __uint128_t;\n\nu64 inv_64(u64 n) {\n    u64 r = n;\n\
    \    for (int i = 0; i < 5; ++i) {\n        r *= 2 - n * r;\n    }\n    return\
    \ r;\n}\n\n// n: odd, < 2^{62}\nstruct Montgomery64 {\n    u64 n, mni, p;\n  \
    \  Montgomery64(u64 n) : n(n), mni(-inv_64(n)), p(-1ULL % n + 1) {}\n    u64 mulmr(u64\
    \ xr, u64 yr) const {\n        u128 z = (u128)xr * yr;\n        u64 ret = (z +\
    \ (u128)((u64)z * mni) * n) >> 64;\n        if (ret >= n) {\n            ret -=\
    \ n;\n        }\n        return ret;\n    }\n    u64 mr(u64 xr) const {\n    \
    \    u64 ret = (xr + (u128)(xr * mni) * n) >> 64;\n        if (ret >= n) {\n \
    \           ret -= n;\n        }\n        return ret;\n    }\n    u64 pow(u64\
    \ xr, u64 t) const {\n        u64 ret = p;\n        while (t) {\n            if\
    \ (t & 1) {\n                ret = mulmr(ret, xr);\n            }\n          \
    \  xr = mulmr(xr, xr);\n            t >>= 1;\n        }\n        return ret;\n\
    \    }\n};\n\nbool is_prime(u64 n) {\n    if (n == 2) {\n        return true;\n\
    \    }\n    if (n == 1 || n % 2 == 0) {\n        return false;\n    }\n    u64\
    \ s = __builtin_ctzll(n - 1);\n    u64 d = (n - 1) >> s;\n    u64 base[] = {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022};\n    Montgomery64 mont(n);\n\
    \    u64 fl = n - mont.p;\n    for (u64 b : base) {\n        b = mont.mr(b);\n\
    \        if (!b) {\n            continue;\n        }\n        u64 t = mont.pow(b,\
    \ d);\n        if (t == mont.p) {\n            continue;\n        }\n        u64\
    \ i = 0;\n        for (; i < s; ++i) {\n            if (t == fl) {\n         \
    \       break;\n            }\n            t = mont.mulmr(t, t);\n        }\n\
    \        if (i == s) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n\n}  // namespace primality\n\nbool is_prime(unsigned long long n)\
    \ {\n    return primality::is_prime(n);\n}\n#line 2 \"template/template.hpp\"\n\
    #include <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i,\
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
    \  read(name);\n#line 5 \"number_theory/test/primality_test.test.cpp\"\n\nvoid\
    \ solve() {\n    I32(q);\n    REP(qi, q) {\n        U64(x);\n        cout << (is_prime(x)\
    \ ? \"Yes\\n\" : \"No\\n\");\n    }\n}\n\nint main() {\n    i32 t = 1;\n    //\
    \ cin >> t;\n    while (t--) {\n        solve();\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n#define\
    \ FAST_IO\n#include \"../../number_theory/primality.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nvoid solve() {\n    I32(q);\n    REP(qi, q) {\n        U64(x);\n        cout\
    \ << (is_prime(x) ? \"Yes\\n\" : \"No\\n\");\n    }\n}\n\nint main() {\n    i32\
    \ t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n}"
  dependsOn:
  - number_theory/primality.hpp
  - template/template.hpp
  isVerificationFile: true
  path: number_theory/test/primality_test.test.cpp
  requiredBy: []
  timestamp: '2025-06-28 10:05:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number_theory/test/primality_test.test.cpp
layout: document
redirect_from:
- /verify/number_theory/test/primality_test.test.cpp
- /verify/number_theory/test/primality_test.test.cpp.html
title: number_theory/test/primality_test.test.cpp
---
