---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/binary_gcd.hpp
    title: number_theory/binary_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: template/random.hpp
    title: template/random.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"number_theory/test/binary_gcd_stress.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#line 2 \"template/template.hpp\"\n#include\
    \ <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i, n) for\
    \ (i32 i = 0; i < (i32)(n); ++i)\n#define REP3(i, m, n) for (i32 i = (i32)(m);\
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
    #line 4 \"template/random.hpp\"\n\n#if defined(LOCAL) || defined(FIX_SEED)\nstd::mt19937_64\
    \ mt(123456789);\n#else\nstd::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    #endif\n\ntemplate <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 2 \"number_theory/binary_gcd.hpp\"\n\nunsigned long long\
    \ binary_gcd(unsigned long long x, unsigned long long y) {\n    if (x == 0) {\n\
    \        return y;\n    }\n    if (y == 0) {\n        return x;\n    }\n    int\
    \ a = __builtin_ctz(x);\n    int b = __builtin_ctz(y);\n    x >>= a;\n    y >>=\
    \ b;\n    while (x != y) {\n        int m = __builtin_ctz(x - y);\n        if\
    \ (x > y) {\n            x = (x - y) >> m;\n        } else {\n            y =\
    \ (y - x) >> m;\n        }\n    }\n    return x << (a < b ? a : b);\n}\n#line\
    \ 8 \"number_theory/test/binary_gcd_stress.test.cpp\"\n\nvoid test() {\n    constexpr\
    \ int ITER = 1'000'000;\n    for (int t = 0; t < ITER; ++t) {\n        u64 a =\
    \ mt();\n        u64 b = mt();\n        assert(gcd(a, b) == binary_gcd(a, b));\n\
    \    }\n    constexpr int RANGE = 1000;\n    for (int i = 0; i < RANGE; ++i) {\n\
    \        for (int j = 0; j < RANGE; ++j) {\n            assert(gcd(i, j) == binary_gcd(i,\
    \ j));\n        }\n    }\n}\n\nint main() {\n    test();\n    cout << \"Hello\
    \ World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#include \"../../template/template.hpp\"\
    \n#include \"../../template/random.hpp\"\n#include \"../../number_theory/binary_gcd.hpp\"\
    \n\nvoid test() {\n    constexpr int ITER = 1'000'000;\n    for (int t = 0; t\
    \ < ITER; ++t) {\n        u64 a = mt();\n        u64 b = mt();\n        assert(gcd(a,\
    \ b) == binary_gcd(a, b));\n    }\n    constexpr int RANGE = 1000;\n    for (int\
    \ i = 0; i < RANGE; ++i) {\n        for (int j = 0; j < RANGE; ++j) {\n      \
    \      assert(gcd(i, j) == binary_gcd(i, j));\n        }\n    }\n}\n\nint main()\
    \ {\n    test();\n    cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - template/template.hpp
  - template/random.hpp
  - number_theory/binary_gcd.hpp
  isVerificationFile: true
  path: number_theory/test/binary_gcd_stress.test.cpp
  requiredBy: []
  timestamp: '2025-05-31 22:12:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number_theory/test/binary_gcd_stress.test.cpp
layout: document
redirect_from:
- /verify/number_theory/test/binary_gcd_stress.test.cpp
- /verify/number_theory/test/binary_gcd_stress.test.cpp.html
title: number_theory/test/binary_gcd_stress.test.cpp
---
