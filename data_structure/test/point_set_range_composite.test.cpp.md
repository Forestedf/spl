---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/operations.hpp
    title: data_structure/operations.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: data_structure/segment_tree.hpp
  - icon: ':question:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':question:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"data_structure/test/point_set_range_composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#define FAST_IO\n\n#line 2 \"data_structure/segment_tree.hpp\"\n\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n#line 2 \"data_structure/operations.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n#line 6 \"data_structure/operations.hpp\"\
    \n\ntemplate <typename T>\nstruct Add {\n    using Value = T;\n    static Value\
    \ id() { return T(0); }\n    static Value op(const Value &lhs, const Value &rhs)\
    \ { return lhs + rhs; }\n    static Value inv(const Value &x) { return -x; }\n\
    };\n\ntemplate <typename T>\nstruct Mul {\n    using Value = T;\n    static Value\
    \ id() { return Value(1); }\n    static Value op(const Value &lhs, const Value\
    \ &rhs) { return lhs * rhs; }\n    static Value inv(const Value &x) { return Value(1)\
    \ / x; }\n};\n\ntemplate <typename T>\nstruct Min {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
    \    using Value = T;\n    static Value id() { return std::numeric_limits<T>::max();\
    \ }\n    static Value op(const Value &lhs, const Value &rhs) {\n        return\
    \ std::min(lhs, rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Max {\n    static_assert(std::numeric_limits<T>::is_specialized);\n\
    \    using Value = T;\n    static Value id() { return std::numeric_limits<Value>::min();\
    \ }\n    static Value op(const Value &lhs, const Value &rhs) {\n        return\
    \ std::max(lhs, rhs);\n    }\n};\n\ntemplate <typename T>\nstruct Xor {\n    using\
    \ Value = T;\n    static Value id() { return T(0); }\n    static Value op(const\
    \ Value &lhs, const Value &rhs) { return lhs ^ rhs; }\n    static Value inv(const\
    \ Value &x) { return x; }\n};\n\ntemplate <typename Monoid>\nstruct Reversible\
    \ {\n    using Value = std::pair<typename Monoid::Value, typename Monoid::Value>;\n\
    \    static Value id() { return Value(Monoid::id(), Monoid::id()); }\n    static\
    \ Value op(const Value &v1, const Value &v2) {\n        return Value(Monoid::op(v1.first,\
    \ v2.first),\n                     Monoid::op(v2.second, v1.second));\n    }\n\
    };\n#line 7 \"data_structure/segment_tree.hpp\"\n\ntemplate <typename Monoid>\n\
    class SegmentTree {\npublic:\n    using Value = typename Monoid::Value;\n\nprivate:\n\
    \    int old_length;\n    int length;\n    std::vector<Value> node;\n\n    static\
    \ int ceil2(int n) {\n        int l = 1;\n        while (l < n) {\n          \
    \  l <<= 1;\n        }\n        return l;\n    }\n\npublic:\n    SegmentTree(int\
    \ n)\n        : old_length(n),\n          length(ceil2(old_length)),\n       \
    \   node(length << 1, Monoid::id()) {\n        assert(n >= 0);\n    }\n\n    SegmentTree(const\
    \ std::vector<Value> &v)\n        : old_length((int)v.size()),\n          length(ceil2(old_length)),\n\
    \          node(length << 1, Monoid::id()) {\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = v[i];\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    template <typename F>\n    SegmentTree(int\
    \ n, const F &f)\n        : old_length(n), length(ceil2(n)), node(length << 1,\
    \ Monoid::id()) {\n        assert(n >= 0);\n        for (int i = 0; i < old_length;\
    \ ++i) {\n            node[i + length] = f(i);\n        }\n        for (int i\
    \ = length - 1; i > 0; --i) {\n            node[i] = Monoid::op(node[i << 1],\
    \ node[i << 1 | 1]);\n        }\n    }\n\n    const Value &operator[](int idx)\
    \ const {\n        assert(idx >= 0 && idx < old_length);\n        return node[idx\
    \ + length];\n    }\n\n    void update(int idx, Value val) {\n        assert(idx\
    \ >= 0 && idx < old_length);\n        idx += length;\n        node[idx] = std::move(val);\n\
    \        while (idx != 1) {\n            idx >>= 1;\n            node[idx] = Monoid::op(node[idx\
    \ << 1], node[idx << 1 | 1]);\n        }\n    }\n\n    Value prod(int l, int r)\
    \ const {\n        assert(l >= 0 && l <= r && r <= old_length);\n        Value\
    \ prodl = Monoid::id();\n        Value prodr = Monoid::id();\n        l += length;\n\
    \        r += length;\n        while (l != r) {\n            if (l & 1) {\n  \
    \              prodl = Monoid::op(prodl, node[l++]);\n            }\n        \
    \    if (r & 1) {\n                prodr = Monoid::op(node[--r], prodr);\n   \
    \         }\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ Monoid::op(prodl, prodr);\n    }\n\n    Value all_prod() const { return node[1];\
    \ }\n};\n#line 2 \"number_theory/mod_int.hpp\"\n\n#line 4 \"number_theory/mod_int.hpp\"\
    \n#include <iostream>\n#include <type_traits>\n#line 2 \"number_theory/utils.hpp\"\
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
    #line 7 \"data_structure/test/point_set_range_composite.test.cpp\"\n\nusing Mint\
    \ = ModInt<998244353>;\n\nstruct Linear {\n    Mint a, b;\n    Linear() : a(Mint(1)),\
    \ b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}\n    Mint operator()(Mint\
    \ x) { return a * x + b; }\n};\n\n// f \\circ g\nLinear composite(const Linear\
    \ &f, const Linear &g) {\n    return Linear(f.a * g.a, f.a * g.b + f.b);\n}\n\n\
    struct Ops {\n    using Value = Linear;\n    static Value id() { return Linear();\
    \ }\n    static Value op(const Value &x, const Value &y) { return composite(y,\
    \ x); }\n};\n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    V<Linear>\
    \ fs(n);\n    REP(i, n) { cin >> fs[i].a >> fs[i].b; }\n\n    SegmentTree<Ops>\
    \ seg(fs);\n\n    REP(qi, q) {\n        i32 type;\n        cin >> type;\n    \
    \    if (type == 0) {\n            i32 p;\n            Linear f;\n           \
    \ cin >> p >> f.a >> f.b;\n            seg.update(p, f);\n        } else {\n \
    \           i32 l, r;\n            Mint x;\n            cin >> l >> r >> x;\n\
    \            cout << seg.prod(l, r)(x) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#define FAST_IO\n\n#include \"../../data_structure/segment_tree.hpp\"\n#include\
    \ \"../../number_theory/mod_int.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nusing Mint = ModInt<998244353>;\n\nstruct Linear {\n    Mint a, b;\n    Linear()\
    \ : a(Mint(1)), b(Mint(0)) {}\n    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}\n\
    \    Mint operator()(Mint x) { return a * x + b; }\n};\n\n// f \\circ g\nLinear\
    \ composite(const Linear &f, const Linear &g) {\n    return Linear(f.a * g.a,\
    \ f.a * g.b + f.b);\n}\n\nstruct Ops {\n    using Value = Linear;\n    static\
    \ Value id() { return Linear(); }\n    static Value op(const Value &x, const Value\
    \ &y) { return composite(y, x); }\n};\n\nint main() {\n    i32 n, q;\n    cin\
    \ >> n >> q;\n    V<Linear> fs(n);\n    REP(i, n) { cin >> fs[i].a >> fs[i].b;\
    \ }\n\n    SegmentTree<Ops> seg(fs);\n\n    REP(qi, q) {\n        i32 type;\n\
    \        cin >> type;\n        if (type == 0) {\n            i32 p;\n        \
    \    Linear f;\n            cin >> p >> f.a >> f.b;\n            seg.update(p,\
    \ f);\n        } else {\n            i32 l, r;\n            Mint x;\n        \
    \    cin >> l >> r >> x;\n            cout << seg.prod(l, r)(x) << '\\n';\n  \
    \      }\n    }\n}"
  dependsOn:
  - data_structure/segment_tree.hpp
  - data_structure/operations.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - template/template.hpp
  isVerificationFile: true
  path: data_structure/test/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2024-07-18 16:56:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/point_set_range_composite.test.cpp
- /verify/data_structure/test/point_set_range_composite.test.cpp.html
title: data_structure/test/point_set_range_composite.test.cpp
---
