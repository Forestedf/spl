---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/bit_vector.hpp
    title: data_structure/bit_vector.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/wavelet_matrix.hpp
    title: data_structure/wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
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
  bundledCode: "#line 1 \"data_structure/test/wavelet_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n#define\
    \ FAST_IO\n#define FIX_SEED\n\n#line 2 \"data_structure/wavelet_matrix.hpp\"\n\
    \n#include <algorithm>\n#include <cassert>\n#include <utility>\n#line 2 \"data_structure/bit_vector.hpp\"\
    \n#include <vector>\n#line 2 \"template/bitop.hpp\"\n\ntemplate <typename T, typename\
    \ U>\nbool ith_bit(T n, U i) {\n    return (n & ((T)1 << i)) != 0;\n}\n\nint popcount(int\
    \ x) { return __builtin_popcount(x); }\nunsigned popcount(unsigned x) { return\
    \ __builtin_popcount(x); }\nlong long popcount(long long x) { return __builtin_popcountll(x);\
    \ }\nunsigned long long popcount(unsigned long long x) {\n    return __builtin_popcountll(x);\n\
    }\n\n// x must not be 0\nint clz(int x) { return __builtin_clz(x); }\nunsigned\
    \ clz(unsigned x) { return __builtin_clz(x); }\nlong long clz(long long x) { return\
    \ __builtin_clzll(x); }\nunsigned long long clz(unsigned long long x) { return\
    \ __builtin_clzll(x); }\n\n// x must not be 0\nint ctz(int x) { return __builtin_ctz(x);\
    \ }\nunsigned ctz(unsigned int x) { return __builtin_ctz(x); }\nlong long ctz(long\
    \ long x) { return __builtin_ctzll(x); }\nunsigned long long ctz(unsigned long\
    \ long x) { return __builtin_ctzll(x); }\n\nint floor_log2(int x) { return 31\
    \ - clz(x); }\nunsigned floor_log2(unsigned x) { return 31 - clz(x); }\nlong long\
    \ floor_log2(long long x) { return 63 - clz(x); }\nunsigned long long floor_log2(unsigned\
    \ long long x) { return 63 - clz(x); }\n\ntemplate <typename T>\nT mask_n(T x,\
    \ T n) {\n    T mask = ((T)1 << n) - 1;\n    return x & mask;\n}\n#line 4 \"data_structure/bit_vector.hpp\"\
    \n\nclass BitVector {\n    static constexpr int WIDTH = 64;\n\n    int n;\n  \
    \  std::vector<unsigned long long> bits;\n    std::vector<unsigned long long>\
    \ sum;\n    int zeros;\n\npublic:\n    BitVector(int _n)\n        : n(_n), bits(n\
    \ / WIDTH + 1, 0), sum(n / WIDTH + 1, 0), zeros(0) {}\n\n    void rev(int idx)\
    \ { bits[idx / WIDTH] ^= 1ULL << (idx % WIDTH); }\n\n    bool operator[](int idx)\
    \ const {\n        return (bits[idx / WIDTH] & (1ULL << (idx % WIDTH))) != 0;\n\
    \    }\n\n    void build() {\n        for (int i = 1; i < (int)sum.size(); ++i)\
    \ {\n            sum[i] = sum[i - 1] + popcount(bits[i - 1]);\n        }\n   \
    \     zeros = rank0(n);\n    }\n\n    int rank0(int n) const { return n - rank1(n);\
    \ }\n    int rank1(int n) const {\n        return sum[n / WIDTH] +\n         \
    \      popcount(\n                   mask_n(bits[n / WIDTH], (unsigned long long)(n\
    \ % WIDTH)));\n    }\n    int all_zeros() const { return zeros; }\n};\n#line 7\
    \ \"data_structure/wavelet_matrix.hpp\"\n\ntemplate <typename T>\nclass WaveletMatrix\
    \ {\n    int n;\n    int ht;\n    std::vector<BitVector> vecs;\n\npublic:\n  \
    \  WaveletMatrix(std::vector<T> a) : n((int)a.size()), ht(0), vecs() {\n     \
    \   assert(n > 0);\n        for (T ele : a) {\n            assert(ele >= 0);\n\
    \        }\n\n        T mx = std::max(T(1), *std::max_element(a.begin(), a.end()));\n\
    \        ht = (int)floor_log2(mx) + 1;\n        vecs.reserve(ht);\n\n        for\
    \ (T d = ht; d-- > 0;) {\n            BitVector vec(n);\n            for (int\
    \ i = 0; i < n; ++i) {\n                if (ith_bit(a[i], d)) {\n            \
    \        vec.rev(i);\n                }\n            }\n            vec.build();\n\
    \            std::vector<T> nxt(n);\n            auto it0 = nxt.begin();\n   \
    \         auto it1 = nxt.begin() + vec.all_zeros();\n            for (int i =\
    \ 0; i < n; ++i) {\n                if (vec[i]) {\n                    *(it1++)\
    \ = a[i];\n                } else {\n                    *(it0++) = a[i];\n  \
    \              }\n            }\n            std::swap(nxt, a);\n            vecs.emplace_back(std::move(vec));\n\
    \        }\n    }\n\n    T access(int idx) const {\n        assert(0 <= idx &&\
    \ idx < n);\n        T ret(0);\n        for (int i = 0; i < ht; ++i) {\n     \
    \       ret <<= 1;\n            if (vecs[i][idx]) {\n                ret ^= 1;\n\
    \                idx = vecs[i].all_zeros() + vecs[i].rank1(idx);\n           \
    \ } else {\n                idx = vecs[i].rank0(idx);\n            }\n       \
    \ }\n        return ret;\n    }\n\n    T kth_smallest(int l, int r, int k) const\
    \ {\n        assert(0 <= l && l <= r && r <= n && 0 <= k && k < r - l);\n    \
    \    T ret = 0;\n        for (int i = 0; i < ht; ++i) {\n            int l0 =\
    \ vecs[i].rank0(l);\n            int r0 = vecs[i].rank0(r);\n            ret <<=\
    \ 1;\n            if (k < r0 - l0) {\n                l = l0;\n              \
    \  r = r0;\n            } else {\n                ret ^= T(1);\n             \
    \   l += vecs[i].all_zeros() - l0;\n                r += vecs[i].all_zeros() -\
    \ r0;\n                k -= r0 - l0;\n            }\n        }\n        return\
    \ ret;\n    }\n    T kth_largest(int l, int r, int k) const {\n        return\
    \ kth_smallest(l, r, r - l - k - 1);\n    }\n\n    // no two ranges intersect\n\
    \    T kth_smallest_many_ranges(std::vector<std::pair<int, int>> ranges,\n   \
    \                            int k) const {\n        int s = 0;\n        for (auto\
    \ [l, r] : ranges) {\n            assert(0 <= l && l <= r && r <= n);\n      \
    \      s += r - l;\n        }\n        assert(0 <= k && k < s);\n        T ret\
    \ = 0;\n        for (int i = 0; i < ht; ++i) {\n            int zs = 0;\n    \
    \        for (auto [l, r] : ranges) {\n                zs += vecs[i].rank0(r)\
    \ - vecs[i].rank0(l);\n            }\n            ret <<= 1;\n            if (k\
    \ < zs) {\n                for (auto &[l, r] : ranges) {\n                   \
    \ l = vecs[i].rank0(l);\n                    r = vecs[i].rank0(r);\n         \
    \       }\n            } else {\n                ret ^= T(1);\n              \
    \  for (auto &[l, r] : ranges) {\n                    l = vecs[i].all_zeros()\
    \ + vecs[i].rank1(l);\n                    r = vecs[i].all_zeros() + vecs[i].rank1(r);\n\
    \                }\n                k -= zs;\n            }\n        }\n     \
    \   return ret;\n    }\n\n    // count i s.t. i \\in [l, r) and a[i] = v\n   \
    \ int rank(int l, int r, T v) const {\n        assert(0 <= l && l <= r && r <=\
    \ n);\n        if (v != 0 && floor_log2(v) >= ht) {\n            return 0;\n \
    \       }\n        for (int i = 0; i < ht; ++i) {\n            int l0 = vecs[i].rank0(l);\n\
    \            int r0 = vecs[i].rank0(r);\n            if (ith_bit(v, ht - 1 - i))\
    \ {\n                l += vecs[i].all_zeros() - l0;\n                r += vecs[i].all_zeros()\
    \ - r0;\n            } else {\n                l = l0;\n                r = r0;\n\
    \            }\n        }\n        return r - l;\n    }\n\n    // count i s.t.\
    \ i \\in [l, r) and a[i] < upper\n    int range_freq(int l, int r, T upper) const\
    \ {\n        assert(0 <= l && l < r && r <= n);\n        if (upper != 0 && floor_log2(upper)\
    \ >= ht) {\n            return r - l;\n        }\n        int cnt = 0;\n     \
    \   for (int i = 0; i < ht; ++i) {\n            int l0 = vecs[i].rank0(l);\n \
    \           int r0 = vecs[i].rank0(r);\n            if (ith_bit(upper, ht - 1\
    \ - i)) {\n                cnt += r0 - l0;\n                l += vecs[i].all_zeros()\
    \ - l0;\n                r += vecs[i].all_zeros() - r0;\n            } else {\n\
    \                l = l0;\n                r = r0;\n            }\n        }\n\
    \        return cnt;\n    }\n    // count i s.t. i \\in [l, r) and a[i] \\in [lower,\
    \ upper)\n    int range_freq(int l, int r, T lower, T upper) const {\n       \
    \ if (lower >= upper) {\n            return 0;\n        } else {\n           \
    \ return range_freq(l, r, upper) - range_freq(l, r, lower);\n        }\n    }\n\
    \n    // max v s.t. v \\in a[l, r) and v < upper\n    int prev(int l, int r, T\
    \ upper) const {\n        int freq = range_freq(l, r, upper);\n        if (freq\
    \ == 0) {\n            return T(-1);\n        } else {\n            return kth_smallest(l,\
    \ r, freq - 1);\n        }\n    }\n\n    // min v s.t. v \\in a[l, r) and v \\\
    geq lower\n    int next(int l, int r, T lower) const {\n        int freq = range_freq(l,\
    \ r, lower);\n        if (freq == r - l) {\n            return T(-1);\n      \
    \  } else {\n            return kth_smallest(l, r, freq);\n        }\n    }\n\
    };\n#line 2 \"template/random.hpp\"\n#include <chrono>\n#include <random>\n\n\
    #if defined(LOCAL) || defined(FIX_SEED)\nstd::mt19937_64 mt(123456789);\n#else\n\
    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    #endif\n\ntemplate <typename T>\nT uniform(T l, T r) {\n    return std::uniform_int_distribution<T>(l,\
    \ r - 1)(mt);\n}\ntemplate <typename T>\nT uniform(T n) {\n    return std::uniform_int_distribution<T>(0,\
    \ n - 1)(mt);\n}\n#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\n\
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
    #line 8 \"data_structure/test/wavelet_matrix.test.cpp\"\n\nconstexpr i32 ITER\
    \ = 100;\nconstexpr i32 LEN = 100;\nconstexpr i32 SIGMA = 100;\n\nvoid test(const\
    \ V<i32> &a) {\n    WaveletMatrix<i32> wm(a);\n\n    i32 n = (i32)a.size();\n\n\
    \    // access\n    REP(i, n) { assert(wm.access(i) == a[i]); }\n\n    // kth_smallest\n\
    \    REP(_iter, ITER) {\n        i32 l = uniform(n);\n        i32 r = uniform(l\
    \ + 1, n + 1);\n        i32 k = uniform(r - l);\n\n        V<i32> b(a.begin()\
    \ + l, a.begin() + r);\n        sort(ALL(b));\n        assert(wm.kth_smallest(l,\
    \ r, k) == b[k]);\n    }\n\n    // rank\n    REP(_iter, ITER) {\n        i32 l\
    \ = uniform(n);\n        i32 r = uniform(l + 1, n + 1);\n        i32 v = uniform(SIGMA\
    \ + 10);\n\n        assert(wm.rank(l, r, v) == count(a.begin() + l, a.begin()\
    \ + r, v));\n    }\n\n    // range_freq\n    REP(_iter, ITER) {\n        i32 l\
    \ = uniform(n);\n        i32 r = uniform(l + 1, n + 1);\n        i32 lower = uniform(SIGMA);\n\
    \        i32 upper = uniform(lower + 1, SIGMA + 10);\n\n        i32 cnt = 0;\n\
    \        REP(i, l, r) {\n            if (lower <= a[i] && a[i] < upper) {\n  \
    \              ++cnt;\n            }\n        }\n        assert(wm.range_freq(l,\
    \ r, lower, upper) == cnt);\n    }\n\n    // prev\n    REP(_iter, ITER) {\n  \
    \      i32 l = uniform(n);\n        i32 r = uniform(l + 1, n + 1);\n        i32\
    \ upper = uniform(SIGMA + 10);\n\n        i32 mx = -1;\n        REP(i, l, r) {\n\
    \            if (a[i] < upper) {\n                chmax(mx, a[i]);\n         \
    \   }\n        }\n        assert(wm.prev(l, r, upper) == mx);\n    }\n\n    //\
    \ next\n    REP(_iter, ITER) {\n        i32 l = uniform(n);\n        i32 r = uniform(l\
    \ + 1, n + 1);\n        i32 lower = uniform(SIGMA + 10);\n\n        i32 mn = INF;\n\
    \        REP(i, l, r) {\n            if (a[i] >= lower) {\n                chmin(mn,\
    \ a[i]);\n            }\n        }\n        if (mn == INF) {\n            assert(wm.next(l,\
    \ r, lower) == -1);\n        } else {\n            assert(wm.next(l, r, lower)\
    \ == mn);\n        }\n    }\n\n    assert(wm.rank(0, n, 128) == 0);\n    assert(wm.range_freq(0,\
    \ n, 128) == n);\n    assert(wm.prev(0, n, 128) == *max_element(ALL(a)));\n}\n\
    \nV<i32> gen_random() {\n    V<i32> a(LEN);\n    for (i32 &ele : a) {\n      \
    \  ele = uniform(SIGMA);\n    }\n    return a;\n}\n\nint main() {\n    REP(_,\
    \ 10) { test(gen_random()); }\n\n    cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#define FAST_IO\n#define FIX_SEED\n\n#include \"../../data_structure/wavelet_matrix.hpp\"\
    \n#include \"../../template/random.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nconstexpr i32 ITER = 100;\nconstexpr i32 LEN = 100;\nconstexpr i32 SIGMA =\
    \ 100;\n\nvoid test(const V<i32> &a) {\n    WaveletMatrix<i32> wm(a);\n\n    i32\
    \ n = (i32)a.size();\n\n    // access\n    REP(i, n) { assert(wm.access(i) ==\
    \ a[i]); }\n\n    // kth_smallest\n    REP(_iter, ITER) {\n        i32 l = uniform(n);\n\
    \        i32 r = uniform(l + 1, n + 1);\n        i32 k = uniform(r - l);\n\n \
    \       V<i32> b(a.begin() + l, a.begin() + r);\n        sort(ALL(b));\n     \
    \   assert(wm.kth_smallest(l, r, k) == b[k]);\n    }\n\n    // rank\n    REP(_iter,\
    \ ITER) {\n        i32 l = uniform(n);\n        i32 r = uniform(l + 1, n + 1);\n\
    \        i32 v = uniform(SIGMA + 10);\n\n        assert(wm.rank(l, r, v) == count(a.begin()\
    \ + l, a.begin() + r, v));\n    }\n\n    // range_freq\n    REP(_iter, ITER) {\n\
    \        i32 l = uniform(n);\n        i32 r = uniform(l + 1, n + 1);\n       \
    \ i32 lower = uniform(SIGMA);\n        i32 upper = uniform(lower + 1, SIGMA +\
    \ 10);\n\n        i32 cnt = 0;\n        REP(i, l, r) {\n            if (lower\
    \ <= a[i] && a[i] < upper) {\n                ++cnt;\n            }\n        }\n\
    \        assert(wm.range_freq(l, r, lower, upper) == cnt);\n    }\n\n    // prev\n\
    \    REP(_iter, ITER) {\n        i32 l = uniform(n);\n        i32 r = uniform(l\
    \ + 1, n + 1);\n        i32 upper = uniform(SIGMA + 10);\n\n        i32 mx = -1;\n\
    \        REP(i, l, r) {\n            if (a[i] < upper) {\n                chmax(mx,\
    \ a[i]);\n            }\n        }\n        assert(wm.prev(l, r, upper) == mx);\n\
    \    }\n\n    // next\n    REP(_iter, ITER) {\n        i32 l = uniform(n);\n \
    \       i32 r = uniform(l + 1, n + 1);\n        i32 lower = uniform(SIGMA + 10);\n\
    \n        i32 mn = INF;\n        REP(i, l, r) {\n            if (a[i] >= lower)\
    \ {\n                chmin(mn, a[i]);\n            }\n        }\n        if (mn\
    \ == INF) {\n            assert(wm.next(l, r, lower) == -1);\n        } else {\n\
    \            assert(wm.next(l, r, lower) == mn);\n        }\n    }\n\n    assert(wm.rank(0,\
    \ n, 128) == 0);\n    assert(wm.range_freq(0, n, 128) == n);\n    assert(wm.prev(0,\
    \ n, 128) == *max_element(ALL(a)));\n}\n\nV<i32> gen_random() {\n    V<i32> a(LEN);\n\
    \    for (i32 &ele : a) {\n        ele = uniform(SIGMA);\n    }\n    return a;\n\
    }\n\nint main() {\n    REP(_, 10) { test(gen_random()); }\n\n    cout << \"Hello\
    \ World\\n\";\n}"
  dependsOn:
  - data_structure/wavelet_matrix.hpp
  - data_structure/bit_vector.hpp
  - template/bitop.hpp
  - template/random.hpp
  - template/template.hpp
  isVerificationFile: true
  path: data_structure/test/wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-01-13 18:43:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: data_structure/test/wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/data_structure/test/wavelet_matrix.test.cpp
- /verify/data_structure/test/wavelet_matrix.test.cpp.html
title: data_structure/test/wavelet_matrix.test.cpp
---