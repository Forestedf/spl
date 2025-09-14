#pragma once
#include "fps_inv.hpp"

template <typename M>
std::vector<M> multieval(std::vector<M> f, const std::vector<M> &p) {
    int n = (int)f.size();
    int m = (int)p.size();

    if (n == 0) {
        return std::vector<M>(m);
    }
    if (m == 0) {
        return std::vector<M>();
    }

    int l = 1;
    int k = 0;
    while (l < m) {
        l *= 2;
        ++k;
    }

    std::vector<std::vector<M>> prod(2 * l);
    for (int i = 0; i < m; ++i) {
        prod[l + i] = std::vector<M>({-p[i], M(1)});
    }
    for (int i = m; i < l; ++i) {
        prod[l + i] = std::vector<M>({M(1)});
    }
    for (int i = l - 1; i >= 1; --i) {
        prod[i] = convolve(prod[2 * i], prod[2 * i + 1]);
    }

    std::vector<M> pr = prod[1];
    std::reverse(pr.begin(), pr.end());
    pr = fps_inv(pr, n);
    std::reverse(f.begin(), f.end());
    pr = convolve(f, pr);
    pr.resize(n);
    std::reverse(pr.begin(), pr.end());
    pr.resize(m, M());

    std::vector<std::vector<M>> fs(2 * l);
    fs[1] = pr;
    for (int i = 1; i < l; ++i) {
        if (prod[i].size() == 1) {
            continue;
        }
        int lc = (int)prod[2 * i].size() - 1;
        int rc = (int)prod[2 * i + 1].size() - 1;
        assert((int)fs[i].size() == lc + rc);
        fs[2 * i] = convolve(fs[i], prod[2 * i + 1]);
        fs[2 * i] =
            std::vector(fs[2 * i].begin() + rc, fs[2 * i].begin() + (lc + rc));
        fs[2 * i + 1] = convolve(fs[i], prod[2 * i]);
        fs[2 * i + 1] = std::vector(fs[2 * i + 1].begin() + lc,
                                    fs[2 * i + 1].begin() + (lc + rc));
    }

    std::vector<M> ans(m);
    for (int i = 0; i < m; ++i) {
        ans[i] = fs[l + i][0];
    }
    return ans;
}
