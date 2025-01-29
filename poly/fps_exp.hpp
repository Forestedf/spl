#pragma once
#include <algorithm>
#include "../number_theory/factorial.hpp"
#include "fft.hpp"

template <typename M>
std::vector<M> fps_exp(const std::vector<M> &h, int len = -1) {
    static constexpr FFTRoot<M::get_mod()> fftroot;
    if (len == -1) {
        len = (int)h.size();
    }
    assert((int)h.size() >= 1 && h[0] == M(0) && len >= 0);
    if (len == 0) {
        return std::vector<M>();
    }
    std::vector<M> f(1, M(1)), g(1, M(1));
    std::vector<M> fft_f(1, M(1));
    while ((int)f.size() < len) {
        int n = (int)f.size();
        f.resize(2 * n, M());
        g.resize(2 * n, M());

        std::vector<M> fft_g = g;
        fft(fft_g);
        fft_f.resize(2 * n);
        {
            M cur(1);
            M zeta = fftroot.root[__builtin_ctz(n) + 1];
            for (int i = 0; i < n; ++i) {
                fft_f[n + i] = f[i] * cur;
                cur *= zeta;
            }
        }
        fft(fft_f.data() + n, n);

        std::vector<M> delta(n);
        for (int i = 0; i < n; ++i) {
            delta[i] = fft_f[i] * fft_g[i];
        }
        ifft(delta);
        delta.resize(2 * n, M());
        std::rotate(delta.begin(), delta.begin() + n, delta.end());
        delta[n] -= M(1);

        std::vector<M> eps(n, M());
        for (int i = 0; i < n - 1; ++i) {
            eps[i] = f[i + 1] * M(i + 1);
        }
        fft(eps);
        for (int i = 0; i < n; ++i) {
            eps[i] *= fft_g[i];
        }
        ifft(eps);
        eps.resize(2 * n, M());
        for (int i = 0; i < n - 1; ++i) {
            M tmp = (i + 1 < (int)h.size() ? h[i + 1] * M(i + 1) : M());
            eps[n + i] = eps[i] - tmp;
            eps[i] = tmp;
        }
        std::vector<M> fft_dh(2 * n);
        for (int i = 0; i < n; ++i) {
            M tmp = (i + 1 < (int)h.size() ? h[i + 1] * M(i + 1) : M());
            fft_dh[i] = tmp;
        }
        fft(fft_dh);
        fft(delta);
        for (int i = 0; i < 2 * n; ++i) {
            delta[i] *= fft_dh[i];
        }
        ifft(delta);
        for (int i = n; i < 2 * n; ++i) {
            eps[i] -= delta[i];
        }
        for (int i = 0; i < 2 * n - 1; ++i) {
            M tmp = (i + 1 < (int)h.size() ? h[i + 1] * M(i + 1) : M());
            eps[i] -= tmp;
        }
        for (int i = 2 * n - 1; i >= 1; --i) {
            eps[i] = eps[i - 1] * inv<M>(i);
        }
        eps[0] = M(0);

        fft(eps);
        for (int i = 0; i < 2 * n; ++i) {
            eps[i] *= fft_f[i];
        }
        ifft(eps);
        for (int i = n; i < 2 * n; ++i) {
            f[i] = -eps[i];
        }
        if (2 * n >= len) {
            break;
        }

        fft_f = f;
        fft(fft_f);
        for (int i = 0; i < 2 * n; ++i) {
            eps[i] = fft_f[i] * fft_g[i];
        }
        ifft(eps);
        std::fill(eps.begin(), eps.begin() + n, M(0));
        fft(eps);
        for (int i = 0; i < 2 * n; ++i) {
            eps[i] *= fft_g[i];
        }
        ifft(eps);
        for (int i = n; i < 2 * n; ++i) {
            g[i] = -eps[i];
        }
    }
    f.resize(len);
    return f;
}
