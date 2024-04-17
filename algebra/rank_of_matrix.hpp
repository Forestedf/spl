#pragma once
#include "matrix.hpp"
// O(HW min(H,W))
template <typename T>
int rank_of_matrix(Matrix<T> a) {
    if (a.h() > a.w()) {
        a = a.trans();
    }
    if (a.h() == 0) {
        return 0;
    }
    int rank = 0;
    for (int i = 0; i < a.w(); ++i) {
        int row = -1;
        for (int j = rank; j < a.h(); ++j) {
            if (a(j, i) != T()) {
                row = j;
                break;
            }
        }
        if (row == -1) {
            continue;
        }
        a.swap_row(rank, row);
        T inv = T(1) / a(rank, i);
        for (int j = i; j < a.w(); ++j) {
            a(rank, j) *= inv;
        }
        for (int j = rank + 1; j < a.h(); ++j) {
            T cf = a(j, i);
            for (int k = i + 1; k < a.w(); ++k) {
                a(j, k) -= a(rank, k) * cf;
            }
        }
        if (++rank == a.h()) {
            break;
        }
    }
    return rank;
}
