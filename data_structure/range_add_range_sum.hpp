#pragma once

#include "fenwick_tree.hpp"

template <typename T>
class RangeAddRangeSum {
    int n;
    FenwickTree<Add<T>> ft0;
    FenwickTree<Add<T>> ft1;

public:
    RangeAddRangeSum(int n) : n(n), ft0(n + 1), ft1(n + 1) {}

    void add(int l, int r, const T &v) {
        assert(0 <= l && l <= r && r <= n);
        ft0.add(l, v);
        ft0.add(r, -v);
        ft1.add(l, -T(l) * v);
        ft1.add(r, T(r) * v);
    }

    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return T(r) * ft0.sum(r) + ft1.sum(r) - T(l) * ft0.sum(l) - ft1.sum(l);
    }
};