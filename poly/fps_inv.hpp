#pragma once
#include <algorithm>
#include "fft.hpp"
// 10 FFT(n)
template <typename T>
std::vector<T> fps_inv(const std::vector<T> &f, int len = -1) {
    if (len == -1) {
        len = (int)f.size();
    }
    assert(!f.empty() && f[0] != T(0) && len >= 0);
    std::vector<T> g(1, T(1) / f[0]);
    while ((int)g.size() < len) {
        int n = (int)g.size();
        std::vector<T> fft_f(2 * n), fft_g(2 * n);
        std::copy(f.begin(), f.begin() + std::min(2 * n, (int)f.size()),
                  fft_f.begin());
        std::copy(g.begin(), g.end(), fft_g.begin());
        fft(fft_f);
        fft(fft_g);
        for (int i = 0; i < 2 * n; ++i) {
            fft_f[i] *= fft_g[i];
        }
        ifft(fft_f);
        std::fill(fft_f.begin(), fft_f.begin() + n, T(0));
        fft(fft_f);
        for (int i = 0; i < 2 * n; ++i) {
            fft_f[i] *= fft_g[i];
        }
        ifft(fft_f);
        g.resize(2 * n);
        for (int i = n; i < 2 * n; ++i) {
            g[i] = -fft_f[i];
        }
    }
    g.resize(len);
    return g;
}
