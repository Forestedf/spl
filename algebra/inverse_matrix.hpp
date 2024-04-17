#pragma once
#include <optional>
#include "matrix.hpp"
template <typename T>
std::optional<Matrix<T>> inverse_matrix(Matrix<T> a) {
    assert(a.h() == a.w());
    int n = a.h();
    Matrix<T> b = Matrix<T>::ident(n);
    for (int i = 0; i < n; ++i) {
        int row = -1;
        for (int j = i; j < n; ++j) {
            if (a(j, i) != T()) {
                row = j;
                break;
            }
        }
        if (row == -1) {
            return std::nullopt;
        }
        a.swap_row(i, row);
        b.swap_row(i, row);
        T inv = T(1) / a(i, i);
        for (int j = i; j < n; ++j) {
            a(i, j) *= inv;
        }
        for (int j = 0; j < n; ++j) {
            b(i, j) *= inv;
        }
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            T cf = a(j, i);
            for (int k = i; k < n; ++k) {
                a(j, k) -= a(i, k) * cf;
            }
            for (int k = 0; k < n; ++k) {
                b(j, k) -= b(i, k) * cf;
            }
        }
    }
    return b;
}
