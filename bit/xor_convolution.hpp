#pragma once
#include <cassert>
#include <type_traits>
#include <vector>
template <typename T>
void hadamard(int n, std::vector<T> &a) {
    for (int d = 0; d < n; ++d) {
        for (int i = 0; i < (1 << n); ++i) {
            if ((i & (1 << d)) == 0) {
                T x = a[i], y = a[i ^ (1 << d)];
                a[i] = x + y;
                a[i ^ (1 << d)] = x - y;
            }
        }
    }
}
template <typename T>
std::vector<T> bitwise_xor_convolution(std::vector<T> a, std::vector<T> b) {
    assert(a.size() == b.size() && a.size() > 0);
    int n = __builtin_ctz((unsigned)a.size());
    assert((int)a.size() == (1 << n));
    hadamard(n, a);
    hadamard(n, b);
    for (int i = 0; i < (1 << n); ++i) {
        a[i] *= b[i];
    }
    hadamard(n, a);
    if constexpr (std::is_integral_v<T>) {
        for (int i = 0; i < (1 << n); ++i) {
            a[i] /= 1 << n;
        }
    } else {
        T inv = T(1 << n).inv();
        for (int i = 0; i < (1 << n); ++i) {
            a[i] *= inv;
        }
    }
    return a;
}
