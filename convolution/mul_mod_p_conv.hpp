#pragma once
#include "../number_theory/primitive_root.hpp"
#include "../poly/fft.hpp"

template <typename T>
std::vector<T> mul_mod_p_convolution(const std::vector<T> &a,
                                     const std::vector<T> &b, int g = -1) {
    int p = (int)a.size();
    if (g == -1) {
        g = find_primitive_root(p);
    }

    std::vector<int> pw(p - 1);
    pw[0] = 1;
    for (int i = 1; i < p - 1; ++i) {
        pw[i] = (long long)pw[i - 1] * g % p;
    }

    std::vector<T> at(p - 1), bt(p - 1);
    for (int i = 0; i < p - 1; ++i) {
        at[i] = a[pw[i]];
        bt[i] = b[pw[i]];
    }
    std::vector<T> ct = convolve(at, bt);

    std::vector<T> c(p, T(0));
    for (int i = 0; i < p; ++i) {
        c[0] += a[i] * b[0];
    }
    for (int i = 1; i < p; ++i) {
        c[0] += a[0] * b[i];
    }
    for (int i = 0; i < (int)ct.size(); ++i) {
        c[pw[i % (p - 1)]] += ct[i];
    }
    return c;
}
