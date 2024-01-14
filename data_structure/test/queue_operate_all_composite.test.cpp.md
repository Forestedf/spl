---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sliding_window_aggregation.hpp
    title: data_structure/sliding_window_aggregation.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"data_structure/test/queue_operate_all_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#define FAST_IO\n\n#line 2 \"data_structure/sliding_window_aggregation.hpp\"\
    \n\n#include <cassert>\n#include <stack>\n#include <utility>\n\ntemplate <typename\
    \ Monoid>\nclass SlidingWindowAggregation {\npublic:\n    using Value = typename\
    \ Monoid::Value;\n\nprivate:\n    std::stack<Value> st0;\n    std::stack<Value>\
    \ st1;\n    Value st1_prod;\n\npublic:\n    SlidingWindowAggregation()\n     \
    \   : st0({Monoid::id()}), st1({Monoid::id()}), st1_prod(Monoid::id()) {}\n\n\
    \    void push(Value val) {\n        st1_prod = Monoid::op(st1_prod, val);\n \
    \       st1.emplace(std::move(val));\n    }\n\n    void pop() {\n        if (st0.size()\
    \ == 1) {\n            while (st1.size() > 1) {\n                st0.emplace(Monoid::op(st1.top(),\
    \ st0.top()));\n                st1.pop();\n            }\n            st1_prod\
    \ = Monoid::id();\n        }\n        st0.pop();\n    }\n\n    int size() const\
    \ { return (int)(st0.size() + st1.size() - 2); }\n\n    bool empty() const { return\
    \ size() == 0; }\n\n    Value prod() const { return Monoid::op(st0.top(), st1_prod);\
    \ }\n};\n#line 2 \"number_theory/mod_int.hpp\"\n\n#line 4 \"number_theory/mod_int.hpp\"\
    \n#include <iostream>\n#include <type_traits>\n#line 2 \"number_theory/utils.hpp\"\
    \n\nconstexpr bool is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n     \
    \   return false;\n    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n      \
    \  if (n % i == 0) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n\nconstexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod)\
    \ {\n    unsigned ret = 1, self = x;\n    while (y != 0) {\n        if (y & 1)\
    \ {\n            ret = (unsigned)((unsigned long long)ret * self % mod);\n   \
    \     }\n        self = (unsigned)((unsigned long long)self * self % mod);\n \
    \       y /= 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr\
    \ unsigned primitive_root() {\n    static_assert(is_prime(mod), \"`mod` must be\
    \ a prime number.\");\n    if (mod == 2) {\n        return 1;\n    }\n\n    unsigned\
    \ primes[32] = {};\n    int it = 0;\n    {\n        unsigned m = mod - 1;\n  \
    \      for (unsigned i = 2; i * i <= m; ++i) {\n            if (m % i == 0) {\n\
    \                primes[it++] = i;\n                while (m % i == 0) {\n   \
    \                 m /= i;\n                }\n            }\n        }\n     \
    \   if (m != 1) {\n            primes[it++] = m;\n        }\n    }\n    for (unsigned\
    \ i = 2; i < mod; ++i) {\n        bool ok = true;\n        for (int j = 0; j <\
    \ it; ++j) {\n            if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return i;\n    }\n    return 0;\n}\n\n// y >= 1\ntemplate <typename\
    \ T>\nconstexpr T safe_mod(T x, T y) {\n    x %= y;\n    if (x < 0) {\n      \
    \  x += y;\n    }\n    return x;\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr\
    \ T floor_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n\
    \    }\n    if (x >= 0) {\n        return x / y;\n    } else {\n        return\
    \ -((-x + y - 1) / y);\n    }\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr\
    \ T ceil_div(T x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n\
    \    }\n    if (x >= 0) {\n        return (x + y - 1) / y;\n    } else {\n   \
    \     return -(-x / y);\n    }\n}\n#line 7 \"number_theory/mod_int.hpp\"\n\ntemplate\
    \ <unsigned mod>\nstruct ModInt {\n    static_assert(mod != 0, \"`mod` must not\
    \ be equal to 0.\");\n    static_assert(mod < (1u << 31),\n                  \"\
    `mod` must be less than (1u << 31) = 2147483648.\");\n\n    unsigned val;\n\n\
    \    static constexpr unsigned get_mod() { return mod; }\n\n    constexpr ModInt()\
    \ : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
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
    \ x) {\n    std::cerr << x.val;\n}\n#line 1 \"template/template.hpp\"\n#include\
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
    #line 7 \"data_structure/test/queue_operate_all_composite.test.cpp\"\n\nusing\
    \ Mint = ModInt<998244353>;\n\nstruct Linear {\n    Mint a, b;\n    Linear() :\
    \ a(Mint(1)), b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}\n\
    \    Mint operator()(Mint x) { return a * x + b; }\n};\n\n// f \\circ g\nLinear\
    \ composite(const Linear &f, const Linear &g) {\n    return Linear(f.a * g.a,\
    \ f.a * g.b + f.b);\n}\n\nstruct Ops {\n    using Value = Linear;\n    static\
    \ Value id() { return Linear(); }\n    static Value op(const Value &x, const Value\
    \ &y) { return composite(y, x); }\n};\n\nint main() {\n    i32 q;\n    cin >>\
    \ q;\n    SlidingWindowAggregation<Ops> swag;\n    REP(qi, q) {\n        i32 type;\n\
    \        cin >> type;\n        if (type == 0) {\n            Linear f;\n     \
    \       cin >> f.a >> f.b;\n            swag.push(f);\n        } else if (type\
    \ == 1) {\n            swag.pop();\n        } else {\n            Mint x;\n  \
    \          cin >> x;\n            cout << swag.prod()(x) << '\\n';\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#define FAST_IO\n\n#include \"../../data_structure/sliding_window_aggregation.hpp\"\
    \n#include \"../../number_theory/mod_int.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nusing Mint = ModInt<998244353>;\n\nstruct Linear {\n    Mint a, b;\n    Linear()\
    \ : a(Mint(1)), b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}\n\
    \    Mint operator()(Mint x) { return a * x + b; }\n};\n\n// f \\circ g\nLinear\
    \ composite(const Linear &f, const Linear &g) {\n    return Linear(f.a * g.a,\
    \ f.a * g.b + f.b);\n}\n\nstruct Ops {\n    using Value = Linear;\n    static\
    \ Value id() { return Linear(); }\n    static Value op(const Value &x, const Value\
    \ &y) { return composite(y, x); }\n};\n\nint main() {\n    i32 q;\n    cin >>\
    \ q;\n    SlidingWindowAggregation<Ops> swag;\n    REP(qi, q) {\n        i32 type;\n\
    \        cin >> type;\n        if (type == 0) {\n            Linear f;\n     \
    \       cin >> f.a >> f.b;\n            swag.push(f);\n        } else if (type\
    \ == 1) {\n            swag.pop();\n        } else {\n            Mint x;\n  \
    \          cin >> x;\n            cout << swag.prod()(x) << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - data_structure/sliding_window_aggregation.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - template/template.hpp
  isVerificationFile: true
  path: data_structure/test/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-01-14 15:15:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/queue_operate_all_composite.test.cpp
- /verify/data_structure/test/queue_operate_all_composite.test.cpp.html
title: data_structure/test/queue_operate_all_composite.test.cpp
---