#pragma once
#include "multieval_geometric.hpp"

template <typename M>
std::vector<M> polynomial_interpolation_geometric_a1(const std::vector<M> &y, M r) {
    int n = (int)y.size();
    if (n == 0) {
        return std::vector<M>(0);
    }
    if (n == 1) {
        return std::vector<M>(1, y[0]);
    }
    std::vector<M> pw(n + 1), invpw(n + 1);
    pw[0] = M(1);
    for (int i = 0; i < n; ++i) {
        pw[i + 1] = pw[i] * r;
    }
    invpw[n] = pw[n].inv();
    for (int i = n - 1; i >= 0; --i) {
        invpw[i] = invpw[i + 1] * r;
    }
    std::vector<M> qfac(n + 1), invqfac(n);
    qfac[0] = M(1);
    for (int i = 0; i < n; ++i) {
        qfac[i + 1] = qfac[i] * (M(1) - pw[i + 1]);
    }
    invqfac[n - 1] = qfac[n - 1].inv();
    for (int i = n - 2; i >= 0; --i) {
        invqfac[i] = invqfac[i + 1] * (M(1) - pw[i + 1]);
    }
    std::vector<M> w = y;
    {
        M t(1);
        w[0] *= invqfac[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            t *= -invpw[n - 2 - i];
            w[i + 1] *= invqfac[i + 1] * invqfac[n - 2 - i] * t;
        }
    }
    std::vector<M> f(n);
    {
        M t(1);
        f[0] = t;
        for (int i = 0; i < n - 1; ++i) {
            t *= -pw[i];
            f[i + 1] = qfac[n] * invqfac[i + 1] * invqfac[n - 1 - i] * t;
        }
    }
    std::vector<M> ev = multieval_geometric(w, n, M(1), r);
    std::vector<M> ans = convolve(f, ev);
    ans.resize(n);
    std::reverse(ans.begin(), ans.end());
    return ans;
}

template <typename M>
std::vector<M> polynomial_interpolation_geometric(const std::vector<M> &y, M a,
                                                  M r) {
    int n = (int)y.size();
    if (n == 0) {
        return std::vector<M>(0);
    }
    if (n == 1) {
        return std::vector<M>(1, y[0]);
    }
    // a != 0, r != 0
    std::vector<M> f = polynomial_interpolation_geometric_a1(y, r);
    M inv = a.inv();
    M pw(1);
    for (int i = 0; i < n; ++i) {
        f[i] *= pw;
        pw *= inv;
    }
    return f;
}
