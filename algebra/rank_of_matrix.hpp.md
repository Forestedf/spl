---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/matrix.hpp
    title: algebra/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algebra/test/matrix_rank.test.cpp
    title: algebra/test/matrix_rank.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/matrix.hpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\ntemplate <typename T>\nclass Matrix {\n    int _h, _w;\n  \
    \  std::vector<std::vector<T>> dat;\n\npublic:\n    Matrix() : dat() {}\n    Matrix(int\
    \ n) : _h(n), _w(n), dat(n, std::vector<T>(n, T())) {\n        assert(0 <= n);\n\
    \    }\n    Matrix(int _h, int _w) : _h(_h), _w(_w), dat(_h, std::vector<T>(_w,\
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
    \ dat;\n        return ret;\n    }\n};\n#line 3 \"algebra/rank_of_matrix.hpp\"\
    \n// O(HW min(H,W))\ntemplate <typename T>\nint rank_of_matrix(Matrix<T> a) {\n\
    \    if (a.h() > a.w()) {\n        a = a.trans();\n    }\n    if (a.h() == 0)\
    \ {\n        return 0;\n    }\n    int rank = 0;\n    for (int i = 0; i < a.w();\
    \ ++i) {\n        int row = -1;\n        for (int j = rank; j < a.h(); ++j) {\n\
    \            if (a(j, i) != T()) {\n                row = j;\n               \
    \ break;\n            }\n        }\n        if (row == -1) {\n            continue;\n\
    \        }\n        a.swap_row(rank, row);\n        T inv = T(1) / a(rank, i);\n\
    \        for (int j = i; j < a.w(); ++j) {\n            a(rank, j) *= inv;\n \
    \       }\n        for (int j = rank + 1; j < a.h(); ++j) {\n            T cf\
    \ = a(j, i);\n            for (int k = i + 1; k < a.w(); ++k) {\n            \
    \    a(j, k) -= a(rank, k) * cf;\n            }\n        }\n        if (++rank\
    \ == a.h()) {\n            break;\n        }\n    }\n    return rank;\n}\n"
  code: "#pragma once\n#include \"matrix.hpp\"\n// O(HW min(H,W))\ntemplate <typename\
    \ T>\nint rank_of_matrix(Matrix<T> a) {\n    if (a.h() > a.w()) {\n        a =\
    \ a.trans();\n    }\n    if (a.h() == 0) {\n        return 0;\n    }\n    int\
    \ rank = 0;\n    for (int i = 0; i < a.w(); ++i) {\n        int row = -1;\n  \
    \      for (int j = rank; j < a.h(); ++j) {\n            if (a(j, i) != T()) {\n\
    \                row = j;\n                break;\n            }\n        }\n\
    \        if (row == -1) {\n            continue;\n        }\n        a.swap_row(rank,\
    \ row);\n        T inv = T(1) / a(rank, i);\n        for (int j = i; j < a.w();\
    \ ++j) {\n            a(rank, j) *= inv;\n        }\n        for (int j = rank\
    \ + 1; j < a.h(); ++j) {\n            T cf = a(j, i);\n            for (int k\
    \ = i + 1; k < a.w(); ++k) {\n                a(j, k) -= a(rank, k) * cf;\n  \
    \          }\n        }\n        if (++rank == a.h()) {\n            break;\n\
    \        }\n    }\n    return rank;\n}\n"
  dependsOn:
  - algebra/matrix.hpp
  isVerificationFile: false
  path: algebra/rank_of_matrix.hpp
  requiredBy: []
  timestamp: '2024-04-17 21:23:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algebra/test/matrix_rank.test.cpp
documentation_of: algebra/rank_of_matrix.hpp
layout: document
redirect_from:
- /library/algebra/rank_of_matrix.hpp
- /library/algebra/rank_of_matrix.hpp.html
title: algebra/rank_of_matrix.hpp
---
