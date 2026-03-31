#pragma once
#include <utility>
#include "fps_inv.hpp"

// sum_i a[i] / (1 - b[i] x)
template <typename M>
std::pair<std::vector<M>, std::vector<M>> rational_sum_1_frac(const std::vector<M> &a, const std::vector<M> &b) {
    static constexpr FFTRoot<M::get_mod()> root{};
    assert(a.size() == b.size());
    const int old = (int)a.size();
    const int lg = (old <= 1 ? 0 : 32 - __builtin_clz(old - 1));
    const int n = 1 << lg;
    const int n2 = n * 2;
    std::vector<M> c(n2), d(n2);
    for (int i = 0; i < old; ++i) {
        c[2 * i] = c[2 * i + 1] = a[i];
        d[2 * i] = M::raw(1) - b[i];
        d[2 * i + 1] = M::raw(1) + b[i];
    }
    std::fill(d.begin() + 2 * old, d.end(), M::raw(1));
    for (int ph = 0; ph < lg; ++ph) {
        const int w = 1 << (ph + 1), w2 = w * 2;
        M omega = root.root[ph + 2];
        for (int i = 0; i < n2; i += w2) {
            const int ti = i + w;
            for (int j = 0; j < w; ++j) {
                c[ti + j] = c[i + j] = c[i + j] * d[ti + j] + c[ti + j] * d[i + j];
                d[ti + j] = d[i + j] *= d[ti + j];
            }
            ifft(c.data() + ti, w);
            ifft(d.data() + ti, w);
            d[ti] = M::raw(2) - d[ti];
            M pw = M::raw(1);
            for (int j = 0; j < w; ++j) {
                c[ti + j] *= pw;
                d[ti + j] *= pw;
                pw *= omega;
            }
            fft(c.data() + ti, w);
            fft(d.data() + ti, w);
        }
    }
    ifft(c);
    ifft(d);
    c.resize(old);
    d.resize(old + 1);
    return std::make_pair(c, d);
}

// sum_i a[i] / (1 - b[i] x), first m terms
template <typename M>
std::vector<M> rational_sum_1(const std::vector<M> &a, const std::vector<M> &b, int m) {
    auto [num, den] = rational_sum_1_frac(a, b);
    num.resize(m);
    den = fps_inv(den, m);
    std::vector<M> c = convolve(num, den);
    c.resize(m);
    return c;
}
