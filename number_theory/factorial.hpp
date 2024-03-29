#pragma once
#include <cassert>
#include <vector>

template <typename M>
M inv(int n) {
    static std::vector<M> data{M::raw(0), M::raw(1)};
    static constexpr unsigned MOD = M::get_mod();
    assert(0 < n);
    while ((int)data.size() <= n) {
        unsigned k = (unsigned)data.size();
        unsigned r = MOD / k + 1;
        data.push_back(M::raw(r) * data[k * r - MOD]);
    }
    return data[n];
}

template <typename M>
M fact(int n) {
    static std::vector<M> data{M::raw(1), M::raw(1)};
    assert(0 <= n);
    while ((int)data.size() <= n) {
        unsigned k = (unsigned)data.size();
        data.push_back(M::raw(k) * data.back());
    }
    return data[n];
}

template <typename M>
M inv_fact(int n) {
    static std::vector<M> data{M::raw(1), M::raw(1)};
    assert(0 <= n);
    while ((int)data.size() <= n) {
        unsigned k = (unsigned)data.size();
        data.push_back(inv<M>(k) * data.back());
    }
    return data[n];
}

template <typename M>
M binom(int n, int k) {
    assert(0 <= n);
    if (k < 0 || n < k) {
        return M::raw(0);
    }
    return fact<M>(n) * inv_fact<M>(k) * inv_fact<M>(n - k);
}

template <typename M>
M n_terms_sum_k(int n, int k) {
    assert(0 <= n && 0 <= k);
    if (n == 0) {
        return (k == 0 ? M::raw(1) : M::raw(0));
    }
    return binom<M>(n + k - 1, n - 1);
}
