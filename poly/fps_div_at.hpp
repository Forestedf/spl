#pragma once
#include <algorithm>
#include <bit>
#include "fps_inv.hpp"
template <typename M>
void extend_fft(std::vector<M> &a) {
    static constexpr FFTRoot<M::get_mod()> fft_root;
    int n = (int)a.size();
    std::copy(a.begin(), a.begin() + n / 2, a.begin() + n / 2);
    ifft(a.data() + n / 2, n / 2);
    M pw(1);
    M r = fft_root.root[std::bit_width((unsigned)n) - 1];
    for (int i = n / 2; i < n; ++i) {
        a[i] *= pw;
        pw *= r;
    }
    fft(a.data() + n / 2, n / 2);
}
// returns [x^k] f(x) / g(x)
// requires LEN(f) < LEN(g) and g[0] != 0
template <typename T>
T fps_div_at(std::vector<T> f, std::vector<T> g, long long k) {
    static constexpr FFTRoot<T::get_mod()> fft_root;
    static constexpr T INV2 = T(2).inv();
    assert(f.size() < g.size() && g[0] != T(0));
    if (g.size() == 1) {
        return T(0);
    }
    int n = (int)std::bit_ceil(2 * g.size() - 1);
    f.resize(n, T(0));
    g.resize(n, T(0));
    fft(f);
    fft(g);
    while (k >= n) {
        for (int i = 0; i < n; ++i) {
            f[i] *= g[i ^ 1];
        }
        if (k & 1) {
            T p(1);
            for (int i = 0; i < n / 2; ++i) {
                f[i] = (f[2 * i] - f[2 * i + 1]) * INV2 * p;
                p *= fft_root.irate2[__builtin_ctz(~i)];
            }
        } else {
            for (int i = 0; i < n / 2; ++i) {
                f[i] = (f[2 * i] + f[2 * i + 1]) * INV2;
            }
        }
        extend_fft(f);
        for (int i = 0; i < n / 2; ++i) {
            g[i] = g[2 * i] * g[2 * i + 1];
        }
        extend_fft(g);
        k /= 2;
    }
    ifft(f);
    ifft(g);
    std::vector<T> inv_g = fps_inv(g);
    T ans(0);
    for (int i = 0; i <= k; ++i) {
        ans += f[i] * inv_g[k - i];
    }
    return ans;
}
