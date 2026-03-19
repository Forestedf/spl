#pragma once
#include "../number_theory/factorial.hpp"
#include "fft.hpp"

template <typename M>
std::pair<std::vector<M>, std::vector<M>> power_projection_recurrence(
    int n, const std::vector<M> &f, const std::vector<M> &g) {
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
    std::vector<M> p(2 * n), q(2 * n);
    for (int i = 0; i < n; ++i) {
        p[2 * i] = g[i];
        q[2 * i] = -f[i];
    }
    q[0] += M(1);
    std::vector<M> rp(2 * n), rq(2 * n);
    for (int h = n, w = 1; h > 1; h >>= 1, w <<= 1) {
        omega = roots.root[__builtin_ctz(w) + 1];
        for (int i = 0; i < 2 * n; i += 2 * w) {
            std::copy(p.begin() + i, p.begin() + i + w, p.begin() + i + w);
            ifft(p.data() + i + w, w);
            pw = M(1);
            for (int j = i + w; j < i + 2 * w; ++j) {
                p[j] *= pw;
                pw *= omega;
            }
            fft(p.data() + i + w, w);
        }
        for (int i = 0; i < 2 * n; i += 2 * w) {
            std::copy(q.begin() + i, q.begin() + i + w, q.begin() + i + w);
            ifft(q.data() + i + w, w);
            if (i == 0) {
                q[w] -= M(2);
            }
            pw = M(1);
            for (int j = i + w; j < i + 2 * w; ++j) {
                q[j] *= pw;
                pw *= omega;
            }
            fft(q.data() + i + w, w);
        }
        for (int j = 0; j < 2 * w; ++j) {
            for (int i = 0; i < h; ++i) {
                rp[i] = p[2 * w * i + j];
                rq[i] = q[2 * w * i + j];
            }
            std::fill(rp.begin() + h, rp.begin() + 2 * h, M());
            fft(rp.data(), 2 * h);
            std::fill(rq.begin() + h, rq.begin() + 2 * h, M());
            fft(rq.data(), 2 * h);
            for (int i = 0; i < h; ++i) {
                rp[i] = (rp[2 * i] * rq[2 * i + 1] - rp[2 * i + 1] * rq[2 * i]) *
                        INV2 * invs[i];
                rq[i] = rq[2 * i] * rq[2 * i + 1];
            }
            ifft(rp.data(), h);
            ifft(rq.data(), h);
            for (int i = 0; i < h / 2; ++i) {
                p[4 * w * i + j] = rp[i];
                p[4 * w * i + 2 * w + j] = M();
                q[4 * w * i + j] = rq[i];
                q[4 * w * i + 2 * w + j] = M();
            }
        }
    }
    p.resize(n);
    ifft(p);
    q.resize(n + 1);
    ifft(q.data(), n);
    q[0] -= M(1);
    q[n] = M(1);
    std::reverse(p.begin(), p.end());
    std::reverse(q.begin(), q.end());
    return std::make_pair(p, q);
}

template <typename M>
std::vector<M> power_projection(std::vector<M> wt, std::vector<M> f, int m) {
    assert(wt.size() == f.size());
    int n = 1;
    while (n < (int)f.size()) {
        n *= 2;
    }
    wt.resize(n);
    f.resize(n);
    std::reverse(wt.begin(), wt.end());
    M c = std::exchange(f[0], M());
    std::vector<M> b = power_projection_recurrence(n, f, wt).first;
    if (c == M()) {
        return b;
    }
    b.resize(m);
    for (int i = 0; i < m; ++i) {
        b[i] *= inv_fact<M>(i);
    }
    std::vector<M> cf(m);
    M pw(1);
    for (int i = 0; i < m; ++i) {
        cf[i] = pw * inv_fact<M>(i);
        pw *= c;
    }
    std::vector<M> ret = convolve(b, cf);
    ret.resize(m);
    for (int i = 0; i < m; ++i) {
        ret[i] *= fact<M>(i);
    }
    return ret;
}
