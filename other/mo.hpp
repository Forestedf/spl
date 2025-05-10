#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

class MoManager {
    int n, q, buc;
    std::vector<int> l, r;

public:
    MoManager(int n, int q) : n(n), q(q), buc(0), l(), r() {
        assert(n >= 0);
        assert(q >= 0);
        buc = std::max(1, (int)std::round(std::sqrt(3) * n /
                                          std::max(1., std::sqrt(2 * q))));
        l.reserve(q);
        r.reserve(q);
    }
    void add_query(int l_, int r_) {
        assert(0 <= l_ && l_ <= r_ && r_ <= n);
        assert((int)l.size() < q);
        l.push_back(l_);
        r.push_back(r_);
    }
    template <typename F1, typename F2, typename F3, typename F4, typename F5>
    void run(F1 add_left, F2 add_right, F3 remove_left, F4 remove_right,
             F5 answer) {
        std::vector<int> idx(q);
        for (int i = 0; i < q; ++i) {
            idx[i] = i;
        }
        std::sort(idx.begin(), idx.end(), [&](int i, int j) -> bool {
            if (l[i] / buc != l[j] / buc) {
                return l[i] < l[j];
            }
            if (l[i] / buc % 2 == 0) {
                return r[i] < r[j];
            }
            return r[j] > r[i];
        });
        int ll = 0, rr = 0;
        for (int i : idx) {
            while (ll > l[i]) {
                add_left(--ll);
            }
            while (rr < r[i]) {
                add_right(rr++);
            }
            while (ll < l[i]) {
                remove_left(ll++);
            }
            while (rr > r[i]) {
                remove_right(--rr);
            }
            answer(i);
        }
    }
    template <typename F1, typename F2, typename F3>
    void run(F1 add, F2 remove, F3 answer) {
        run(add, add, remove, remove, answer);
    }
};
