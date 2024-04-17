---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: number_theory/utils.hpp
    title: number_theory/utils.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/fft.hpp
    title: poly/fft.hpp
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
    path: algebra/test/inverse_matrix.test.cpp
    title: algebra/test/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_det.test.cpp
    title: algebra/test/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_product.test.cpp
    title: algebra/test/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/1891.test.cpp
    title: data_structure/test/1891.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/point_set_range_composite.test.cpp
    title: data_structure/test/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/queue_operate_all_composite.test.cpp
    title: data_structure/test/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: data_structure/test/range_affine_range_sum.test.cpp
    title: data_structure/test/range_affine_range_sum.test.cpp
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
  bundledCode: "#line 2 \"number_theory/mod_int.hpp\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <type_traits>\n#line 2 \"number_theory/utils.hpp\"\n\n\
    #include <utility>\n\nconstexpr bool is_prime(unsigned n) {\n    if (n == 0 ||\
    \ n == 1) {\n        return false;\n    }\n    for (unsigned i = 2; i * i <= n;\
    \ ++i) {\n        if (n % i == 0) {\n            return false;\n        }\n  \
    \  }\n    return true;\n}\n\nconstexpr unsigned mod_pow(unsigned x, unsigned y,\
    \ unsigned mod) {\n    unsigned ret = 1, self = x;\n    while (y != 0) {\n   \
    \     if (y & 1) {\n            ret = (unsigned)((unsigned long long)ret * self\
    \ % mod);\n        }\n        self = (unsigned)((unsigned long long)self * self\
    \ % mod);\n        y /= 2;\n    }\n    return ret;\n}\n\ntemplate <unsigned mod>\n\
    constexpr unsigned primitive_root() {\n    static_assert(is_prime(mod), \"`mod`\
    \ must be a prime number.\");\n    if (mod == 2) {\n        return 1;\n    }\n\
    \n    unsigned primes[32] = {};\n    int it = 0;\n    {\n        unsigned m =\
    \ mod - 1;\n        for (unsigned i = 2; i * i <= m; ++i) {\n            if (m\
    \ % i == 0) {\n                primes[it++] = i;\n                while (m % i\
    \ == 0) {\n                    m /= i;\n                }\n            }\n   \
    \     }\n        if (m != 1) {\n            primes[it++] = m;\n        }\n   \
    \ }\n    for (unsigned i = 2; i < mod; ++i) {\n        bool ok = true;\n     \
    \   for (int j = 0; j < it; ++j) {\n            if (mod_pow(i, (mod - 1) / primes[j],\
    \ mod) == 1) {\n                ok = false;\n                break;\n        \
    \    }\n        }\n        if (ok) return i;\n    }\n    return 0;\n}\n\n// y\
    \ >= 1\ntemplate <typename T>\nconstexpr T safe_mod(T x, T y) {\n    x %= y;\n\
    \    if (x < 0) {\n        x += y;\n    }\n    return x;\n}\n\n// y != 0\ntemplate\
    \ <typename T>\nconstexpr T floor_div(T x, T y) {\n    if (y < 0) {\n        x\
    \ *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return x / y;\n\
    \    } else {\n        return -((-x + y - 1) / y);\n    }\n}\n\n// y != 0\ntemplate\
    \ <typename T>\nconstexpr T ceil_div(T x, T y) {\n    if (y < 0) {\n        x\
    \ *= -1;\n        y *= -1;\n    }\n    if (x >= 0) {\n        return (x + y -\
    \ 1) / y;\n    } else {\n        return -(-x / y);\n    }\n}\n\n// b >= 1\n//\
    \ returns (g, x) s.t. g = gcd(a, b), a * x = g (mod b), 0 <= x < b / g\n// from\
    \ ACL\ntemplate <typename T>\nstd::pair<T, T> extgcd(T a, T b) {\n    a = safe_mod(a,\
    \ b);\n    T s = b, t = a, m0 = 0, m1 = 1;\n    while (t) {\n        T u = s /\
    \ t;\n        s -= t * u;\n        m0 -= m1 * u;\n        std::swap(s, t);\n \
    \       std::swap(m0, m1);\n    }\n    if (m0 < 0) {\n        m0 += b / s;\n \
    \   }\n    return std::pair<T, T>(s, m0);\n}\n\n// b >= 1\n// returns (g, x, y)\
    \ s.t. g = gcd(a, b), a * x + b * y = g, 0 <= x < b / g, |y| < max(2, |a| / g)\n\
    template <typename T>\nstd::tuple<T, T, T> extgcd2(T a, T b) {\n    T _a = safe_mod(a,\
    \ b);\n    T quot = (a - _a) / b;\n    T x00 = 0, x01 = 1, y0 = b;\n    T x10\
    \ = 1, x11 = -quot, y1 = _a;\n    while (y1) {\n        T u = y0 / y1;\n     \
    \   x00 -= u * x10;\n        x01 -= u * x11;\n        y0 -= u * y1;\n        std::swap(x00,\
    \ x10);\n        std::swap(x01, x11);\n        std::swap(y0, y1);\n    }\n   \
    \ if (x00 < 0) {\n        x00 += b / y0;\n        x01 -= a / y0;\n    }\n    return\
    \ std::tuple<T, T, T>(y0, x00, x01);\n}\n\n// gcd(x, m) == 1\ntemplate <typename\
    \ T>\nT inv_mod(T x, T m) {\n    return extgcd(x, m).second;\n}\n#line 7 \"number_theory/mod_int.hpp\"\
    \n\ntemplate <unsigned mod>\nstruct ModInt {\n    static_assert(mod != 0, \"`mod`\
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
    \ x) {\n    std::cerr << x.val;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iostream>\n#include <type_traits>\n\
    #include \"utils.hpp\"\n\ntemplate <unsigned mod>\nstruct ModInt {\n    static_assert(mod\
    \ != 0, \"`mod` must not be equal to 0.\");\n    static_assert(mod < (1u << 31),\n\
    \                  \"`mod` must be less than (1u << 31) = 2147483648.\");\n\n\
    \    unsigned val;\n\n    static constexpr unsigned get_mod() { return mod; }\n\
    \n    constexpr ModInt() : val(0) {}\n    template <typename T, std::enable_if_t<std::is_signed_v<T>>\
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
    \ x) {\n    std::cerr << x.val;\n}"
  dependsOn:
  - number_theory/utils.hpp
  isVerificationFile: false
  path: number_theory/mod_int.hpp
  requiredBy:
  - poly/stirling1.hpp
  - poly/fft.hpp
  - poly/stirling2.hpp
  - poly/taylor_shift.hpp
  timestamp: '2024-03-29 12:47:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - poly/test/convolution_mod.test.cpp
  - poly/test/polynomial_taylor_shift.test.cpp
  - poly/test/stirling_number_of_the_second_kind.test.cpp
  - poly/test/stirling_number_of_the_first_kind.test.cpp
  - algebra/test/matrix_det.test.cpp
  - algebra/test/matrix_product.test.cpp
  - algebra/test/inverse_matrix.test.cpp
  - data_structure/test/range_affine_range_sum.test.cpp
  - data_structure/test/point_set_range_composite.test.cpp
  - data_structure/test/1891.test.cpp
  - data_structure/test/queue_operate_all_composite.test.cpp
documentation_of: number_theory/mod_int.hpp
layout: document
redirect_from:
- /library/number_theory/mod_int.hpp
- /library/number_theory/mod_int.hpp.html
title: number_theory/mod_int.hpp
---
