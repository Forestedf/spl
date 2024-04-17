#pragma once
#include "matrix.hpp"
template <typename T>
T determinant(Matrix<T> a) {
    assert(a.h() == a.w());
    int n = a.h();
    T det(1);
    for (int i = 0; i < n; ++i) {
        int row = -1;
        for (int j = i; j < n; ++j) {
            if (a(j, i) != T()) {
                row = j;
                break;
            }
        }
        if (row == -1) {
            det = T(0);
            break;
        }
        if (row != i) {
            a.swap_row(i, row);
            det = -det;
        }
        det *= a(i, i);
        T inv = T(1) / a(i, i);
        for (int j = i; j < n; ++j) {
            a(i, j) *= inv;
        }
        for (int j = i + 1; j < n; ++j) {
            T cf = a(j, i);
            for (int k = i + 1; k < n; ++k) {
                a(j, k) -= cf * a(i, k);
            }
        }
    }
    return det;
}
