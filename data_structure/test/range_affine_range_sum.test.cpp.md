---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segment_tree.hpp
    title: data_structure/lazy_segment_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"data_structure/test/range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#define\
    \ FAST_IO\n\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#define\
    \ OVERRIDE(a, b, c, d, ...) d\n#define REP2(i, n) for (i32 i = 0; i < (i32)(n);\
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
    #line 2 \"number_theory/mod_int.hpp\"\n\n#line 5 \"number_theory/mod_int.hpp\"\
    \n#include <type_traits>\n#line 2 \"number_theory/utils.hpp\"\n\nconstexpr bool\
    \ is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n        return false;\n\
    \    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n        if (n % i == 0) {\n\
    \            return false;\n        }\n    }\n    return true;\n}\n\nconstexpr\
    \ unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {\n    unsigned ret =\
    \ 1, self = x;\n    while (y != 0) {\n        if (y & 1) {\n            ret =\
    \ (unsigned)((unsigned long long)ret * self % mod);\n        }\n        self =\
    \ (unsigned)((unsigned long long)self * self % mod);\n        y /= 2;\n    }\n\
    \    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr unsigned primitive_root()\
    \ {\n    static_assert(is_prime(mod), \"`mod` must be a prime number.\");\n  \
    \  if (mod == 2) {\n        return 1;\n    }\n\n    unsigned primes[32] = {};\n\
    \    int it = 0;\n    {\n        unsigned m = mod - 1;\n        for (unsigned\
    \ i = 2; i * i <= m; ++i) {\n            if (m % i == 0) {\n                primes[it++]\
    \ = i;\n                while (m % i == 0) {\n                    m /= i;\n  \
    \              }\n            }\n        }\n        if (m != 1) {\n          \
    \  primes[it++] = m;\n        }\n    }\n    for (unsigned i = 2; i < mod; ++i)\
    \ {\n        bool ok = true;\n        for (int j = 0; j < it; ++j) {\n       \
    \     if (mod_pow(i, (mod - 1) / primes[j], mod) == 1) {\n                ok =\
    \ false;\n                break;\n            }\n        }\n        if (ok) return\
    \ i;\n    }\n    return 0;\n}\n\n// y >= 1\ntemplate <typename T>\nconstexpr T\
    \ safe_mod(T x, T y) {\n    x %= y;\n    if (x < 0) {\n        x += y;\n    }\n\
    \    return x;\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr T floor_div(T\
    \ x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n   \
    \ if (x >= 0) {\n        return x / y;\n    } else {\n        return -((-x + y\
    \ - 1) / y);\n    }\n}\n\n// y != 0\ntemplate <typename T>\nconstexpr T ceil_div(T\
    \ x, T y) {\n    if (y < 0) {\n        x *= -1;\n        y *= -1;\n    }\n   \
    \ if (x >= 0) {\n        return (x + y - 1) / y;\n    } else {\n        return\
    \ -(-x / y);\n    }\n}\n#line 7 \"number_theory/mod_int.hpp\"\n\ntemplate <unsigned\
    \ mod>\nclass ModInt {\n    static_assert(mod != 0, \"`mod` must not be equal\
    \ to 0.\");\n    static_assert(mod < (1u << 31),\n                  \"`mod` must\
    \ be less than (1u << 31) = 2147483648.\");\n\n    unsigned val;\n\npublic:\n\
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
    \ return lhs.val != rhs.val;\n    }\n};\n#line 2 \"data_structure/lazy_segment_tree.hpp\"\
    \n\n#line 6 \"data_structure/lazy_segment_tree.hpp\"\n\ntemplate <typename MonoidFunc>\n\
    class LazySegmentTree {\npublic:\n    using Value = typename MonoidFunc::Value;\n\
    \    using Func = typename MonoidFunc::Func;\n\nprivate:\n    int old_length;\n\
    \    int lg;\n    int length;\n    std::vector<Value> values;\n    std::vector<Func>\
    \ funcs;\n\n    static int lg2(int n) {\n        int x = 1;\n        int l = 0;\n\
    \        while (x < n) {\n            x <<= 1;\n            ++l;\n        }\n\
    \        return l;\n    }\n\n    void _apply(int idx, const Func &func) {\n  \
    \      values[idx] = MonoidFunc::apply(func, values[idx]);\n        funcs[idx]\
    \ = MonoidFunc::composite(func, funcs[idx]);\n    }\n\n    void push(int idx)\
    \ {\n        _apply(idx << 1, funcs[idx]);\n        _apply(idx << 1 | 1, funcs[idx]);\n\
    \        funcs[idx] = MonoidFunc::func_id();\n    }\n\n    void recalc_values(int\
    \ idx) {\n        values[idx] = MonoidFunc::op(values[idx << 1], values[idx <<\
    \ 1 | 1]);\n    }\n\npublic:\n    LazySegmentTree(int n)\n        : old_length(n),\n\
    \          lg(lg2(n)),\n          length(1 << lg),\n          values(length <<\
    \ 1, MonoidFunc::id()),\n          funcs(length << 1, MonoidFunc::func_id()) {\n\
    \        assert(n >= 0);\n    }\n\n    LazySegmentTree(const std::vector<Value>\
    \ &v)\n        : old_length((int)v.size()),\n          lg(lg2(old_length)),\n\
    \          length(1 << lg),\n          values(length << 1, MonoidFunc::id()),\n\
    \          funcs(length << 1, MonoidFunc::func_id()) {\n        for (int i = 0;\
    \ i < old_length; ++i) {\n            values[i + length] = v[i];\n        }\n\
    \        for (int i = length - 1; i > 0; --i) {\n            recalc_values(i);\n\
    \        }\n    }\n\n    template <typename F>\n    LazySegmentTree(int n, const\
    \ F &f)\n        : old_length(n),\n          lg(lg2(n)),\n          length(1 <<\
    \ lg),\n          values(length << 1, MonoidFunc::id()),\n          funcs(length\
    \ << 1, MonoidFunc::func_id()) {\n        for (int i = 0; i < old_length; ++i)\
    \ {\n            values[i + length] = f(i);\n        }\n        for (int i = length\
    \ - 1; i > 0; --i) {\n            recalc_values(i);\n        }\n    }\n\n    void\
    \ update(int idx, Value val) {\n        assert(idx >= 0 && idx < old_length);\n\
    \        idx += length;\n        for (int i = lg; i > 0; --i) {\n            push(idx\
    \ >> i);\n        }\n        values[idx] = std::move(val);\n        while (idx\
    \ >>= 1) {\n            recalc_values(idx);\n        }\n    }\n\n    void apply(int\
    \ l, int r, const Func &func) {\n        assert(l >= 0 && l <= r && r <= old_length);\n\
    \        if (l == r) {\n            return;\n        }\n        l += length;\n\
    \        r += length;\n        int _l = l;\n        int _r = r;\n        for (int\
    \ i = lg; i > 0; --i) {\n            push(_l >> i);\n            push((_r - 1)\
    \ >> i);\n        }\n        while (l < r) {\n            if (l & 1) {\n     \
    \           _apply(l++, func);\n            }\n            if (r & 1) {\n    \
    \            _apply(--r, func);\n            }\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n        for (int i = 1; i <= lg; ++i) {\n         \
    \   if ((_l >> i << i) != _l) {\n                recalc_values(_l >> i);\n   \
    \         }\n            if ((_r >> i << i) != _r) {\n                recalc_values((_r\
    \ - 1) >> i);\n            }\n        }\n    }\n\n    Value prod(int l, int r)\
    \ {\n        assert(l >= 0 && l <= r && r <= old_length);\n        if (l == r)\
    \ {\n            return MonoidFunc::id();\n        }\n        l += length;\n \
    \       r += length;\n        for (int i = lg; i > 0; --i) {\n            push(l\
    \ >> i);\n            push((r - 1) >> i);\n        }\n        Value lp = MonoidFunc::id();\n\
    \        Value rp = MonoidFunc::id();\n        while (l < r) {\n            if\
    \ (l & 1) {\n                lp = MonoidFunc::op(lp, values[l++]);\n         \
    \   }\n            if (r & 1) {\n                rp = MonoidFunc::op(values[--r],\
    \ rp);\n            }\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return MonoidFunc::op(lp, rp);\n    }\n\n    Value all_prod() const {\
    \ return values[1]; }\n};\n#line 7 \"data_structure/test/range_affine_range_sum.test.cpp\"\
    \n\nusing Mint = ModInt<998244353>;\n\nstruct Node {\n    i32 len;\n    Mint sum;\n\
    };\n\nstruct Fn {\n    Mint a, b;\n};\n\nstruct Ops {\n    using Value = Node;\n\
    \    using Func = Fn;\n    static Value id() {\n        return Node{0, Mint()};\n\
    \    }\n    static Value op(const Value &x, const Value &y) {\n        return\
    \ Node{x.len + y.len, x.sum + y.sum};\n    }\n    static Func func_id() {\n  \
    \      return Fn{Mint(1), Mint()};\n    }\n    static Func composite(const Func\
    \ &f, const Func &g) {\n        return Fn{f.a * g.a, f.a * g.b + f.b};\n    }\n\
    \    static Value apply(const Func &f, const Value &x) {\n        return Node{x.len,\
    \ x.sum * f.a + Mint(x.len) * f.b};\n    }\n};\n\nint main() {\n    i32 n, q;\n\
    \    cin >> n >> q;\n    V<Node> a(n);\n    REP(i, n) {\n        a[i].len = 1;\n\
    \        cin >> a[i].sum;\n    }\n    LazySegmentTree<Ops> seg(a);\n    REP(qi,\
    \ q) {\n        i32 type;\n        cin >> type;\n        if (type == 0) {\n  \
    \          i32 l, r;\n            Fn f;\n            cin >> l >> r >> f.a >> f.b;\n\
    \            seg.apply(l, r, f);\n        } else {\n            i32 l, r;\n  \
    \          cin >> l >> r;\n            cout << seg.prod(l, r).sum << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#define FAST_IO\n\n#include \"../../template/template.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n#include \"../../data_structure/lazy_segment_tree.hpp\"\n\nusing Mint = ModInt<998244353>;\n\
    \nstruct Node {\n    i32 len;\n    Mint sum;\n};\n\nstruct Fn {\n    Mint a, b;\n\
    };\n\nstruct Ops {\n    using Value = Node;\n    using Func = Fn;\n    static\
    \ Value id() {\n        return Node{0, Mint()};\n    }\n    static Value op(const\
    \ Value &x, const Value &y) {\n        return Node{x.len + y.len, x.sum + y.sum};\n\
    \    }\n    static Func func_id() {\n        return Fn{Mint(1), Mint()};\n   \
    \ }\n    static Func composite(const Func &f, const Func &g) {\n        return\
    \ Fn{f.a * g.a, f.a * g.b + f.b};\n    }\n    static Value apply(const Func &f,\
    \ const Value &x) {\n        return Node{x.len, x.sum * f.a + Mint(x.len) * f.b};\n\
    \    }\n};\n\nint main() {\n    i32 n, q;\n    cin >> n >> q;\n    V<Node> a(n);\n\
    \    REP(i, n) {\n        a[i].len = 1;\n        cin >> a[i].sum;\n    }\n   \
    \ LazySegmentTree<Ops> seg(a);\n    REP(qi, q) {\n        i32 type;\n        cin\
    \ >> type;\n        if (type == 0) {\n            i32 l, r;\n            Fn f;\n\
    \            cin >> l >> r >> f.a >> f.b;\n            seg.apply(l, r, f);\n \
    \       } else {\n            i32 l, r;\n            cin >> l >> r;\n        \
    \    cout << seg.prod(l, r).sum << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  - data_structure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: data_structure/test/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-13 18:43:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/range_affine_range_sum.test.cpp
- /verify/data_structure/test/range_affine_range_sum.test.cpp.html
title: data_structure/test/range_affine_range_sum.test.cpp
---
