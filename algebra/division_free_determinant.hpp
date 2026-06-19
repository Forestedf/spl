#pragma once
#include <utility>
#include "matrix.hpp"
template <typename T>
T division_free_determinant(Matrix<T> a) {
    int n = a.h();
    assert(a.w() == n);
    if (n == 0) {
        return T(1);
    }
    Matrix<T> t(n);
    Matrix<T> x = a;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(a(i, j), a(j, i));
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        T sum(0);
        for (int j = n - i - 1; j >= 0; --j) {
            sum += std::exchange(x(j, j), -sum);
        }
        for (int j = 0; j < n - i - 1; ++j) {
            for (int k = 0; k < n; ++k) {
                t(j, k) = T();
            }
        }
        for (int j = 0; j < n - i - 1; ++j) {
            for (int k = 0; k < n; ++k) {
                T sum(0);
                for (int l = j; l < n; ++l) {
                    sum += x(j, l) * a(k, l);
                }
                t(j, k) = sum;
            }
        }
        x = t;
    }
    T ans = x(0, 0);
    if (n % 2 == 0) {
        ans = -ans;
    }
    return ans;
}
