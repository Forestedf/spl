#pragma once
#include "fps_pow.hpp"
#include "power_projection.hpp"

template <typename M>
std::vector<M> compositional_inverse(std::vector<M> f) {
    if (f.empty()) {
        return std::vector<M>(0);
    }
    assert(f[0] == M());
    if (f.size() == 1) {
        return std::vector<M>(1, M());
    }
    assert(f[1] != M());
    int n = (int)f.size();
    M c = f[1];
    M c_inv = c.inv();
    for (M &elem : f) {
        elem *= c_inv;
    }
    std::vector<M> wt(n);
    wt[n - 1] = M(1);
    std::vector<M> pp = power_projection(wt, f, n);
    std::vector<M> h(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        h[i] = pp[n - 1 - i] * M(n - 1) * inv<M>(n - 1 - i);
    }
    std::vector<M> g = fps_pow_constant_1(h, -inv<M>(n - 1));
    M pw(1);
    for (M &elem : g) {
        pw *= c_inv;
        elem *= pw;
    }
    g.insert(g.begin(), M());
    return g;
}
