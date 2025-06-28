---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/montgomery_64.hpp
    title: number_theory/montgomery_64.hpp
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
  bundledCode: "#line 1 \"number_theory/test/montgomery_64_stress.test.cpp\"\n#define\
    \ PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#line 2 \"number_theory/montgomery_64.hpp\"\
    \n#include <cassert>\n\n// mod: odd, < 2^{63}\ntemplate <int id>\nstruct MontgomeryModInt64\
    \ {\n    using u64 = unsigned long long;\n    using u128 = __uint128_t;\n\n  \
    \  static u64 inv_64(u64 n) {\n        u64 r = n;\n        for (int i = 0; i <\
    \ 5; ++i) {\n            r *= 2 - n * r;\n        }\n        return r;\n    }\n\
    \n    static u64 mod, neg_inv, sq;\n    static void set_mod(u64 m) {\n       \
    \ assert(m % 2 == 1 && m < (1ULL << 63));\n        mod = m;\n        neg_inv =\
    \ -inv_64(m);\n        sq = -u128(mod) % mod;\n    }\n    static u64 get_mod()\
    \ { return mod; }\n\n    static u64 reduce(u128 xr) {\n        u64 ret = (xr +\
    \ u128(u64(xr) * neg_inv) * mod) >> 64;\n        if (ret >= mod) {\n         \
    \   ret -= mod;\n        }\n        return ret;\n    }\n\n    using M = MontgomeryModInt64<id>;\n\
    \n    u64 x;\n    MontgomeryModInt64() : x(0) {}\n    MontgomeryModInt64(u64 _x)\
    \ : x(reduce(u128(_x) * sq)) {}\n\n    u64 val() const { return reduce(u128(x));\
    \ }\n\n    M &operator+=(M rhs) {\n        if ((x += rhs.x) >= mod) {\n      \
    \      x -= mod;\n        }\n        return *this;\n    }\n    M &operator-=(M\
    \ rhs) {\n        if ((x -= rhs.x) >= mod) {\n            x += mod;\n        }\n\
    \        return *this;\n    }\n    M &operator*=(M rhs) {\n        x = reduce(u128(x)\
    \ * rhs.x);\n        return *this;\n    }\n    M operator+(M rhs) const { return\
    \ M(*this) += rhs; }\n    M operator-(M rhs) const { return M(*this) -= rhs; }\n\
    \    M operator*(M rhs) const { return M(*this) *= rhs; }\n\n    M pow(u64 t)\
    \ const {\n        M ret(1);\n        M self = *this;\n        while (t) {\n \
    \           if (t & 1) {\n                ret *= self;\n            }\n      \
    \      self *= self;\n            t >>= 1;\n        }\n        return ret;\n \
    \   }\n    M inv() const {\n        assert(x);\n        return this->pow(mod -\
    \ 2);\n    }\n\n    M &operator/=(M rhs) {\n        *this /= rhs.inv();\n    \
    \    return *this;\n    }\n    M operator/(M rhs) const { return M(*this) /= rhs;\
    \ }\n};\n\ntemplate <int id> unsigned long long MontgomeryModInt64<id>::mod =\
    \ 1;\ntemplate <int id> unsigned long long MontgomeryModInt64<id>::neg_inv = 1;\n\
    template <int id> unsigned long long MontgomeryModInt64<id>::sq = 1;\n#line 2\
    \ \"template/random.hpp\"\n#include <chrono>\n#include <random>\n\n#if defined(LOCAL)\
    \ || defined(FIX_SEED)\nstd::mt19937_64 mt(123456789);\n#else\nstd::mt19937_64\
    \ mt(std::chrono::steady_clock::now().time_since_epoch().count());\n#endif\n\n\
    template <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
    #define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i, n) for (i32 i = 0; i < (i32)(n);\
    \ ++i)\n#define REP3(i, m, n) for (i32 i = (i32)(m); i < (i32)(n); ++i)\n#define\
    \ REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)\n#define PER2(i, n)\
    \ for (i32 i = (i32)(n)-1; i >= 0; --i)\n#define PER3(i, m, n) for (i32 i = (i32)(n)-1;\
    \ i >= (i32)(m); --i)\n#define PER(...) OVERRIDE(__VA_ARGS__, PER3, PER2)(__VA_ARGS__)\n\
    #define ALL(x) begin(x), end(x)\n#define LEN(x) (i32)(x.size())\nusing namespace\
    \ std;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i32\
    \ = signed int;\nusing i64 = signed long long;\nusing f64 = double;\nusing f80\
    \ = long double;\nusing pi = pair<i32, i32>;\nusing pl = pair<i64, i64>;\ntemplate\
    \ <typename T>\nusing V = vector<T>;\ntemplate <typename T>\nusing VV = V<V<T>>;\n\
    template <typename T>\nusing VVV = V<V<V<T>>>;\ntemplate <typename T>\nusing VVVV\
    \ = V<V<V<V<T>>>>;\ntemplate <typename T>\nusing PQR = priority_queue<T, V<T>,\
    \ greater<T>>;\ntemplate <typename T>\nbool chmin(T &x, const T &y) {\n    if\
    \ (x > y) {\n        x = y;\n        return true;\n    }\n    return false;\n\
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
    \  read(name);\n#line 9 \"number_theory/test/montgomery_64_stress.test.cpp\"\n\
    \nusing M = MontgomeryModInt64<0>;\n\nu64 add(u64 a, u64 b, u64 m) { return (a\
    \ + b) % m; }\nu64 sub(u64 a, u64 b, u64 m) { return (m + a - b) % m; }\nu64 mul(u64\
    \ a, u64 b, u64 m) { return __uint128_t(a) * b % m; }\n\nvoid test_small_mod(i32\
    \ m) {\n    M::set_mod(m);\n    REP(i, m) REP(j, m) {\n        M x(i), y(j);\n\
    \        assert((x + y).val() == add(i, j, m));\n        assert((x - y).val()\
    \ == sub(i, j, m));\n        assert((x * y).val() == mul(i, j, m));\n    }\n}\n\
    \nvoid test_large_mod(u64 m) {\n    M::set_mod(m);\n\n    constexpr int ITER =\
    \ 1'000'000;\n\n    for (int i = 0; i < ITER; ++i) {\n        u64 x = uniform(m);\n\
    \        u64 y = uniform(m);\n        M x_(x), y_(y);\n        assert((x_ + y_).val()\
    \ == add(x, y, m));\n        assert((x_ - y_).val() == sub(x, y, m));\n      \
    \  assert((x_ * y_).val() == mul(x, y, m));\n    }\n}\n\nvoid test() {\n    for\
    \ (i32 m = 3; m <= 99; m += 2) {\n        test_small_mod(m);\n    }\n\n    for\
    \ (int i = 0; i < 10; ++i) {\n        u64 m = uniform<u64>(3, 1ULL << 63);\n \
    \       while (m % 2 == 0) {\n            m = uniform<u64>(3, 1ULL << 63);\n \
    \       }\n        test_large_mod(m);\n    }\n\n    test_large_mod((1ULL << 63)\
    \ - 1);\n}\n\nint main() {\n    test();\n    cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \\\n    \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#include \"../../number_theory/montgomery_64.hpp\"\
    \n#include \"../../template/random.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nusing M = MontgomeryModInt64<0>;\n\nu64 add(u64 a, u64 b, u64 m) { return\
    \ (a + b) % m; }\nu64 sub(u64 a, u64 b, u64 m) { return (m + a - b) % m; }\nu64\
    \ mul(u64 a, u64 b, u64 m) { return __uint128_t(a) * b % m; }\n\nvoid test_small_mod(i32\
    \ m) {\n    M::set_mod(m);\n    REP(i, m) REP(j, m) {\n        M x(i), y(j);\n\
    \        assert((x + y).val() == add(i, j, m));\n        assert((x - y).val()\
    \ == sub(i, j, m));\n        assert((x * y).val() == mul(i, j, m));\n    }\n}\n\
    \nvoid test_large_mod(u64 m) {\n    M::set_mod(m);\n\n    constexpr int ITER =\
    \ 1'000'000;\n\n    for (int i = 0; i < ITER; ++i) {\n        u64 x = uniform(m);\n\
    \        u64 y = uniform(m);\n        M x_(x), y_(y);\n        assert((x_ + y_).val()\
    \ == add(x, y, m));\n        assert((x_ - y_).val() == sub(x, y, m));\n      \
    \  assert((x_ * y_).val() == mul(x, y, m));\n    }\n}\n\nvoid test() {\n    for\
    \ (i32 m = 3; m <= 99; m += 2) {\n        test_small_mod(m);\n    }\n\n    for\
    \ (int i = 0; i < 10; ++i) {\n        u64 m = uniform<u64>(3, 1ULL << 63);\n \
    \       while (m % 2 == 0) {\n            m = uniform<u64>(3, 1ULL << 63);\n \
    \       }\n        test_large_mod(m);\n    }\n\n    test_large_mod((1ULL << 63)\
    \ - 1);\n}\n\nint main() {\n    test();\n    cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - number_theory/montgomery_64.hpp
  - template/random.hpp
  - template/template.hpp
  isVerificationFile: true
  path: number_theory/test/montgomery_64_stress.test.cpp
  requiredBy: []
  timestamp: '2025-06-28 10:05:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number_theory/test/montgomery_64_stress.test.cpp
layout: document
redirect_from:
- /verify/number_theory/test/montgomery_64_stress.test.cpp
- /verify/number_theory/test/montgomery_64_stress.test.cpp.html
title: number_theory/test/montgomery_64_stress.test.cpp
---
