#pragma once
#include "fft.hpp"
#include "../number_theory/factorial.hpp"
template <typename M>
std::vector<M> stirling_2(int n) {
    assert(0 <= n);
    std::vector<M> f(n + 1), g(n + 1);
    for (int i = 0; i <= n; ++i) {
        f[i] = M::raw(i).pow(n) * inv_fact<M>(i);
        g[i] = inv_fact<M>(i);
        if (i % 2 == 1) {
            g[i] = -g[i];
        }
    }
    std::vector<M> h = convolve(f, g);
    h.resize(n + 1);
    return h;
}
