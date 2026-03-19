#pragma once
#include "../number_theory/factorial.hpp"
#include "fft.hpp"
#include "taylor_shift.hpp"

template <typename M>
void transposed_fft(M *a, int n) {
    ifft(a, n);
    std::reverse(a + 1, a + n);
    M c(n);
    for (int i = 0; i < n; ++i) {
        a[i] *= c;
    }
}
template <typename M>
void transposed_fft(std::vector<M> &a) {
    transposed_fft(a.data(), (int)a.size());
}

template <typename M>
void transposed_ifft(M *a, int n) {
    static constexpr FFTRoot<M::get_mod()> roots;
    std::reverse(a + 1, a + n);
    fft(a, n);
    M c = roots.inv2[__builtin_ctz(n)];
    for (int i = 0; i < n; ++i) {
        a[i] *= c;
    }
}
template <typename M>
void transposed_ifft(std::vector<M> &a) {
    transposed_ifft(a.data(), (int)a.size());
}

template <typename M>
std::vector<M> transposed_power_projection(int n, const std::vector<M> &f, const std::vector<M> &g) {
    static constexpr FFTRoot<M::get_mod()> roots;
    static constexpr M INV2 = M(2).inv();
    int lg = __builtin_ctz(n);
    std::vector<int> btr(n, 0);
    for (int i = 1; i < n; ++i) {
        btr[i] = (btr[i >> 1] >> 1) | ((i & 1) << (lg - 1));
    }
    M omega = roots.iroot[lg + 1];
    M pw(1);
    std::vector<M> invs(n);
    for (int idx : btr) {
        invs[idx] = pw;
        pw *= omega;
    }
    std::vector<M> p = g;
    std::reverse(p.begin(), p.end());
    transposed_ifft(p);
    p.resize(2 * n);
    std::vector<M> q(2 * n);
    for (int i = 0; i < n; ++i) {
        q[2 * i] = -f[i];
    }
    q[0] += M(1);
    auto rec = [&](auto rec, int h, int w) -> void {
        if (h == 1) {
            return;
        }
        M omega = roots.root[__builtin_ctz(w) + 1];
        for (int i = 0; i < 2 * n; i += 2 * w) {
            std::copy(q.begin() + i, q.begin() + i + w, q.begin() + i + w);
            ifft(q.data() + i + w, w);
            if (i == 0) {
                q[i + w] -= M(2);
            }
            M pw(1);
            for (int j = i + w; j < i + 2 * w; ++j) {
                q[j] *= pw;
                pw *= omega;
            }
            fft(q.data() + i + w, w);
        }
        std::vector<std::vector<M>> rq(2 * w, std::vector<M>(2 * h));
        std::vector<M> wq(h);
        for (int j = 0; j < 2 * w; ++j) {
            for (int i = 0; i < h; ++i) {
                rq[j][i] = q[2 * w * i + j];
            }
            fft(rq[j]);
            for (int i = 0; i < h; ++i) {
                wq[i] = rq[j][2 * i] * rq[j][2 * i + 1];
            }
            ifft(wq);
            for (int i = 0; i < h / 2; ++i) {
                q[4 * w * i + j] = wq[i];
                q[4 * w * i + j + 2 * w] = M();
            }
        }
        rec(rec, h / 2, w * 2);
        std::vector<M> rp(2 * h);
        for (int j = 0; j < 2 * w; ++j) {
            for (int i = 0; i < h / 2; ++i) {
                wq[i] = p[4 * w * i + j];
            }
            std::fill(wq.begin() + h / 2, wq.end(), M());
            transposed_ifft(wq);
            for (int i = 0; i < h; ++i) {
                rp[2 * i] = wq[i] * rq[j][2 * i + 1] * INV2 * invs[i];
                rp[2 * i + 1] = -wq[i] * rq[j][2 * i] * INV2 * invs[i];
            }
            transposed_fft(rp);
            for (int i = 0; i < h; ++i) {
                p[2 * w * i + j] = rp[i];
            }
        }
        for (int i = 0; i < 2 * n; i += 2 * w) {
            transposed_fft(p.data() + i + w, w);
            M pw(1);
            for (int j = i + w; j < i + 2 * w; ++j) {
                p[j] *= pw;
                pw *= omega;
            }
            transposed_ifft(p.data() + i + w, w);
            for (int j = i; j < i + w; ++j) {
                p[j] += p[j + w];
                p[j + w] = M();
            }
        }
    };
    rec(rec, n, 1);
    std::vector<M> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = p[2 * i];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// f(g(x)), length: max(f.size(), g.size())
template <typename M>
std::vector<M> compose(std::vector<M> f, std::vector<M> g) {
    if (f.empty() || g.empty()) {
        return std::vector<M>();
    }
    int m = (int)std::max(f.size(), g.size());
    int n = 1;
    while (n < m) {
        n *= 2;
    }
    f.resize(n);
    g.resize(n);
    if (g[0] != M()) {
        f = taylor_shift(f, g[0]);
        g[0] = M();
    }
    std::vector<M> h = transposed_power_projection(n, g, f);
    h.resize(m);
    return h;
}
