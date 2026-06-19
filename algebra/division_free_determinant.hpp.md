---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/matrix.hpp
    title: algebra/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algebra/test/division_free_determinant.test.cpp
    title: algebra/test/division_free_determinant.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/division_free_determinant.hpp\"\n#include <utility>\n\
    #line 2 \"algebra/matrix.hpp\"\n#include <cassert>\n#line 4 \"algebra/matrix.hpp\"\
    \n#include <vector>\ntemplate <typename T>\nclass Matrix {\n    int _h, _w;\n\
    \    std::vector<std::vector<T>> dat;\n\npublic:\n    Matrix() : dat() {}\n  \
    \  Matrix(int n) : _h(n), _w(n), dat(n, std::vector<T>(n, T())) {\n        assert(0\
    \ <= n);\n    }\n    Matrix(int _h, int _w) : _h(_h), _w(_w), dat(_h, std::vector<T>(_w,\
    \ T())) {\n        assert(0 <= _h && 0 <= _w);\n    }\n    static Matrix<T> ident(int\
    \ n) {\n        assert(0 <= n);\n        Matrix<T> ret(n);\n        for (int i\
    \ = 0; i < n; ++i) {\n            ret.dat[i][i] = T(1);\n        }\n        return\
    \ ret;\n    }\n    int h() const { return _h; }\n    int w() const { return _w;\
    \ }\n    std::pair<int, int> shape() const { return std::pair<int, int>(_h, _w);\
    \ }\n    const T &operator()(int i, int j) const {\n        assert(0 <= i && i\
    \ < _h && 0 <= j && j < _w);\n        return dat[i][j];\n    }\n    T &operator()(int\
    \ i, int j) {\n        assert(0 <= i && i < _h && 0 <= j && j < _w);\n       \
    \ return dat[i][j];\n    }\n    void swap_row(int i, int j) {\n        assert(0\
    \ <= i && i < _h && 0 <= j && j < _h);\n        std::swap(dat[i], dat[j]);\n \
    \   }\n    void swap_column(int i, int j) {\n        assert(0 <= i && i < _w &&\
    \ 0 <= j && j < _w);\n        for (int k = 0; k < _h; ++k) {\n            std::swap(dat[k][i],\
    \ dat[k][j]);\n        }\n    }\n    Matrix<T> trans() const {\n        Matrix<T>\
    \ ret(_w, _h);\n        for (int i = 0; i < _h; ++i) {\n            for (int j\
    \ = 0; j < _w; ++j) {\n                ret.dat[j][i] = dat[i][j];\n          \
    \  }\n        }\n        return ret;\n    }\n    Matrix<T> &operator+=(const Matrix<T>\
    \ &rhs) {\n        assert(shape() == rhs.shape());\n        for (int i = 0; i\
    \ < _h; ++i) {\n            for (int j = 0; j < _w; ++j) {\n                dat[i][j]\
    \ += rhs.dat[i][j];\n            }\n        }\n        return *this;\n    }\n\
    \    Matrix<T> &operator-=(const Matrix<T> &rhs) {\n        assert(shape() ==\
    \ rhs.shape());\n        for (int i = 0; i < _h; ++i) {\n            for (int\
    \ j = 0; j < _w; ++j) {\n                dat[i][j] -= rhs.dat[i][j];\n       \
    \     }\n        }\n        return *this;\n    }\n    Matrix<T> &operator*=(const\
    \ Matrix<T> &rhs) { return *this = *this * rhs; }\n    friend Matrix<T> operator+(Matrix<T>\
    \ lhs, const Matrix<T> &rhs) {\n        return lhs += rhs;\n    }\n    friend\
    \ Matrix<T> operator-(Matrix<T> lhs, const Matrix<T> &rhs) {\n        return lhs\
    \ -= rhs;\n    }\n    friend Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T>\
    \ &rhs) {\n        assert(lhs._w == rhs._h);\n        std::vector<std::vector<T>>\
    \ dat(lhs._h, std::vector<T>(rhs._w, T()));\n        for (int i = 0; i < lhs._h;\
    \ ++i) {\n            for (int j = 0; j < rhs._w; ++j) {\n                for\
    \ (int k = 0; k < lhs._w; ++k) {\n                    dat[i][j] += lhs.dat[i][k]\
    \ * rhs.dat[k][j];\n                }\n            }\n        }\n        Matrix<T>\
    \ ret;\n        ret._h = lhs._h;\n        ret._w = rhs._w;\n        ret.dat =\
    \ dat;\n        return ret;\n    }\n    Matrix<T> pow(unsigned long long t) const\
    \ {\n        assert(_h == _w);\n        Matrix<T> ret = Matrix<T>::ident(_h);\n\
    \        Matrix<T> self = *this;\n        while (t > 0) {\n            if (t &\
    \ 1) {\n                ret *= self;\n            }\n            self *= self;\n\
    \            t >>= 1;\n        }\n        return ret;\n    }\n};\n#line 4 \"algebra/division_free_determinant.hpp\"\
    \ntemplate <typename T>\nT division_free_determinant(Matrix<T> a) {\n    int n\
    \ = a.h();\n    assert(a.w() == n);\n    if (n == 0) {\n        return T(1);\n\
    \    }\n    Matrix<T> t(n);\n    Matrix<T> x = a;\n    for (int i = 0; i < n;\
    \ ++i) {\n        for (int j = i + 1; j < n; ++j) {\n            swap(a(i, j),\
    \ a(j, i));\n        }\n    }\n    for (int i = 0; i < n - 1; ++i) {\n       \
    \ T sum(0);\n        for (int j = n - i - 1; j >= 0; --j) {\n            sum +=\
    \ std::exchange(x(j, j), -sum);\n        }\n        for (int j = 0; j < n - i\
    \ - 1; ++j) {\n            for (int k = 0; k < n; ++k) {\n                t(j,\
    \ k) = T();\n            }\n        }\n        for (int j = 0; j < n - i - 1;\
    \ ++j) {\n            for (int k = 0; k < n; ++k) {\n                T sum(0);\n\
    \                for (int l = j; l < n; ++l) {\n                    sum += x(j,\
    \ l) * a(k, l);\n                }\n                t(j, k) = sum;\n         \
    \   }\n        }\n        x = t;\n    }\n    T ans = x(0, 0);\n    if (n % 2 ==\
    \ 0) {\n        ans = -ans;\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include <utility>\n#include \"matrix.hpp\"\ntemplate <typename\
    \ T>\nT division_free_determinant(Matrix<T> a) {\n    int n = a.h();\n    assert(a.w()\
    \ == n);\n    if (n == 0) {\n        return T(1);\n    }\n    Matrix<T> t(n);\n\
    \    Matrix<T> x = a;\n    for (int i = 0; i < n; ++i) {\n        for (int j =\
    \ i + 1; j < n; ++j) {\n            swap(a(i, j), a(j, i));\n        }\n    }\n\
    \    for (int i = 0; i < n - 1; ++i) {\n        T sum(0);\n        for (int j\
    \ = n - i - 1; j >= 0; --j) {\n            sum += std::exchange(x(j, j), -sum);\n\
    \        }\n        for (int j = 0; j < n - i - 1; ++j) {\n            for (int\
    \ k = 0; k < n; ++k) {\n                t(j, k) = T();\n            }\n      \
    \  }\n        for (int j = 0; j < n - i - 1; ++j) {\n            for (int k =\
    \ 0; k < n; ++k) {\n                T sum(0);\n                for (int l = j;\
    \ l < n; ++l) {\n                    sum += x(j, l) * a(k, l);\n             \
    \   }\n                t(j, k) = sum;\n            }\n        }\n        x = t;\n\
    \    }\n    T ans = x(0, 0);\n    if (n % 2 == 0) {\n        ans = -ans;\n   \
    \ }\n    return ans;\n}\n"
  dependsOn:
  - algebra/matrix.hpp
  isVerificationFile: false
  path: algebra/division_free_determinant.hpp
  requiredBy: []
  timestamp: '2026-06-19 12:45:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algebra/test/division_free_determinant.test.cpp
documentation_of: algebra/division_free_determinant.hpp
layout: document
redirect_from:
- /library/algebra/division_free_determinant.hpp
- /library/algebra/division_free_determinant.hpp.html
title: algebra/division_free_determinant.hpp
---
