#pragma once
#include <cassert>
#include <utility>
#include <vector>
template <typename T>
class Matrix {
    int _h, _w;
    std::vector<std::vector<T>> dat;

public:
    Matrix() : dat() {}
    Matrix(int n) : _h(n), _w(n), dat(n, std::vector<T>(n, T())) {
        assert(0 <= n);
    }
    Matrix(int _h, int _w) : _h(_h), _w(_w), dat(_h, std::vector<T>(_w, T())) {
        assert(0 <= _h && 0 <= _w);
    }
    static Matrix<T> ident(int n) {
        assert(0 <= n);
        Matrix<T> ret(n);
        for (int i = 0; i < n; ++i) {
            ret.dat[i][i] = T(1);
        }
        return ret;
    }
    int h() const { return _h; }
    int w() const { return _w; }
    std::pair<int, int> shape() const { return std::pair<int, int>(_h, _w); }
    const T &operator()(int i, int j) const {
        assert(0 <= i && i < _h && 0 <= j && j < _w);
        return dat[i][j];
    }
    T &operator()(int i, int j) {
        assert(0 <= i && i < _h && 0 <= j && j < _w);
        return dat[i][j];
    }
    void swap_row(int i, int j) {
        assert(0 <= i && i < _h && 0 <= j && j < _h);
        std::swap(dat[i], dat[j]);
    }
    void swap_column(int i, int j) {
        assert(0 <= i && i < _w && 0 <= j && j < _w);
        for (int k = 0; k < _h; ++k) {
            std::swap(dat[k][i], dat[k][j]);
        }
    }
    Matrix<T> &operator+=(const Matrix<T> &rhs) {
        assert(shape() == rhs.shape());
        for (int i = 0; i < _h; ++i) {
            for (int j = 0; j < _w; ++j) {
                dat[i][j] += rhs.dat[i][j];
            }
        }
        return *this;
    }
    Matrix<T> &operator-=(const Matrix<T> &rhs) {
        assert(shape() == rhs.shape());
        for (int i = 0; i < _h; ++i) {
            for (int j = 0; j < _w; ++j) {
                dat[i][j] -= rhs.dat[i][j];
            }
        }
        return *this;
    }
    Matrix<T> &operator*=(const Matrix<T> &rhs) { return *this = *this * rhs; }
    friend Matrix<T> operator+(Matrix<T> lhs, const Matrix<T> &rhs) {
        return lhs += rhs;
    }
    friend Matrix<T> operator-(Matrix<T> lhs, const Matrix<T> &rhs) {
        return lhs -= rhs;
    }
    friend Matrix<T> operator*(const Matrix<T> &lhs, const Matrix<T> &rhs) {
        assert(lhs._w == rhs._h);
        std::vector<std::vector<T>> dat(lhs._h, std::vector<T>(rhs._w, T()));
        for (int i = 0; i < lhs._h; ++i) {
            for (int j = 0; j < rhs._w; ++j) {
                for (int k = 0; k < lhs._w; ++k) {
                    dat[i][j] += lhs.dat[i][k] * rhs.dat[k][j];
                }
            }
        }
        Matrix<T> ret;
        ret._h = lhs._h;
        ret._w = rhs._w;
        ret.dat = dat;
        return ret;
    }
};