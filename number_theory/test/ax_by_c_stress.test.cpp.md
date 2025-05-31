---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/ax_by_c.hpp
    title: number_theory/ax_by_c.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
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
  bundledCode: "#line 1 \"number_theory/test/ax_by_c_stress.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n#define\
    \ FAST_IO\n#define FIX_SEED\n\n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
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
    \ n - 1)(mt);\n}\n#line 2 \"number_theory/ax_by_c.hpp\"\n\n#line 2 \"number_theory/utils.hpp\"\
    \n\n#line 4 \"number_theory/utils.hpp\"\n\nconstexpr bool is_prime(unsigned n)\
    \ {\n    if (n == 0 || n == 1) {\n        return false;\n    }\n    for (unsigned\
    \ i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned\
    \ x, unsigned y, unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y\
    \ != 0) {\n        if (y & 1) {\n            ret = (unsigned)((unsigned long long)ret\
    \ * self % mod);\n        }\n        self = (unsigned)((unsigned long long)self\
    \ * self % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned\
    \ mod>\nconstexpr unsigned primitive_root() {\n    static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n    if (mod == 2) {\n        return 1;\n\
    \    }\n\n    unsigned primes[32] = {};\n    int it = 0;\n    {\n        unsigned\
    \ m = mod - 1;\n        for (unsigned i = 2; i * i <= m; ++i) {\n            if\
    \ (m % i == 0) {\n                primes[it++] = i;\n                while (m\
    \ % i == 0) {\n                    m /= i;\n                }\n            }\n\
    \        }\n        if (m != 1) {\n            primes[it++] = m;\n        }\n\
    \    }\n    for (unsigned i = 2; i < mod; ++i) {\n        bool ok = true;\n  \
    \      for (int j = 0; j < it; ++j) {\n            if (mod_pow(i, (mod - 1) /\
    \ primes[j], mod) == 1) {\n                ok = false;\n                break;\n\
    \            }\n        }\n        if (ok) return i;\n    }\n    return 0;\n}\n\
    \n// y >= 1\ntemplate <typename T>\nconstexpr T safe_mod(T x, T y) {\n    x %=\
    \ y;\n    if (x < 0) {\n        x += y;\n    }\n    return x;\n}\n\n// y != 0\n\
    template <typename T>\nconstexpr T floor_div(T x, T y) {\n    if (y < 0) {\n \
    \       x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return x\
    \ / y;\n    } else {\n        return -((-x + y - 1) / y);\n    }\n}\n\n// y !=\
    \ 0\ntemplate <typename T>\nconstexpr T ceil_div(T x, T y) {\n    if (y < 0) {\n\
    \        x *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return\
    \ (x + y - 1) / y;\n    } else {\n        return -(-x / y);\n    }\n}\n\n// b\
    \ >= 1\n// returns (g, x) s.t. g = gcd(a, b), a * x = g (mod b), 0 <= x < b /\
    \ g\n// from ACL\ntemplate <typename T>\nstd::pair<T, T> extgcd(T a, T b) {\n\
    \    a = safe_mod(a, b);\n    T s = b, t = a, m0 = 0, m1 = 1;\n    while (t) {\n\
    \        T u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        std::swap(s,\
    \ t);\n        std::swap(m0, m1);\n    }\n    if (m0 < 0) {\n        m0 += b /\
    \ s;\n    }\n    return std::pair<T, T>(s, m0);\n}\n\n// b >= 1\n// returns (g,\
    \ x, y) s.t. g = gcd(a, b), a * x + b * y = g, 0 <= x < b / g, |y| < max(2, |a|\
    \ / g)\ntemplate <typename T>\nstd::tuple<T, T, T> extgcd2(T a, T b) {\n    T\
    \ _a = safe_mod(a, b);\n    T quot = (a - _a) / b;\n    T x00 = 0, x01 = 1, y0\
    \ = b;\n    T x10 = 1, x11 = -quot, y1 = _a;\n    while (y1) {\n        T u =\
    \ y0 / y1;\n        x00 -= u * x10;\n        x01 -= u * x11;\n        y0 -= u\
    \ * y1;\n        std::swap(x00, x10);\n        std::swap(x01, x11);\n        std::swap(y0,\
    \ y1);\n    }\n    if (x00 < 0) {\n        x00 += b / y0;\n        x01 -= a /\
    \ y0;\n    }\n    return std::tuple<T, T, T>(y0, x00, x01);\n}\n\n// gcd(x, m)\
    \ == 1\ntemplate <typename T>\nT inv_mod(T x, T m) {\n    return extgcd(x, m).second;\n\
    }\n#line 4 \"number_theory/ax_by_c.hpp\"\n#include <optional>\n\n// solve a *\
    \ x + b * y = c\n// |x| <= |b * c|, |y| <= |a * c| (|a|, |b|, |c| > 0)\ntemplate\
    \ <typename T>\nstd::optional<std::pair<T, T>> ax_by_c(T a, T b, T c) {\n    if\
    \ (c == 0) {\n        return std::pair<T, T>(0, 0);\n    }\n    if (a == 0 &&\
    \ b == 0) {\n        return std::nullopt;\n    }\n    if (a == 0) {\n        if\
    \ (c % b) {\n            return std::nullopt;\n        }\n        return std::pair<T,\
    \ T>(0, c / b);\n    }\n    if (b == 0) {\n        if (c % a) {\n            return\
    \ std::nullopt;\n        }\n        return std::pair<T, T>(c / a, 0);\n    }\n\
    \    if (b < 0) {\n        a = -a;\n        b = -b;\n        c = -c;\n    }\n\
    \    auto [g, x, y] = extgcd2(a, b);\n    if (c % g) {\n        return std::nullopt;\n\
    \    }\n    T mult = c / g;\n    x *= mult;\n    y *= mult;\n    return std::pair<T,\
    \ T>(x, y);\n}\n#line 8 \"number_theory/test/ax_by_c_stress.test.cpp\"\n\nvoid\
    \ test() {\n    constexpr int ITER = 1'000'000;\n    for (int t = 0; t < ITER;\
    \ ++t) {\n        i64 a = uniform(-1'000'000, 1'000'000);\n        i64 b = uniform(-1'000'000,\
    \ 1'000'000);\n        i64 c = uniform(-1'000'000, 1'000'000);\n        optional<pair<i64,\
    \ i64>> ret = ax_by_c(a, b, c);\n        if (ret.has_value()) {\n            auto\
    \ [x, y] = *ret;\n            assert(a * x + b * y == c);\n            if (a &&\
    \ b && c) {\n                assert(abs(x) <= abs(b * c));\n                assert(abs(y)\
    \ <= abs(a * c));\n            }\n        }\n    }\n    for (int a = -50; a <=\
    \ 50; ++a) {\n        for (int b = -50; b <= 50; ++b) {\n            for (int\
    \ c = -50; c <= 50; ++c) {\n                optional<pair<i32, i32>> ret = ax_by_c(a,\
    \ b, c);\n                if (ret.has_value()) {\n                    auto [x,\
    \ y] = *ret;\n                    assert(a * x + b * y == c);\n              \
    \      if (a && b && c) {\n                        assert(abs(x) <= abs(b * c));\n\
    \                        assert(abs(y) <= abs(a * c));\n                    }\n\
    \                }\n            }\n        }\n    }\n}\n\nint main() {\n    test();\n\
    \    cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#include \"../../template/template.hpp\"\
    \n#include \"../../template/random.hpp\"\n#include \"../../number_theory/ax_by_c.hpp\"\
    \n\nvoid test() {\n    constexpr int ITER = 1'000'000;\n    for (int t = 0; t\
    \ < ITER; ++t) {\n        i64 a = uniform(-1'000'000, 1'000'000);\n        i64\
    \ b = uniform(-1'000'000, 1'000'000);\n        i64 c = uniform(-1'000'000, 1'000'000);\n\
    \        optional<pair<i64, i64>> ret = ax_by_c(a, b, c);\n        if (ret.has_value())\
    \ {\n            auto [x, y] = *ret;\n            assert(a * x + b * y == c);\n\
    \            if (a && b && c) {\n                assert(abs(x) <= abs(b * c));\n\
    \                assert(abs(y) <= abs(a * c));\n            }\n        }\n   \
    \ }\n    for (int a = -50; a <= 50; ++a) {\n        for (int b = -50; b <= 50;\
    \ ++b) {\n            for (int c = -50; c <= 50; ++c) {\n                optional<pair<i32,\
    \ i32>> ret = ax_by_c(a, b, c);\n                if (ret.has_value()) {\n    \
    \                auto [x, y] = *ret;\n                    assert(a * x + b * y\
    \ == c);\n                    if (a && b && c) {\n                        assert(abs(x)\
    \ <= abs(b * c));\n                        assert(abs(y) <= abs(a * c));\n   \
    \                 }\n                }\n            }\n        }\n    }\n}\n\n\
    int main() {\n    test();\n    cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - template/template.hpp
  - template/random.hpp
  - number_theory/ax_by_c.hpp
  - number_theory/utils.hpp
  isVerificationFile: true
  path: number_theory/test/ax_by_c_stress.test.cpp
  requiredBy: []
  timestamp: '2025-05-17 23:14:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: number_theory/test/ax_by_c_stress.test.cpp
layout: document
redirect_from:
- /verify/number_theory/test/ax_by_c_stress.test.cpp
- /verify/number_theory/test/ax_by_c_stress.test.cpp.html
title: number_theory/test/ax_by_c_stress.test.cpp
---
