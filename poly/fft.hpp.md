---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/mod_int.hpp
    title: number_theory/mod_int.hpp
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/stirling1.hpp
    title: poly/stirling1.hpp
  - icon: ':heavy_check_mark:'
    path: poly/stirling2.hpp
    title: poly/stirling2.hpp
  - icon: ':heavy_check_mark:'
    path: poly/taylor_shift.hpp
    title: poly/taylor_shift.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: poly/test/convolution_mod.test.cpp
    title: poly/test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/polynomial_taylor_shift.test.cpp
    title: poly/test/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/stirling_number_of_the_first_kind.test.cpp
    title: poly/test/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: poly/test/stirling_number_of_the_second_kind.test.cpp
    title: poly/test/stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/fft.hpp\"\n#include <array>\n#include <vector>\n#line\
    \ 2 \"number_theory/mod_int.hpp\"\n\n#include <cassert>\n#include <iostream>\n\
    #include <type_traits>\n#line 2 \"number_theory/utils.hpp\"\n\n#include <utility>\n\
    \nconstexpr bool is_prime(unsigned n) {\n    if (n == 0 || n == 1) {\n       \
    \ return false;\n    }\n    for (unsigned i = 2; i * i <= n; ++i) {\n        if\
    \ (n % i == 0) {\n            return false;\n        }\n    }\n    return true;\n\
    }\n\nconstexpr unsigned mod_pow(unsigned x, unsigned y, unsigned mod) {\n    unsigned\
    \ ret = 1, self = x;\n    while (y != 0) {\n        if (y & 1) {\n           \
    \ ret = (unsigned)((unsigned long long)ret * self % mod);\n        }\n       \
    \ self = (unsigned)((unsigned long long)self * self % mod);\n        y /= 2;\n\
    \    }\n    return ret;\n}\n\ntemplate <unsigned mod>\nconstexpr unsigned primitive_root()\
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
    \ -(-x / y);\n    }\n}\n\n// b >= 1\n// returns (g, x) s.t. g = gcd(a, b), a *\
    \ x = g (mod b), 0 <= x < b / g\n// from ACL\ntemplate <typename T>\nstd::pair<T,\
    \ T> extgcd(T a, T b) {\n    a = safe_mod(a, b);\n    T s = b, t = a, m0 = 0,\
    \ m1 = 1;\n    while (t) {\n        T u = s / t;\n        s -= t * u;\n      \
    \  m0 -= m1 * u;\n        std::swap(s, t);\n        std::swap(m0, m1);\n    }\n\
    \    if (m0 < 0) {\n        m0 += b / s;\n    }\n    return std::pair<T, T>(s,\
    \ m0);\n}\n\n// b >= 1\n// returns (g, x, y) s.t. g = gcd(a, b), a * x + b * y\
    \ = g, 0 <= x < b / g, |y| < max(2, |a| / g)\ntemplate <typename T>\nstd::tuple<T,\
    \ T, T> extgcd2(T a, T b) {\n    T _a = safe_mod(a, b);\n    T quot = (a - _a)\
    \ / b;\n    T x00 = 0, x01 = 1, y0 = b;\n    T x10 = 1, x11 = -quot, y1 = _a;\n\
    \    while (y1) {\n        T u = y0 / y1;\n        x00 -= u * x10;\n        x01\
    \ -= u * x11;\n        y0 -= u * y1;\n        std::swap(x00, x10);\n        std::swap(x01,\
    \ x11);\n        std::swap(y0, y1);\n    }\n    if (x00 < 0) {\n        x00 +=\
    \ b / y0;\n        x01 -= a / y0;\n    }\n    return std::tuple<T, T, T>(y0, x00,\
    \ x01);\n}\n\n// gcd(x, m) == 1\ntemplate <typename T>\nT inv_mod(T x, T m) {\n\
    \    return extgcd(x, m).second;\n}\n#line 7 \"number_theory/mod_int.hpp\"\n\n\
    template <unsigned mod>\nstruct ModInt {\n    static_assert(mod != 0, \"`mod`\
    \ must not be equal to 0.\");\n    static_assert(mod < (1u << 31),\n         \
    \         \"`mod` must be less than (1u << 31) = 2147483648.\");\n\n    unsigned\
    \ val;\n\n    static constexpr unsigned get_mod() { return mod; }\n\n    constexpr\
    \ ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
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
    \ x) {\n    std::cerr << x.val;\n}\n#line 5 \"poly/fft.hpp\"\n\nconstexpr int\
    \ ctz_constexpr(unsigned n) {\n    int x = 0;\n    while (!(n & (1u << x))) {\n\
    \        ++x;\n    }\n    return x;\n}\n\ntemplate <unsigned MOD>\nstruct FFTRoot\
    \ {\n    static constexpr unsigned R = ctz_constexpr(MOD - 1);\n    std::array<ModInt<MOD>,\
    \ R + 1> root, iroot;\n    std::array<ModInt<MOD>, R> rate2, irate2;\n    std::array<ModInt<MOD>,\
    \ R - 1> rate3, irate3;\n    std::array<ModInt<MOD>, R + 1> inv2;\n\n    constexpr\
    \ FFTRoot() : root{}, iroot{}, rate2{}, irate2{}, rate3{}, irate3{}, inv2{} {\n\
    \        unsigned pr = primitive_root<MOD>();\n        root[R] = ModInt<MOD>(pr).pow(MOD\
    \ >> R);\n        iroot[R] = root[R].inv();\n        for (int i = R - 1; i >=\
    \ 0; --i) {\n            root[i] = root[i + 1] * root[i + 1];\n            iroot[i]\
    \ = iroot[i + 1] * iroot[i + 1];\n        }\n        ModInt<MOD> prod(1), iprod(1);\n\
    \        for (int i = 0; i < (int)R - 1; ++i) {\n            rate2[i] = prod *\
    \ root[i + 2];\n            irate2[i] = iprod * iroot[i + 2];\n            prod\
    \ *= iroot[i + 2];\n            iprod *= root[i + 2];\n        }\n        prod\
    \ = ModInt<MOD>(1);\n        iprod = ModInt<MOD>(1);\n        for (int i = 0;\
    \ i < (int)R - 2; ++i) {\n            rate3[i] = prod * root[i + 3];\n       \
    \     irate3[i] = iprod * iroot[i + 3];\n            prod *= iroot[i + 3];\n \
    \           iprod *= root[i + 3];\n        }\n        ModInt<MOD> i2 = ModInt<MOD>(2).inv();\n\
    \        inv2[0] = ModInt<MOD>(1);\n        for (int i = 0; i < (int)R; ++i) {\n\
    \            inv2[i + 1] = inv2[i] * i2;\n        }\n    }\n};\n\ntemplate <typename\
    \ M>\nvoid fft(std::vector<M> &a) {\n    using ull = unsigned long long;\n   \
    \ static_assert(M::get_mod() < (1u << 30));\n    static constexpr FFTRoot<M::get_mod()>\
    \ fftroot;\n    static constexpr ull CEIL = 2ULL * M::get_mod() * M::get_mod();\n\
    \    int n = (int)a.size();\n    int l = __builtin_ctz(n);\n    int ph = 0;\n\
    \    while (ph < l) {\n        if (ph + 1 == l) {\n            int b = 1 << ph;\n\
    \            M z = M::raw(1);\n            for (int i = 0; i < b; ++i) {\n   \
    \             int offset = i << 1;\n                M x = a[offset];\n       \
    \         M y = a[offset + 1] * z;\n                a[offset] = x + y;\n     \
    \           a[offset + 1] = x - y;\n                z *= fftroot.rate2[__builtin_ctz(~i)];\n\
    \            }\n            ++ph;\n        } else {\n            int bl = 1 <<\
    \ ph;\n            int wd = 1 << (l - 2 - ph);\n            M zeta = M::raw(1);\n\
    \            for (int i = 0; i < bl; ++i) {\n                int offset = i <<\
    \ (l - ph);\n                M zeta2 = zeta * zeta;\n                M zeta3 =\
    \ zeta2 * zeta;\n                for (int j = 0; j < wd; ++j) {\n            \
    \        ull w = a[offset + j].val;\n                    ull x = (ull)a[offset\
    \ + j + wd].val * zeta.val;\n                    ull y = (ull)a[offset + j + 2\
    \ * wd].val * zeta2.val;\n                    ull z = (ull)a[offset + j + 3 *\
    \ wd].val * zeta3.val;\n                    ull ix_m_iz = (CEIL + x - z) % M::get_mod()\
    \ * fftroot.root[2].val;\n                    a[offset + j] = M(w + x + y + z);\n\
    \                    a[offset + j + wd] = M(CEIL + w - x + y - z);\n         \
    \           a[offset + j + 2 * wd] = M(CEIL + w - y + ix_m_iz);\n            \
    \        a[offset + j + 3 * wd] = M(CEIL + w - y - ix_m_iz);\n               \
    \ }\n                zeta *= fftroot.rate3[__builtin_ctz(~i)];\n            }\n\
    \            ph += 2;\n        }\n    }\n}\n\ntemplate <typename M>\nvoid ifft(std::vector<M>\
    \ &a) {\n    using ull = unsigned long long;\n    static_assert(M::get_mod() <\
    \ (1u << 30));\n    static constexpr FFTRoot<M::get_mod()> fftroot;\n    int n\
    \ = (int)a.size();\n    int l = __builtin_ctz(n);\n    int ph = l;\n    while\
    \ (ph > 0) {\n        if (ph == 1) {\n            --ph;\n            int wd =\
    \ 1 << (l - 1);\n            for (int i = 0; i < wd; ++i) {\n                M\
    \ x = a[i];\n                M y = a[i + wd];\n                a[i] = x + y;\n\
    \                a[i + wd] = x - y;\n            }\n        } else {\n       \
    \     ph -= 2;\n            int bl = 1 << ph;\n            int wd = 1 << (l -\
    \ 2 - ph);\n            M zeta = M::raw(1);\n            for (int i = 0; i < bl;\
    \ ++i) {\n                int offset = i << (l - ph);\n                M zeta2\
    \ = zeta * zeta;\n                M zeta3 = zeta2 * zeta;\n                for\
    \ (int j = 0; j < wd; ++j) {\n                    unsigned w = a[offset + j].val;\n\
    \                    unsigned x = a[offset + j + wd].val;\n                  \
    \  unsigned y = a[offset + j + 2 * wd].val;\n                    unsigned z =\
    \ a[offset + j + 3 * wd].val;\n                    unsigned iy_m_iz = (ull)(M::get_mod()\
    \ + y - z) * fftroot.root[2].val % M::get_mod();\n                    a[offset\
    \ + j] = M(w + x + y + z);\n                    a[offset + j + wd] = M((ull)zeta.val\
    \ * (2 * M::get_mod() + w - x - iy_m_iz));\n                    a[offset + j +\
    \ 2 * wd] = M((ull)zeta2.val * (2 * M::get_mod() + w + x - y - z));\n        \
    \            a[offset + j + 3 * wd] = M((ull)zeta3.val * (M::get_mod() + w - x\
    \ + iy_m_iz));\n                }\n                zeta *= fftroot.irate3[__builtin_ctz(~i)];\n\
    \            }\n        }\n    }\n    for (M &ele : a) {\n        ele *= fftroot.inv2[l];\n\
    \    }\n}\n\ntemplate <typename M>\nstd::vector<M> convolve_naive(const std::vector<M>\
    \ &a,\n                              const std::vector<M> &b) {\n    int n = (int)a.size();\n\
    \    int m = (int)b.size();\n    std::vector<M> c(n + m - 1);\n    if (n < m)\
    \ {\n        for (int j = 0; j < m; ++j) {\n            for (int i = 0; i < n;\
    \ ++i) {\n                c[i + j] += a[i] * b[j];\n            }\n        }\n\
    \    } else {\n        for (int i = 0; i < n; ++i) {\n            for (int j =\
    \ 0; j < m; ++j) {\n                c[i + j] += a[i] * b[j];\n            }\n\
    \        }\n    }\n    return c;\n}\n\ntemplate <typename M>\nstd::vector<M> convolve_fft(std::vector<M>\
    \ a, std::vector<M> b) {\n    int n = (int)a.size() + (int)b.size() - 1;\n   \
    \ int m = 1;\n    while (m < n) {\n        m <<= 1;\n    }\n    bool shr = false;\n\
    \    M last;\n    if (n >= 3 && n == m / 2 + 1) {\n        shr = true;\n     \
    \   last = a.back() * b.back();\n        m /= 2;\n        while ((int)a.size()\
    \ > m) {\n            a[(int)a.size() - 1 - m] += a.back();\n            a.pop_back();\n\
    \        }\n        while ((int)b.size() > m) {\n            b[(int)b.size() -\
    \ 1 - m] += b.back();\n            b.pop_back();\n        }\n    }\n    a.resize(m);\n\
    \    b.resize(m);\n    fft(a);\n    fft(b);\n    for (int i = 0; i < m; ++i) {\n\
    \        a[i] *= b[i];\n    }\n    ifft(a);\n    a.resize(n);\n    if (shr) {\n\
    \        a[0] -= last;\n        a[n - 1] = last;\n    }\n    return a;\n}\n\n\
    template <typename M>\nstd::vector<M> convolve(const std::vector<M> &a, const\
    \ std::vector<M> &b) {\n    if (a.empty() || b.empty()) {\n        return std::vector<M>(0);\n\
    \    }\n    if (std::min(a.size(), b.size()) <= 60) {\n        return convolve_naive(a,\
    \ b);\n    } else {\n        return convolve_fft(a, b);\n    }\n}\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include \"../number_theory/mod_int.hpp\"\
    \n\nconstexpr int ctz_constexpr(unsigned n) {\n    int x = 0;\n    while (!(n\
    \ & (1u << x))) {\n        ++x;\n    }\n    return x;\n}\n\ntemplate <unsigned\
    \ MOD>\nstruct FFTRoot {\n    static constexpr unsigned R = ctz_constexpr(MOD\
    \ - 1);\n    std::array<ModInt<MOD>, R + 1> root, iroot;\n    std::array<ModInt<MOD>,\
    \ R> rate2, irate2;\n    std::array<ModInt<MOD>, R - 1> rate3, irate3;\n    std::array<ModInt<MOD>,\
    \ R + 1> inv2;\n\n    constexpr FFTRoot() : root{}, iroot{}, rate2{}, irate2{},\
    \ rate3{}, irate3{}, inv2{} {\n        unsigned pr = primitive_root<MOD>();\n\
    \        root[R] = ModInt<MOD>(pr).pow(MOD >> R);\n        iroot[R] = root[R].inv();\n\
    \        for (int i = R - 1; i >= 0; --i) {\n            root[i] = root[i + 1]\
    \ * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n      \
    \  }\n        ModInt<MOD> prod(1), iprod(1);\n        for (int i = 0; i < (int)R\
    \ - 1; ++i) {\n            rate2[i] = prod * root[i + 2];\n            irate2[i]\
    \ = iprod * iroot[i + 2];\n            prod *= iroot[i + 2];\n            iprod\
    \ *= root[i + 2];\n        }\n        prod = ModInt<MOD>(1);\n        iprod =\
    \ ModInt<MOD>(1);\n        for (int i = 0; i < (int)R - 2; ++i) {\n          \
    \  rate3[i] = prod * root[i + 3];\n            irate3[i] = iprod * iroot[i + 3];\n\
    \            prod *= iroot[i + 3];\n            iprod *= root[i + 3];\n      \
    \  }\n        ModInt<MOD> i2 = ModInt<MOD>(2).inv();\n        inv2[0] = ModInt<MOD>(1);\n\
    \        for (int i = 0; i < (int)R; ++i) {\n            inv2[i + 1] = inv2[i]\
    \ * i2;\n        }\n    }\n};\n\ntemplate <typename M>\nvoid fft(std::vector<M>\
    \ &a) {\n    using ull = unsigned long long;\n    static_assert(M::get_mod() <\
    \ (1u << 30));\n    static constexpr FFTRoot<M::get_mod()> fftroot;\n    static\
    \ constexpr ull CEIL = 2ULL * M::get_mod() * M::get_mod();\n    int n = (int)a.size();\n\
    \    int l = __builtin_ctz(n);\n    int ph = 0;\n    while (ph < l) {\n      \
    \  if (ph + 1 == l) {\n            int b = 1 << ph;\n            M z = M::raw(1);\n\
    \            for (int i = 0; i < b; ++i) {\n                int offset = i <<\
    \ 1;\n                M x = a[offset];\n                M y = a[offset + 1] *\
    \ z;\n                a[offset] = x + y;\n                a[offset + 1] = x -\
    \ y;\n                z *= fftroot.rate2[__builtin_ctz(~i)];\n            }\n\
    \            ++ph;\n        } else {\n            int bl = 1 << ph;\n        \
    \    int wd = 1 << (l - 2 - ph);\n            M zeta = M::raw(1);\n          \
    \  for (int i = 0; i < bl; ++i) {\n                int offset = i << (l - ph);\n\
    \                M zeta2 = zeta * zeta;\n                M zeta3 = zeta2 * zeta;\n\
    \                for (int j = 0; j < wd; ++j) {\n                    ull w = a[offset\
    \ + j].val;\n                    ull x = (ull)a[offset + j + wd].val * zeta.val;\n\
    \                    ull y = (ull)a[offset + j + 2 * wd].val * zeta2.val;\n  \
    \                  ull z = (ull)a[offset + j + 3 * wd].val * zeta3.val;\n    \
    \                ull ix_m_iz = (CEIL + x - z) % M::get_mod() * fftroot.root[2].val;\n\
    \                    a[offset + j] = M(w + x + y + z);\n                    a[offset\
    \ + j + wd] = M(CEIL + w - x + y - z);\n                    a[offset + j + 2 *\
    \ wd] = M(CEIL + w - y + ix_m_iz);\n                    a[offset + j + 3 * wd]\
    \ = M(CEIL + w - y - ix_m_iz);\n                }\n                zeta *= fftroot.rate3[__builtin_ctz(~i)];\n\
    \            }\n            ph += 2;\n        }\n    }\n}\n\ntemplate <typename\
    \ M>\nvoid ifft(std::vector<M> &a) {\n    using ull = unsigned long long;\n  \
    \  static_assert(M::get_mod() < (1u << 30));\n    static constexpr FFTRoot<M::get_mod()>\
    \ fftroot;\n    int n = (int)a.size();\n    int l = __builtin_ctz(n);\n    int\
    \ ph = l;\n    while (ph > 0) {\n        if (ph == 1) {\n            --ph;\n \
    \           int wd = 1 << (l - 1);\n            for (int i = 0; i < wd; ++i) {\n\
    \                M x = a[i];\n                M y = a[i + wd];\n             \
    \   a[i] = x + y;\n                a[i + wd] = x - y;\n            }\n       \
    \ } else {\n            ph -= 2;\n            int bl = 1 << ph;\n            int\
    \ wd = 1 << (l - 2 - ph);\n            M zeta = M::raw(1);\n            for (int\
    \ i = 0; i < bl; ++i) {\n                int offset = i << (l - ph);\n       \
    \         M zeta2 = zeta * zeta;\n                M zeta3 = zeta2 * zeta;\n  \
    \              for (int j = 0; j < wd; ++j) {\n                    unsigned w\
    \ = a[offset + j].val;\n                    unsigned x = a[offset + j + wd].val;\n\
    \                    unsigned y = a[offset + j + 2 * wd].val;\n              \
    \      unsigned z = a[offset + j + 3 * wd].val;\n                    unsigned\
    \ iy_m_iz = (ull)(M::get_mod() + y - z) * fftroot.root[2].val % M::get_mod();\n\
    \                    a[offset + j] = M(w + x + y + z);\n                    a[offset\
    \ + j + wd] = M((ull)zeta.val * (2 * M::get_mod() + w - x - iy_m_iz));\n     \
    \               a[offset + j + 2 * wd] = M((ull)zeta2.val * (2 * M::get_mod()\
    \ + w + x - y - z));\n                    a[offset + j + 3 * wd] = M((ull)zeta3.val\
    \ * (M::get_mod() + w - x + iy_m_iz));\n                }\n                zeta\
    \ *= fftroot.irate3[__builtin_ctz(~i)];\n            }\n        }\n    }\n   \
    \ for (M &ele : a) {\n        ele *= fftroot.inv2[l];\n    }\n}\n\ntemplate <typename\
    \ M>\nstd::vector<M> convolve_naive(const std::vector<M> &a,\n               \
    \               const std::vector<M> &b) {\n    int n = (int)a.size();\n    int\
    \ m = (int)b.size();\n    std::vector<M> c(n + m - 1);\n    if (n < m) {\n   \
    \     for (int j = 0; j < m; ++j) {\n            for (int i = 0; i < n; ++i) {\n\
    \                c[i + j] += a[i] * b[j];\n            }\n        }\n    } else\
    \ {\n        for (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m;\
    \ ++j) {\n                c[i + j] += a[i] * b[j];\n            }\n        }\n\
    \    }\n    return c;\n}\n\ntemplate <typename M>\nstd::vector<M> convolve_fft(std::vector<M>\
    \ a, std::vector<M> b) {\n    int n = (int)a.size() + (int)b.size() - 1;\n   \
    \ int m = 1;\n    while (m < n) {\n        m <<= 1;\n    }\n    bool shr = false;\n\
    \    M last;\n    if (n >= 3 && n == m / 2 + 1) {\n        shr = true;\n     \
    \   last = a.back() * b.back();\n        m /= 2;\n        while ((int)a.size()\
    \ > m) {\n            a[(int)a.size() - 1 - m] += a.back();\n            a.pop_back();\n\
    \        }\n        while ((int)b.size() > m) {\n            b[(int)b.size() -\
    \ 1 - m] += b.back();\n            b.pop_back();\n        }\n    }\n    a.resize(m);\n\
    \    b.resize(m);\n    fft(a);\n    fft(b);\n    for (int i = 0; i < m; ++i) {\n\
    \        a[i] *= b[i];\n    }\n    ifft(a);\n    a.resize(n);\n    if (shr) {\n\
    \        a[0] -= last;\n        a[n - 1] = last;\n    }\n    return a;\n}\n\n\
    template <typename M>\nstd::vector<M> convolve(const std::vector<M> &a, const\
    \ std::vector<M> &b) {\n    if (a.empty() || b.empty()) {\n        return std::vector<M>(0);\n\
    \    }\n    if (std::min(a.size(), b.size()) <= 60) {\n        return convolve_naive(a,\
    \ b);\n    } else {\n        return convolve_fft(a, b);\n    }\n}\n"
  dependsOn:
  - number_theory/mod_int.hpp
  - number_theory/utils.hpp
  isVerificationFile: false
  path: poly/fft.hpp
  requiredBy:
  - poly/stirling1.hpp
  - poly/stirling2.hpp
  - poly/taylor_shift.hpp
  timestamp: '2024-04-08 20:24:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - poly/test/convolution_mod.test.cpp
  - poly/test/polynomial_taylor_shift.test.cpp
  - poly/test/stirling_number_of_the_second_kind.test.cpp
  - poly/test/stirling_number_of_the_first_kind.test.cpp
documentation_of: poly/fft.hpp
layout: document
redirect_from:
- /library/poly/fft.hpp
- /library/poly/fft.hpp.html
title: poly/fft.hpp
---
