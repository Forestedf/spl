---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/rational.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #include <numeric>\ntemplate <typename T>\nstruct Rational {\n    T num, den;\n\
    \    Rational() : num(0), den(1) {}\n    Rational(T x) : num(x), den(1) {}\n \
    \   Rational(T n, T d) : num(n), den(d) {\n        T g = std::gcd(num, den);\n\
    \        num /= g;\n        den /= g;\n        if (den < 0) {\n            num\
    \ = -num;\n            den = -den;\n        }\n    }\n    static Rational<T> raw(T\
    \ num, T den) {\n        Rational<T> ret;\n        ret.num = num;\n        ret.den\
    \ = den;\n        return ret;\n    }\n    friend Rational<T> operator+(const Rational<T>\
    \ &lhs, const Rational<T> &rhs) {\n        return Rational<T>(lhs.num * rhs.den\
    \ + lhs.den * rhs.num, lhs.den * rhs.den);\n    }\n    friend Rational<T> operator-(const\
    \ Rational<T> &lhs, const Rational<T> &rhs) {\n        return Rational<T>(lhs.num\
    \ * rhs.den - lhs.den * rhs.num, lhs.den * rhs.den);\n    }\n    friend Rational<T>\
    \ operator*(const Rational<T> &lhs, const Rational<T> &rhs) {\n        return\
    \ Rational<T>(lhs.num * rhs.num, lhs.den * rhs.den);\n    }\n    friend Rational<T>\
    \ operator/(const Rational<T> &lhs, const Rational<T> &rhs) {\n        assert(rhs.num\
    \ != T(0));\n        return Rational<T>(lhs.num * rhs.den, lhs.den * rhs.num);\n\
    \    }\n    Rational<T> &operator+=(const Rational<T> &rhs) {\n        *this =\
    \ *this + rhs;\n        return *this;\n    }\n    Rational<T> &operator-=(const\
    \ Rational<T> &rhs) {\n        *this = *this - rhs;\n        return *this;\n \
    \   }\n    Rational<T> &operator*=(const Rational<T> &rhs) {\n        *this =\
    \ *this * rhs;\n        return *this;\n    }\n    Rational<T> &operator/=(const\
    \ Rational<T> &rhs) {\n        assert(rhs.num != T(0));\n        *this = *this\
    \ / rhs;\n        return *this;\n    }\n    T cmp(const Rational<T> &rhs) const\
    \ {\n        return num * rhs.den - den * rhs.num;\n    }\n    friend bool operator==(const\
    \ Rational<T> &lhs, const Rational<T> &rhs) {\n        return lhs.cmp(rhs) ==\
    \ 0;\n    }\n    friend bool operator!=(const Rational<T> &lhs, const Rational<T>\
    \ &rhs) {\n        return lhs.cmp(rhs) != 0;\n    }\n    friend bool operator<(const\
    \ Rational<T> &lhs, const Rational<T> &rhs) {\n        return lhs.cmp(rhs) < 0;\n\
    \    }\n    friend bool operator>(const Rational<T> &lhs, const Rational<T> &rhs)\
    \ {\n        return lhs.cmp(rhs) > 0;\n    }\n    friend bool operator<=(const\
    \ Rational<T> &lhs, const Rational<T> &rhs) {\n        return lhs.cmp(rhs) <=\
    \ 0;\n    }\n    friend bool operator>=(const Rational<T> &lhs, const Rational<T>\
    \ &rhs) {\n        return lhs.cmp(rhs) >= 0;\n    }\n};\n\ntemplate <typename\
    \ T>\nvoid debug(Rational<T> x) {\n    std::cerr << x.num << '/' << x.den;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include <numeric>\n\
    template <typename T>\nstruct Rational {\n    T num, den;\n    Rational() : num(0),\
    \ den(1) {}\n    Rational(T x) : num(x), den(1) {}\n    Rational(T n, T d) : num(n),\
    \ den(d) {\n        T g = std::gcd(num, den);\n        num /= g;\n        den\
    \ /= g;\n        if (den < 0) {\n            num = -num;\n            den = -den;\n\
    \        }\n    }\n    static Rational<T> raw(T num, T den) {\n        Rational<T>\
    \ ret;\n        ret.num = num;\n        ret.den = den;\n        return ret;\n\
    \    }\n    friend Rational<T> operator+(const Rational<T> &lhs, const Rational<T>\
    \ &rhs) {\n        return Rational<T>(lhs.num * rhs.den + lhs.den * rhs.num, lhs.den\
    \ * rhs.den);\n    }\n    friend Rational<T> operator-(const Rational<T> &lhs,\
    \ const Rational<T> &rhs) {\n        return Rational<T>(lhs.num * rhs.den - lhs.den\
    \ * rhs.num, lhs.den * rhs.den);\n    }\n    friend Rational<T> operator*(const\
    \ Rational<T> &lhs, const Rational<T> &rhs) {\n        return Rational<T>(lhs.num\
    \ * rhs.num, lhs.den * rhs.den);\n    }\n    friend Rational<T> operator/(const\
    \ Rational<T> &lhs, const Rational<T> &rhs) {\n        assert(rhs.num != T(0));\n\
    \        return Rational<T>(lhs.num * rhs.den, lhs.den * rhs.num);\n    }\n  \
    \  Rational<T> &operator+=(const Rational<T> &rhs) {\n        *this = *this +\
    \ rhs;\n        return *this;\n    }\n    Rational<T> &operator-=(const Rational<T>\
    \ &rhs) {\n        *this = *this - rhs;\n        return *this;\n    }\n    Rational<T>\
    \ &operator*=(const Rational<T> &rhs) {\n        *this = *this * rhs;\n      \
    \  return *this;\n    }\n    Rational<T> &operator/=(const Rational<T> &rhs) {\n\
    \        assert(rhs.num != T(0));\n        *this = *this / rhs;\n        return\
    \ *this;\n    }\n    T cmp(const Rational<T> &rhs) const {\n        return num\
    \ * rhs.den - den * rhs.num;\n    }\n    friend bool operator==(const Rational<T>\
    \ &lhs, const Rational<T> &rhs) {\n        return lhs.cmp(rhs) == 0;\n    }\n\
    \    friend bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs) {\n\
    \        return lhs.cmp(rhs) != 0;\n    }\n    friend bool operator<(const Rational<T>\
    \ &lhs, const Rational<T> &rhs) {\n        return lhs.cmp(rhs) < 0;\n    }\n \
    \   friend bool operator>(const Rational<T> &lhs, const Rational<T> &rhs) {\n\
    \        return lhs.cmp(rhs) > 0;\n    }\n    friend bool operator<=(const Rational<T>\
    \ &lhs, const Rational<T> &rhs) {\n        return lhs.cmp(rhs) <= 0;\n    }\n\
    \    friend bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs) {\n\
    \        return lhs.cmp(rhs) >= 0;\n    }\n};\n\ntemplate <typename T>\nvoid debug(Rational<T>\
    \ x) {\n    std::cerr << x.num << '/' << x.den;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/rational.hpp
  requiredBy: []
  timestamp: '2024-07-18 16:52:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/rational.hpp
layout: document
redirect_from:
- /library/other/rational.hpp
- /library/other/rational.hpp.html
title: other/rational.hpp
---
