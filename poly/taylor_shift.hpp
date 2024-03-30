#pragma once
#include "fft.hpp"
#include "../number_theory/factorial.hpp"
#include <algorithm>
// f(x) -> f(x+c)
template <typename M>
std::vector<M> taylor_shift(std::vector<M> f, M c) {
    for (int i = 0; i < (int)f.size(); ++i) {
        f[i] *= fact<M>(i);
    }
    std::reverse(f.begin(), f.end());
    M cp(1);
    std::vector<M> g(f.size());
    for (int i = 0; i < (int)f.size(); ++i) {
        g[i] = cp * inv_fact<M>(i);
        cp *= c;
    }
    std::vector<M> h = convolve(f, g);
    h.resize(f.size());
    std::reverse(h.begin(), h.end());
    for (int i = 0; i < (int)f.size(); ++i) {
        h[i] *= inv_fact<M>(i);
    }
    return h;
}
