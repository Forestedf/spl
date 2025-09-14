---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/lcm_convolution.hpp
    title: convolution/lcm_convolution.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
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
  bundledCode: "#line 1 \"convolution/test/lcm_convolution.stress.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#line 2 \"number_theory/mod_int.hpp\"\n\
    \n#include <cassert>\n#include <iostream>\n#include <type_traits>\n#line 2 \"\
    number_theory/utils.hpp\"\n\n#include <utility>\n\nconstexpr bool is_prime(unsigned\
    \ n) {\n    if (n == 0 || n == 1) {\n        return false;\n    }\n    for (unsigned\
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
    }\n#line 7 \"number_theory/mod_int.hpp\"\n\ntemplate <unsigned mod>\nstruct ModInt\
    \ {\n    static_assert(mod != 0, \"`mod` must not be equal to 0.\");\n    static_assert(mod\
    \ < (1u << 31),\n                  \"`mod` must be less than (1u << 31) = 2147483648.\"\
    );\n\n    unsigned val;\n\n    static constexpr unsigned get_mod() { return mod;\
    \ }\n\n    constexpr ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
    \ * = nullptr>\n    constexpr ModInt(T x)\n        : val((unsigned)((long long)x\
    \ % (long long)mod + (x < 0 ? mod : 0))) {}\n    template <typename T, std::enable_if_t<std::is_unsigned_v<T>>\
    \ * = nullptr>\n    constexpr ModInt(T x) : val((unsigned)(x % mod)) {}\n\n  \
    \  static constexpr ModInt raw(unsigned x) {\n        ModInt<mod> ret;\n     \
    \   ret.val = x;\n        return ret;\n    }\n\n    constexpr unsigned get_val()\
    \ const { return val; }\n\n    constexpr ModInt operator+() const { return *this;\
    \ }\n    constexpr ModInt operator-() const { return ModInt<mod>(0u) - *this;\
    \ }\n\n    constexpr ModInt &operator+=(const ModInt &rhs) {\n        val += rhs.val;\n\
    \        if (val >= mod) val -= mod;\n        return *this;\n    }\n    constexpr\
    \ ModInt &operator-=(const ModInt &rhs) {\n        val -= rhs.val;\n        if\
    \ (val >= mod) val += mod;\n        return *this;\n    }\n    constexpr ModInt\
    \ &operator*=(const ModInt &rhs) {\n        val = (unsigned long long)val * rhs.val\
    \ % mod;\n        return *this;\n    }\n    constexpr ModInt &operator/=(const\
    \ ModInt &rhs) {\n        val = (unsigned long long)val * rhs.inv().val % mod;\n\
    \        return *this;\n    }\n\n    friend constexpr ModInt operator+(const ModInt\
    \ &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs) += rhs;\n    }\n\
    \    friend constexpr ModInt operator-(const ModInt &lhs, const ModInt &rhs) {\n\
    \        return ModInt<mod>(lhs) -= rhs;\n    }\n    friend constexpr ModInt operator*(const\
    \ ModInt &lhs, const ModInt &rhs) {\n        return ModInt<mod>(lhs) *= rhs;\n\
    \    }\n    friend constexpr ModInt operator/(const ModInt &lhs, const ModInt\
    \ &rhs) {\n        return ModInt<mod>(lhs) /= rhs;\n    }\n\n    constexpr ModInt\
    \ pow(unsigned long long x) const {\n        ModInt<mod> ret = ModInt<mod>::raw(1);\n\
    \        ModInt<mod> self = *this;\n        while (x != 0) {\n            if (x\
    \ & 1) ret *= self;\n            self *= self;\n            x >>= 1;\n       \
    \ }\n        return ret;\n    }\n    constexpr ModInt inv() const {\n        static_assert(is_prime(mod),\
    \ \"`mod` must be a prime number.\");\n        assert(val != 0);\n        return\
    \ this->pow(mod - 2);\n    }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, ModInt<mod> &x) {\n        long long val;\n        is >> val;\n       \
    \ x.val = val % mod + (val < 0 ? mod : 0);\n        return is;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const ModInt<mod> &x) {\n       \
    \ os << x.val;\n        return os;\n    }\n\n    friend bool operator==(const\
    \ ModInt &lhs, const ModInt &rhs) {\n        return lhs.val == rhs.val;\n    }\n\
    \n    friend bool operator!=(const ModInt &lhs, const ModInt &rhs) {\n       \
    \ return lhs.val != rhs.val;\n    }\n};\n\ntemplate <unsigned mod>\nvoid debug(ModInt<mod>\
    \ x) {\n    std::cerr << x.val;\n}\n#line 3 \"convolution/lcm_convolution.hpp\"\
    \n#include <vector>\n// length: max(a.size(), b.size())\n// ignore index 0\ntemplate\
    \ <typename T>\nstd::vector<T> lcm_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    if (a.size() <= 1 || b.size() <= 1) {\n        return std::vector<T>(std::max(a.size(),\
    \ b.size()), T(0));\n    }\n    if (a.size() > b.size()) {\n        a.swap(b);\n\
    \    }\n    int n = (int)b.size();\n    a.resize(n, T(0));\n    std::vector<int>\
    \ is_prime(n, 1);\n    for (int i = 2; i < n; ++i) {\n        if (!is_prime[i])\
    \ {\n            continue;\n        }\n        for (int j = 1, k = i; k < n; ++j,\
    \ k += i) {\n            a[k] += a[j];\n            b[k] += b[j];\n          \
    \  is_prime[k] = 0;\n        }\n        is_prime[i] = 1;\n    }\n    for (int\
    \ i = 1; i < n; ++i) {\n        b[i] *= a[i];\n    }\n    for (int i = 2; i <\
    \ n; ++i) {\n        if (!is_prime[i]) {\n            continue;\n        }\n \
    \       for (int j = (n - 1) / i, k = j * i; j >= 1; --j, k -= i) {\n        \
    \    b[k] -= b[j];\n        }\n    }\n    b[0] = T(0);\n    return b;\n}\n#line\
    \ 2 \"template/random.hpp\"\n#include <chrono>\n#include <random>\n\n#if defined(LOCAL)\
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
    \  read(name);\n#line 9 \"convolution/test/lcm_convolution.stress.test.cpp\"\n\
    \nusing M = ModInt<998244353>;\n\nV<M> naive_convolution(const V<M> &a, const\
    \ V<M> &b) {\n    V<M> ret(max(LEN(a), LEN(b)));\n    REP(i, 1, LEN(a)) REP(j,\
    \ 1, LEN(b)) {\n        i64 tmp = lcm(i64(i), i64(j));\n        if (tmp < LEN(ret))\
    \ {\n            ret[tmp] += a[i] * b[j];\n        }\n    }\n    return ret;\n\
    }\n\nvoid test() {\n    constexpr i32 NM_MAX = 500;\n    i32 n = uniform(NM_MAX\
    \ + 1);\n    i32 m = uniform(NM_MAX + 1);\n    V<M> a(n), b(m);\n    REP(i, n)\
    \ { a[i].val = uniform(M::get_mod()); }\n    REP(i, m) { b[i].val = uniform(M::get_mod());\
    \ }\n    V<M> c = naive_convolution(a, b);\n    V<M> d = lcm_convolution(a, b);\n\
    \    assert(c == d);\n}\n\nvoid small_test() {\n    constexpr i32 NM_MAX = 10;\n\
    \    i32 n = uniform(NM_MAX + 1);\n    i32 m = uniform(NM_MAX + 1);\n    V<M>\
    \ a(n), b(m);\n    REP(i, n) { a[i].val = uniform(M::get_mod()); }\n    REP(i,\
    \ m) { b[i].val = uniform(M::get_mod()); }\n    V<M> c = naive_convolution(a,\
    \ b);\n    V<M> d = lcm_convolution(a, b);\n    assert(c == d);\n}\n\nvoid zero_test()\
    \ {\n    constexpr i32 NM_MAX = 5;\n    REP(n, NM_MAX + 1) REP(m, NM_MAX + 1)\
    \ {\n        V<M> a(n), b(m);\n        REP(i, n) { a[i].val = uniform(M::get_mod());\
    \ }\n        REP(i, m) { b[i].val = uniform(M::get_mod()); }\n        V<M> c =\
    \ naive_convolution(a, b);\n        V<M> d = lcm_convolution(a, b);\n        assert(c\
    \ == d);\n    }\n}\n\nint main() {\n    constexpr i32 ITER = 1000;\n    REP(i,\
    \ ITER) {\n        test();\n        small_test();\n    }\n    zero_test();\n \
    \   cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../convolution/lcm_convolution.hpp\"\n#include \"../../template/random.hpp\"\
    \n#include \"../../template/template.hpp\"\n\nusing M = ModInt<998244353>;\n\n\
    V<M> naive_convolution(const V<M> &a, const V<M> &b) {\n    V<M> ret(max(LEN(a),\
    \ LEN(b)));\n    REP(i, 1, LEN(a)) REP(j, 1, LEN(b)) {\n        i64 tmp = lcm(i64(i),\
    \ i64(j));\n        if (tmp < LEN(ret)) {\n            ret[tmp] += a[i] * b[j];\n\
    \        }\n    }\n    return ret;\n}\n\nvoid test() {\n    constexpr i32 NM_MAX\
    \ = 500;\n    i32 n = uniform(NM_MAX + 1);\n    i32 m = uniform(NM_MAX + 1);\n\
    \    V<M> a(n), b(m);\n    REP(i, n) { a[i].val = uniform(M::get_mod()); }\n \
    \   REP(i, m) { b[i].val = uniform(M::get_mod()); }\n    V<M> c = naive_convolution(a,\
    \ b);\n    V<M> d = lcm_convolution(a, b);\n    assert(c == d);\n}\n\nvoid small_test()\
    \ {\n    constexpr i32 NM_MAX = 10;\n    i32 n = uniform(NM_MAX + 1);\n    i32\
    \ m = uniform(NM_MAX + 1);\n    V<M> a(n), b(m);\n    REP(i, n) { a[i].val = uniform(M::get_mod());\
    \ }\n    REP(i, m) { b[i].val = uniform(M::get_mod()); }\n    V<M> c = naive_convolution(a,\
    \ b);\n    V<M> d = lcm_convolution(a, b);\n    assert(c == d);\n}\n\nvoid zero_test()\
    \ {\n    constexpr i32 NM_MAX = 5;\n    REP(n, NM_MAX + 1) REP(m, NM_MAX + 1)\
    \ {\n        V<M> a(n), b(m);\n        REP(i, n) { a[i].val = uniform(M::get_mod());\
    \ }\n        REP(i, m) { b[i].val = uniform(M::get_mod()); }\n        V<M> c =\
    \ naive_convolution(a, b);\n        V<M> d = lcm_convolution(a, b);\n        assert(c\
    \ == d);\n    }\n}\n\nint main() {\n    constexpr i32 ITER = 1000;\n    REP(i,\
    \ ITER) {\n        test();\n        small_test();\n    }\n    zero_test();\n \
    \   cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - convolution/lcm_convolution.hpp
  - template/random.hpp
  - template/template.hpp
  isVerificationFile: true
  path: convolution/test/lcm_convolution.stress.test.cpp
  requiredBy: []
  timestamp: '2025-08-14 15:17:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: convolution/test/lcm_convolution.stress.test.cpp
layout: document
redirect_from:
- /verify/convolution/test/lcm_convolution.stress.test.cpp
- /verify/convolution/test/lcm_convolution.stress.test.cpp.html
title: convolution/test/lcm_convolution.stress.test.cpp
---
