---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/inverse_matrix.hpp
    title: algebra/inverse_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/matrix.hpp
    title: algebra/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  - icon: ':heavy_check_mark:'
    path: template/fastio.hpp
    title: template/fastio.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"algebra/test/inverse_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/inverse_matrix\"\n#line 1 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#define OVERRIDE(a, b, c, d, ...) d\n#define REP2(i,\
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
    #line 3 \"template/fastio.hpp\"\n#include <type_traits>\n#line 5 \"template/fastio.hpp\"\
    \n\n// unable to read INT_MIN (int), LLONG_MIN (long long)\nclass Reader {\n \
    \   FILE *fp;\n    static constexpr int BUF = 1 << 18;\n    char buf[BUF];\n \
    \   char *pl, *pr;\n\n    void reread() {\n        int wd = pr - pl;\n       \
    \ std::memcpy(buf, pl, wd);\n        pl = buf;\n        pr = buf + wd;\n     \
    \   pr += std::fread(pr, 1, BUF - wd, fp);\n    }\n\n    char skip() {\n     \
    \   char ch = *pl++;\n        while (ch <= ' ') {\n            ch = *pl++;\n \
    \       }\n        return ch;\n    }\n\n    template <typename T>\n    void read_unsigned(T\
    \ &x) {\n        if (pr - pl < 64) {\n            reread();\n        }\n     \
    \   x = 0;\n        char ch = skip();\n        while ('0' <= ch) {\n         \
    \   x = 10 * x + (0xf & ch);\n            ch = *pl++;\n        }\n    }\n    template\
    \ <typename T>\n    void read_signed(T &x) {\n        if (pr - pl < 64) {\n  \
    \          reread();\n        }\n        x = 0;\n        bool neg = false;\n \
    \       char ch = skip();\n        if (ch == '-') {\n            ch = *pl++;\n\
    \            neg = true;\n        }\n        while ('0' <= ch) {\n           \
    \ x = 10 * x + (0xf & ch);\n            ch = *pl++;\n        }\n        if (neg)\
    \ {\n            x = -x;\n        }\n    }\n\n    void read_single(int &x) { read_signed(x);\
    \ }\n    void read_single(unsigned &x) { read_unsigned(x); }\n    void read_single(long\
    \ &x) { read_signed(x); }\n    void read_single(unsigned long &x) { read_signed(x);\
    \ }\n    void read_single(long long &x) { read_signed(x); }\n    void read_single(unsigned\
    \ long long &x) { read_unsigned(x); }\n\npublic:\n    Reader(FILE *fp) : fp(fp),\
    \ pl(buf), pr(buf) { reread(); }\n\n    void read() {}\n    template <typename\
    \ Head, typename... Tail>\n    void read(Head &head, Tail &...tail) {\n      \
    \  read_single(head);\n        read(tail...);\n    }\n};\n\nstruct NumberToString\
    \ {\n    char buf[10000][4];\n    constexpr NumberToString() : buf() {\n     \
    \   for (int i = 0; i < 10000; ++i) {\n            int n = i;\n            for\
    \ (int j = 3; j >= 0; --j) {\n                buf[i][j] = '0' + n % 10;\n    \
    \            n /= 10;\n            }\n        }\n    }\n} constexpr number_to_string_precalc;\n\
    \nclass Writer {\n    FILE *fp;\n    static constexpr int BUF = 1 << 18;\n   \
    \ char buf[BUF];\n    char *ptr;\n\n    void write_u32(unsigned x) {\n       \
    \ if ((buf + BUF - ptr) < 32) {\n            flush();\n        }\n        static\
    \ char sml[12];\n        int t = 8;\n        while (x >= 10000) {\n          \
    \  unsigned n = x % 10000;\n            x /= 10000;\n            std::memcpy(sml\
    \ + t, number_to_string_precalc.buf[n], 4);\n            t -= 4;\n        }\n\
    \        if (x >= 1000) {\n            std::memcpy(ptr, number_to_string_precalc.buf[x],\
    \ 4);\n            ptr += 4;\n        } else if (x >= 100) {\n            std::memcpy(ptr,\
    \ number_to_string_precalc.buf[x] + 1, 3);\n            ptr += 3;\n        } else\
    \ if (x >= 10) {\n            unsigned q = (x * 103) >> 10;\n            *ptr++\
    \ = q | '0';\n            *ptr++ = (x - 10 * q) | '0';\n        } else {\n   \
    \         *ptr++ = '0' | x;\n        }\n        std::memcpy(ptr, sml + (t + 4),\
    \ 8 - t);\n        ptr += 8 - t;\n    }\n\n    void write_u64(unsigned long long\
    \ x) {\n        if ((buf + BUF - ptr) < 32) {\n            flush();\n        }\n\
    \        if (x >= 10000000000000000) {\n            unsigned long long z = x %\
    \ 100000000;\n            x /= 100000000;\n            unsigned long long y =\
    \ x % 100000000;\n            x /= 100000000;\n            if (x >= 1000) {\n\
    \                std::memcpy(ptr, number_to_string_precalc.buf[x], 4);\n     \
    \           ptr += 4;\n            } else if (x >= 100) {\n                std::memcpy(ptr,\
    \ number_to_string_precalc.buf[x] + 1, 3);\n                ptr += 3;\n      \
    \      } else if (x >= 10) {\n                unsigned q = (x * 103) >> 10;\n\
    \                *ptr++ = q | '0';\n                *ptr++ = (x - 10 * q) | '0';\n\
    \            } else {\n                *ptr++ = '0' | x;\n            }\n    \
    \        std::memcpy(ptr, number_to_string_precalc.buf[y / 10000], 4);\n     \
    \       std::memcpy(ptr + 4, number_to_string_precalc.buf[y % 10000], 4);\n  \
    \          std::memcpy(ptr + 8, number_to_string_precalc.buf[z / 10000], 4);\n\
    \            std::memcpy(ptr + 12, number_to_string_precalc.buf[z % 10000], 4);\n\
    \            ptr += 16;\n        } else {\n            static char sml[12];\n\
    \            int t = 8;\n            while (x >= 10000) {\n                unsigned\
    \ long long n = x % 10000;\n                x /= 10000;\n                std::memcpy(sml\
    \ + t, number_to_string_precalc.buf[n], 4);\n                t -= 4;\n       \
    \     }\n            if (x >= 1000) {\n                std::memcpy(ptr, number_to_string_precalc.buf[x],\
    \ 4);\n                ptr += 4;\n            } else if (x >= 100) {\n       \
    \         std::memcpy(ptr, number_to_string_precalc.buf[x] + 1, 3);\n        \
    \        ptr += 3;\n            } else if (x >= 10) {\n                unsigned\
    \ q = (x * 103) >> 10;\n                *ptr++ = q | '0';\n                *ptr++\
    \ = (x - 10 * q) | '0';\n            } else {\n                *ptr++ = '0' |\
    \ x;\n            }\n            std::memcpy(ptr, sml + (t + 4), 8 - t);\n   \
    \         ptr += 8 - t;\n        }\n    }\n\n    void write_char(char c) {\n \
    \       if (ptr == buf + BUF) {\n            flush();\n        }\n        *ptr++\
    \ = c;\n    }\n\n    template <typename T>\n    void write_unsigned(T x) {\n \
    \       if constexpr (std::is_same_v<T, unsigned long long> ||\n             \
    \         std::is_same_v<T, unsigned long>) {\n            write_u64(x);\n   \
    \     } else {\n            write_u32(x);\n        }\n    }\n\n    template <typename\
    \ T>\n    void write_signed(T x) {\n        std::make_unsigned_t<T> y = x;\n \
    \       if (x < 0) {\n            write_char('-');\n            y = -y;\n    \
    \    }\n        write_unsigned(y);\n    }\n\n    void write_single(int x) { write_signed(x);\
    \ }\n    void write_single(unsigned x) { write_unsigned(x); }\n    void write_single(long\
    \ x) { write_signed(x); }\n    void write_single(unsigned long x) { write_unsigned(x);\
    \ }\n    void write_single(long long x) { write_signed(x); }\n    void write_single(unsigned\
    \ long long x) { write_unsigned(x); }\n    void write_single(char c) { write_char(c);\
    \ }\n\npublic:\n    Writer(FILE *fp) : fp(fp), ptr(buf) {}\n    ~Writer() { flush();\
    \ }\n\n    void flush() {\n        std::fwrite(buf, 1, ptr - buf, fp);\n     \
    \   ptr = buf;\n    }\n\n    void write() {}\n    template <typename Head, typename...\
    \ Tail>\n    void write(Head &&head, Tail &&...tail) {\n        write_single(head);\n\
    \        if (sizeof...(Tail)) {\n            write_char(' ');\n        }\n   \
    \     write(std::forward<Tail>(tail)...);\n    }\n\n    template <typename...\
    \ T>\n    void writeln(T &&...t) {\n        write(std::forward<T>(t)...);\n  \
    \      write_char('\\n');\n    }\n};\n\nReader rd(stdin);\nWriter wr(stdout);\n\
    #line 2 \"algebra/inverse_matrix.hpp\"\n#include <optional>\n#line 5 \"algebra/matrix.hpp\"\
    \ntemplate <typename T>\nclass Matrix {\n    int _h, _w;\n    std::vector<std::vector<T>>\
    \ dat;\n\npublic:\n    Matrix() : dat() {}\n    Matrix(int n) : _h(n), _w(n),\
    \ dat(n, std::vector<T>(n, T())) {\n        assert(0 <= n);\n    }\n    Matrix(int\
    \ _h, int _w) : _h(_h), _w(_w), dat(_h, std::vector<T>(_w, T())) {\n        assert(0\
    \ <= _h && 0 <= _w);\n    }\n    static Matrix<T> ident(int n) {\n        assert(0\
    \ <= n);\n        Matrix<T> ret(n);\n        for (int i = 0; i < n; ++i) {\n \
    \           ret.dat[i][i] = T(1);\n        }\n        return ret;\n    }\n   \
    \ int h() const { return _h; }\n    int w() const { return _w; }\n    std::pair<int,\
    \ int> shape() const { return std::pair<int, int>(_h, _w); }\n    const T &operator()(int\
    \ i, int j) const {\n        assert(0 <= i && i < _h && 0 <= j && j < _w);\n \
    \       return dat[i][j];\n    }\n    T &operator()(int i, int j) {\n        assert(0\
    \ <= i && i < _h && 0 <= j && j < _w);\n        return dat[i][j];\n    }\n   \
    \ void swap_row(int i, int j) {\n        assert(0 <= i && i < _h && 0 <= j &&\
    \ j < _h);\n        std::swap(dat[i], dat[j]);\n    }\n    void swap_column(int\
    \ i, int j) {\n        assert(0 <= i && i < _w && 0 <= j && j < _w);\n       \
    \ for (int k = 0; k < _h; ++k) {\n            std::swap(dat[k][i], dat[k][j]);\n\
    \        }\n    }\n    Matrix<T> &operator+=(const Matrix<T> &rhs) {\n       \
    \ assert(shape() == rhs.shape());\n        for (int i = 0; i < _h; ++i) {\n  \
    \          for (int j = 0; j < _w; ++j) {\n                dat[i][j] += rhs.dat[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    Matrix<T> &operator-=(const\
    \ Matrix<T> &rhs) {\n        assert(shape() == rhs.shape());\n        for (int\
    \ i = 0; i < _h; ++i) {\n            for (int j = 0; j < _w; ++j) {\n        \
    \        dat[i][j] -= rhs.dat[i][j];\n            }\n        }\n        return\
    \ *this;\n    }\n    Matrix<T> &operator*=(const Matrix<T> &rhs) { return *this\
    \ = *this * rhs; }\n    friend Matrix<T> operator+(Matrix<T> lhs, const Matrix<T>\
    \ &rhs) {\n        return lhs += rhs;\n    }\n    friend Matrix<T> operator-(Matrix<T>\
    \ lhs, const Matrix<T> &rhs) {\n        return lhs -= rhs;\n    }\n    friend\
    \ Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {\n        assert(lhs._w\
    \ == rhs._h);\n        std::vector<std::vector<T>> dat(lhs._h, std::vector<T>(rhs._w,\
    \ T()));\n        for (int i = 0; i < lhs._h; ++i) {\n            for (int j =\
    \ 0; j < rhs._w; ++j) {\n                for (int k = 0; k < lhs._w; ++k) {\n\
    \                    dat[i][j] += lhs.dat[i][k] * rhs.dat[k][j];\n           \
    \     }\n            }\n        }\n        Matrix<T> ret;\n        ret._h = lhs._h;\n\
    \        ret._w = rhs._w;\n        ret.dat = dat;\n        return ret;\n    }\n\
    };\n#line 4 \"algebra/inverse_matrix.hpp\"\ntemplate <typename T>\nstd::optional<Matrix<T>>\
    \ inverse_matrix(Matrix<T> a) {\n    assert(a.h() == a.w());\n    int n = a.h();\n\
    \    Matrix<T> b = Matrix<T>::ident(n);\n    for (int i = 0; i < n; ++i) {\n \
    \       int row = -1;\n        for (int j = i; j < n; ++j) {\n            if (a(j,\
    \ i) != T()) {\n                row = j;\n                break;\n           \
    \ }\n        }\n        if (row == -1) {\n            return std::nullopt;\n \
    \       }\n        a.swap_row(i, row);\n        b.swap_row(i, row);\n        T\
    \ inv = T(1) / a(i, i);\n        for (int j = i; j < n; ++j) {\n            a(i,\
    \ j) *= inv;\n        }\n        for (int j = 0; j < n; ++j) {\n            b(i,\
    \ j) *= inv;\n        }\n        for (int j = 0; j < n; ++j) {\n            if\
    \ (j == i) {\n                continue;\n            }\n            T cf = a(j,\
    \ i);\n            for (int k = i; k < n; ++k) {\n                a(j, k) -= a(i,\
    \ k) * cf;\n            }\n            for (int k = 0; k < n; ++k) {\n       \
    \         b(j, k) -= b(i, k) * cf;\n            }\n        }\n    }\n    return\
    \ b;\n}\n#line 2 \"number_theory/mod_int.hpp\"\n\n#line 2 \"number_theory/utils.hpp\"\
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
    \ x) {\n    std::cerr << x.val;\n}\n#line 6 \"algebra/test/inverse_matrix.test.cpp\"\
    \n\nint main() {\n    using M = ModInt<998244353>;\n    i32 n;\n    rd.read(n);\n\
    \    Matrix<M> a(n);\n    REP(i, n) REP(j, n) {\n        rd.read(a(i, j).val);\n\
    \    }\n    optional<Matrix<M>> b = inverse_matrix(a);\n    if (b.has_value())\
    \ {\n        REP(i, n) REP(j, n) {\n            wr.write(b->operator()(i, j).val);\n\
    \            wr.write(\" \\n\"[j + 1 == n]);\n        }\n    } else {\n      \
    \  wr.writeln(-1);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../template/fastio.hpp\"\n#include\
    \ \"../../algebra/inverse_matrix.hpp\"\n#include \"../../number_theory/mod_int.hpp\"\
    \n\nint main() {\n    using M = ModInt<998244353>;\n    i32 n;\n    rd.read(n);\n\
    \    Matrix<M> a(n);\n    REP(i, n) REP(j, n) {\n        rd.read(a(i, j).val);\n\
    \    }\n    optional<Matrix<M>> b = inverse_matrix(a);\n    if (b.has_value())\
    \ {\n        REP(i, n) REP(j, n) {\n            wr.write(b->operator()(i, j).val);\n\
    \            wr.write(\" \\n\"[j + 1 == n]);\n        }\n    } else {\n      \
    \  wr.writeln(-1);\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/fastio.hpp
  - algebra/inverse_matrix.hpp
  - algebra/matrix.hpp
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  isVerificationFile: true
  path: algebra/test/inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-04-17 20:50:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: algebra/test/inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/algebra/test/inverse_matrix.test.cpp
- /verify/algebra/test/inverse_matrix.test.cpp.html
title: algebra/test/inverse_matrix.test.cpp
---