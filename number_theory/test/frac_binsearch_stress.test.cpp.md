---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: number_theory/frac_binsearch.hpp
    title: number_theory/frac_binsearch.hpp
  - icon: ':question:'
    path: template/random.hpp
    title: template/random.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"number_theory/test/frac_binsearch_stress.test.cpp\"\n#define\
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
    \ n - 1)(mt);\n}\n#line 2 \"number_theory/frac_binsearch.hpp\"\n\n#line 6 \"number_theory/frac_binsearch.hpp\"\
    \n\n// f :: I -> I -> bool\ntemplate <typename I, typename F>\nstd::pair<I, I>\
    \ get_lim_true(I bound, F f) {\n    assert(bound >= 1);\n    std::pair<I, I> ok(0,\
    \ 1), ng(1, 0);\n    if (!f(0, 1)) {\n        std::swap(ok, ng);\n    }\n    while\
    \ (true) {\n        std::pair<I, I> now(ok.first + ng.first, ok.second + ng.second);\n\
    \        bool rt = f(now.first, now.second);\n        std::pair<I, I> &from =\
    \ (rt ? ok : ng), &to = (rt ? ng : ok);\n        I l = 1, r = 2;\n        while\
    \ (f(from.first + to.first * r, from.second + to.second * r) == rt) {\n      \
    \      l *= 2;\n            r *= 2;\n            if (std::max(from.first + to.first\
    \ * l, from.second + to.second * l) > bound) {\n                if (rt) {\n  \
    \                  I t = l;\n                    if (to.first != 0) {\n      \
    \                  t = std::min(t, (bound - from.first) / to.first);\n       \
    \             }\n                    if (to.second != 0) {\n                 \
    \       t = std::min(t, (bound - from.second) / to.second);\n                \
    \    }\n                    return std::pair<I, I>(from.first + to.first * t,\
    \ from.second + to.second * t);\n                } else {\n                  \
    \  return ok;\n                }\n            }\n        }\n        while (r -\
    \ l > 1) {\n            I mid = (l + r) / 2;\n            std::pair<I, I> nxt(from.first\
    \ + to.first * mid, from.second + to.second * mid);\n            if (std::max(nxt.first,\
    \ nxt.second) <= bound && f(nxt.first, nxt.second) == rt) {\n                l\
    \ = mid;\n            } else {\n                r = mid;\n            }\n    \
    \    }\n        if (std::max(from.first + to.first * r, from.second + to.second\
    \ * r) > bound) {\n            if (rt) {\n                return std::pair<I,\
    \ I>(from.first + to.first * l, from.second + to.second * l);\n            } else\
    \ {\n                return to;\n            }\n        }\n        from.first\
    \ += to.first * l;\n        from.second += to.second * l;\n    }\n    assert(false);\n\
    }\n#line 8 \"number_theory/test/frac_binsearch_stress.test.cpp\"\n\nstruct Rational\
    \ {\n    i64 num, den;\n    Rational() : num(0), den(1) {}\n    Rational(i64 n,\
    \ i64 d) : num(n), den(d) {\n        assert(den != 0);\n        i64 g = gcd(num,\
    \ den);\n        num /= g;\n        den /= g;\n        if (den < 0) {\n      \
    \      num = -num;\n            den = -den;\n        }\n    }\n    friend i64\
    \ comp(Rational lhs, Rational rhs) {\n        return lhs.num * rhs.den - rhs.num\
    \ * lhs.den;\n    }\n    friend bool operator<(Rational lhs, Rational rhs) {\n\
    \        return comp(lhs, rhs) < 0;\n    }\n    friend bool operator>(Rational\
    \ lhs, Rational rhs) {\n        return comp(lhs, rhs) > 0;\n    }\n    friend\
    \ bool operator<=(Rational lhs, Rational rhs) {\n        return comp(lhs, rhs)\
    \ <= 0;\n    }\n    friend bool operator>=(Rational lhs, Rational rhs) {\n   \
    \     return comp(lhs, rhs) >= 0;\n    }\n    friend bool operator==(Rational\
    \ lhs, Rational rhs) {\n        return comp(lhs, rhs) == 0;\n    }\n    friend\
    \ bool operator!=(Rational lhs, Rational rhs) {\n        return comp(lhs, rhs)\
    \ != 0;\n    }\n};\n\nvoid test() {\n    constexpr i32 B = 1000;\n    V<Rational>\
    \ rats;\n    REP(num, 1, B + 1) {\n        REP(den, num + 1, B + 1) {\n      \
    \      if (gcd(num, den) == 1) {\n                rats.push_back(Rational(num,\
    \ den));\n            }\n        }\n    }\n    rats.push_back(Rational(0, 1));\n\
    \    rats.push_back(Rational(1, 1));\n    sort(ALL(rats));\n    constexpr i64\
    \ C = 1'000'000'000'000'000;\n    REP(i, 100000) {\n        i64 c = (uniform(2)\
    \ ? B + 1 : C + 1);\n        i64 num = uniform(1LL, c + 1);\n        i64 den =\
    \ uniform(1LL, c + 1);\n        while (num == den) {\n            num = uniform(1LL,\
    \ c + 1);\n            den = uniform(1LL, c + 1);\n        }\n        if (num\
    \ > den) {\n            swap(num, den);\n        }\n        Rational r(num, den);\n\
    \        // >=r\n        {\n            auto [a, b] = get_lim_true(B, [&](i32\
    \ x, i32 y) -> bool {\n                return Rational(x, y) >= r;\n         \
    \   });\n            auto it = lower_bound(ALL(rats), r);\n            assert(Rational(a,\
    \ b) == *it);\n        }\n        // <=r\n        {\n            auto [a, b] =\
    \ get_lim_true(B, [&](i32 x, i32 y) -> bool {\n                return Rational(x,\
    \ y) <= r;\n            });\n            auto it = upper_bound(ALL(rats), r) -\
    \ 1;\n            assert(Rational(a, b) == *it);\n        }\n        // >r\n \
    \       {\n            auto [a, b] = get_lim_true(B, [&](i32 x, i32 y) -> bool\
    \ {\n                return Rational(x, y) > r;\n            });\n           \
    \ auto it = upper_bound(ALL(rats), r);\n            assert(Rational(a, b) == *it);\n\
    \        }\n        // <r\n        {\n            auto [a, b] = get_lim_true(B,\
    \ [&](i32 x, i32 y) -> bool {\n                return Rational(x, y) < r;\n  \
    \          });\n            auto it = lower_bound(ALL(rats), r) - 1;\n       \
    \     assert(Rational(a, b) == *it);\n        }\n    }\n}\n\nint main() {\n  \
    \  test();\n    cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#include \"../../template/template.hpp\"\
    \n#include \"../../template/random.hpp\"\n#include \"../../number_theory/frac_binsearch.hpp\"\
    \n\nstruct Rational {\n    i64 num, den;\n    Rational() : num(0), den(1) {}\n\
    \    Rational(i64 n, i64 d) : num(n), den(d) {\n        assert(den != 0);\n  \
    \      i64 g = gcd(num, den);\n        num /= g;\n        den /= g;\n        if\
    \ (den < 0) {\n            num = -num;\n            den = -den;\n        }\n \
    \   }\n    friend i64 comp(Rational lhs, Rational rhs) {\n        return lhs.num\
    \ * rhs.den - rhs.num * lhs.den;\n    }\n    friend bool operator<(Rational lhs,\
    \ Rational rhs) {\n        return comp(lhs, rhs) < 0;\n    }\n    friend bool\
    \ operator>(Rational lhs, Rational rhs) {\n        return comp(lhs, rhs) > 0;\n\
    \    }\n    friend bool operator<=(Rational lhs, Rational rhs) {\n        return\
    \ comp(lhs, rhs) <= 0;\n    }\n    friend bool operator>=(Rational lhs, Rational\
    \ rhs) {\n        return comp(lhs, rhs) >= 0;\n    }\n    friend bool operator==(Rational\
    \ lhs, Rational rhs) {\n        return comp(lhs, rhs) == 0;\n    }\n    friend\
    \ bool operator!=(Rational lhs, Rational rhs) {\n        return comp(lhs, rhs)\
    \ != 0;\n    }\n};\n\nvoid test() {\n    constexpr i32 B = 1000;\n    V<Rational>\
    \ rats;\n    REP(num, 1, B + 1) {\n        REP(den, num + 1, B + 1) {\n      \
    \      if (gcd(num, den) == 1) {\n                rats.push_back(Rational(num,\
    \ den));\n            }\n        }\n    }\n    rats.push_back(Rational(0, 1));\n\
    \    rats.push_back(Rational(1, 1));\n    sort(ALL(rats));\n    constexpr i64\
    \ C = 1'000'000'000'000'000;\n    REP(i, 100000) {\n        i64 c = (uniform(2)\
    \ ? B + 1 : C + 1);\n        i64 num = uniform(1LL, c + 1);\n        i64 den =\
    \ uniform(1LL, c + 1);\n        while (num == den) {\n            num = uniform(1LL,\
    \ c + 1);\n            den = uniform(1LL, c + 1);\n        }\n        if (num\
    \ > den) {\n            swap(num, den);\n        }\n        Rational r(num, den);\n\
    \        // >=r\n        {\n            auto [a, b] = get_lim_true(B, [&](i32\
    \ x, i32 y) -> bool {\n                return Rational(x, y) >= r;\n         \
    \   });\n            auto it = lower_bound(ALL(rats), r);\n            assert(Rational(a,\
    \ b) == *it);\n        }\n        // <=r\n        {\n            auto [a, b] =\
    \ get_lim_true(B, [&](i32 x, i32 y) -> bool {\n                return Rational(x,\
    \ y) <= r;\n            });\n            auto it = upper_bound(ALL(rats), r) -\
    \ 1;\n            assert(Rational(a, b) == *it);\n        }\n        // >r\n \
    \       {\n            auto [a, b] = get_lim_true(B, [&](i32 x, i32 y) -> bool\
    \ {\n                return Rational(x, y) > r;\n            });\n           \
    \ auto it = upper_bound(ALL(rats), r);\n            assert(Rational(a, b) == *it);\n\
    \        }\n        // <r\n        {\n            auto [a, b] = get_lim_true(B,\
    \ [&](i32 x, i32 y) -> bool {\n                return Rational(x, y) < r;\n  \
    \          });\n            auto it = lower_bound(ALL(rats), r) - 1;\n       \
    \     assert(Rational(a, b) == *it);\n        }\n    }\n}\n\nint main() {\n  \
    \  test();\n    cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - template/template.hpp
  - template/random.hpp
  - number_theory/frac_binsearch.hpp
  isVerificationFile: true
  path: number_theory/test/frac_binsearch_stress.test.cpp
  requiredBy: []
  timestamp: '2025-05-17 23:14:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: number_theory/test/frac_binsearch_stress.test.cpp
layout: document
redirect_from:
- /verify/number_theory/test/frac_binsearch_stress.test.cpp
- /verify/number_theory/test/frac_binsearch_stress.test.cpp.html
title: number_theory/test/frac_binsearch_stress.test.cpp
---
