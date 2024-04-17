---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/matrix.hpp
    title: algebra/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algebra/test/inverse_matrix.test.cpp
    title: algebra/test/inverse_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/inverse_matrix.hpp\"\n#include <optional>\n#line\
    \ 2 \"algebra/matrix.hpp\"\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    template <typename T>\nclass Matrix {\n    int _h, _w;\n    std::vector<std::vector<T>>\
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
    \ b;\n}\n"
  code: "#pragma once\n#include <optional>\n#include \"matrix.hpp\"\ntemplate <typename\
    \ T>\nstd::optional<Matrix<T>> inverse_matrix(Matrix<T> a) {\n    assert(a.h()\
    \ == a.w());\n    int n = a.h();\n    Matrix<T> b = Matrix<T>::ident(n);\n   \
    \ for (int i = 0; i < n; ++i) {\n        int row = -1;\n        for (int j = i;\
    \ j < n; ++j) {\n            if (a(j, i) != T()) {\n                row = j;\n\
    \                break;\n            }\n        }\n        if (row == -1) {\n\
    \            return std::nullopt;\n        }\n        a.swap_row(i, row);\n  \
    \      b.swap_row(i, row);\n        T inv = T(1) / a(i, i);\n        for (int\
    \ j = i; j < n; ++j) {\n            a(i, j) *= inv;\n        }\n        for (int\
    \ j = 0; j < n; ++j) {\n            b(i, j) *= inv;\n        }\n        for (int\
    \ j = 0; j < n; ++j) {\n            if (j == i) {\n                continue;\n\
    \            }\n            T cf = a(j, i);\n            for (int k = i; k < n;\
    \ ++k) {\n                a(j, k) -= a(i, k) * cf;\n            }\n          \
    \  for (int k = 0; k < n; ++k) {\n                b(j, k) -= b(i, k) * cf;\n \
    \           }\n        }\n    }\n    return b;\n}\n"
  dependsOn:
  - algebra/matrix.hpp
  isVerificationFile: false
  path: algebra/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2024-04-17 20:50:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algebra/test/inverse_matrix.test.cpp
documentation_of: algebra/inverse_matrix.hpp
layout: document
redirect_from:
- /library/algebra/inverse_matrix.hpp
- /library/algebra/inverse_matrix.hpp.html
title: algebra/inverse_matrix.hpp
---
