#pragma once
#include <cassert>
#include <vector>
template <typename M>
struct PowTable {
    int n;
    std::vector<M> pow;
    std::vector<M> invpow;
    PowTable(int n, M r) : n(n), pow(n + 1), invpow(n + 1) {
        assert(n >= 0);
        M p = M::raw(1);
        for (int i = 0; i <= n; ++i) {
            pow[i] = p;
            p *= r;
        }
        if (r.val != 0) {
            p = M::raw(1);
            M inv = r.inv();
            for (int i = 0; i <= n; ++i) {
                invpow[i] = p;
                p *= inv;
            }
        }
    }
    M get(int e) const {
        return (e < 0 ? invpow[-e] : pow[e]);
    }
};
