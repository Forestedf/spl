#pragma once
#include "fps_inv.hpp"
#include "middle_product.hpp"

int ceil_log2(int n) {
    return n <= 1 ? 0 : 32 - __builtin_clz(n - 1);
}

template <typename M>
std::vector<M> multieval(std::vector<M> f, const std::vector<M> &p) {
    static constexpr FFTRoot<M::get_mod()> root{};
    const int m = (int)f.size();
    const int _n = (int)p.size();
    const int lg = ceil_log2(_n);
    const int n = 1 << lg;
    const int n2 = n * 2;
    std::vector<std::vector<M>> tree(lg + 1, std::vector<M>(n2));
    for (int i = 0; i < _n; ++i) {
        tree[0][2 * i] = M::raw(1) - p[i];
        tree[0][2 * i + 1] = M::raw(1) + p[i];
    }
    std::fill(tree[0].begin() + 2 * _n, tree[0].end(), M::raw(1));
    for (int ph = 0; ph < lg; ++ph) {
        const int w = 1 << (ph + 1), w2 = w * 2;
        M omega = root.root[ph + 2];
        std::vector<M> &d = tree[ph + 1];
        d = tree[ph];
        for (int i = 0; i < n2; i += w2) {
            const int ti = i + w;
            for (int j = 0; j < w; ++j) {
                d[ti + j] = d[i + j] *= d[ti + j];
            }
            ifft(d.data() + ti, w);
            d[ti] = M::raw(2) - d[ti];
            M pw(1);
            for (int j = 0; j < w; ++j) {
                d[ti + j] *= pw;
                pw *= omega;
            }
            fft(d.data() + ti, w);
        }
    }
    ifft(tree[lg]);
    tree[lg] = fps_inv(tree[lg], m);
    f.resize(2 * m - 1);
    std::vector<M> c = middle_product(tree[lg], f);
    c.resize(n2);
    transposed_ifft(c);
    for (int ph = lg - 1; ph >= 0; --ph) {
        const int w = 1 << (ph + 1), w2 = w * 2;
        M omega = root.root[ph + 2];
        for (int i = 0; i < n2; i += w2) {
            const int ti = i + w;
            transposed_fft(c.data() + ti, w);
            M pw(1);
            for (int j = 0; j < w; ++j) {
                c[ti + j] *= pw;
                pw *= omega;
            }
            transposed_ifft(c.data() + ti, w);
            for (int j = 0; j < w; ++j) {
                M t = c[i + j] + c[ti + j];
                c[i + j] = t * tree[ph][ti + j];
                c[ti + j] = t * tree[ph][i + j];
            }
        }
    }
    std::vector<M> ans(_n);
    for (int i = 0; i < _n; ++i) {
        ans[i] = c[2 * i] + c[2 * i + 1];
    }
    return ans;
}
