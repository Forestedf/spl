#pragma once
#include "middle_product.hpp"

template <typename M>
std::vector<M> multieval_geometric(std::vector<M> f, int m, M a, M r) {
    int n = (int)f.size();
    if (n == 0) {
        return std::vector<M>(m, 0);
    }
    if (m == 0) {
        return std::vector<M>();
    }
    if (r == M()) {
        std::vector<M> ret(m, f[0]);
        M ev, pw(1);
        for (int i = 0; i < n; ++i) {
            ev += f[i] * pw;
            pw *= a;
        }
        ret[0] = ev;
        return ret;
    }
    std::vector<M> w(n + m - 1);
    M val(1), pw(1);
    for (int i = 0; i < n + m - 1; ++i) {
        w[i] = val;
        val *= pw;
        pw *= r;
    }
    val = pw = M(1);
    M invr = r.inv();
    for (int i = 0; i < n; ++i) {
        f[i] *= val;
        val *= a * pw;
        pw *= invr;
    }
    std::vector<M> ret = middle_product(f, w);
    val = pw = M(1);
    for (int i = 0; i < m; ++i) {
        ret[i] *= val;
        val *= pw;
        pw *= invr;
    }
    return ret;
}
