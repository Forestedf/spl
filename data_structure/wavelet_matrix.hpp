#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include "bit_vector.hpp"

template <typename T>
class WaveletMatrix {
    int n;
    int ht;
    std::vector<BitVector> vecs;

public:
    WaveletMatrix(std::vector<T> a) : n((int)a.size()), ht(0), vecs() {
        assert(n > 0);
        for (T ele : a) {
            assert(ele >= 0);
        }

        T mx = std::max(T(1), *std::max_element(a.begin(), a.end()));
        ht = (int)floor_log2(mx) + 1;
        vecs.reserve(ht);

        for (T d = ht; d-- > 0;) {
            BitVector vec(n);
            for (int i = 0; i < n; ++i) {
                if (ith_bit(a[i], d)) {
                    vec.rev(i);
                }
            }
            vec.build();
            std::vector<T> nxt(n);
            auto it0 = nxt.begin();
            auto it1 = nxt.begin() + vec.all_zeros();
            for (int i = 0; i < n; ++i) {
                if (vec[i]) {
                    *(it1++) = a[i];
                } else {
                    *(it0++) = a[i];
                }
            }
            std::swap(nxt, a);
            vecs.emplace_back(std::move(vec));
        }
    }

    T access(int idx) const {
        assert(0 <= idx && idx < n);
        T ret(0);
        for (int i = 0; i < ht; ++i) {
            ret <<= 1;
            if (vecs[i][idx]) {
                ret ^= 1;
                idx = vecs[i].all_zeros() + vecs[i].rank1(idx);
            } else {
                idx = vecs[i].rank0(idx);
            }
        }
        return ret;
    }

    T kth_smallest(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n && 0 <= k && k < r - l);
        T ret = 0;
        for (int i = 0; i < ht; ++i) {
            int l0 = vecs[i].rank0(l);
            int r0 = vecs[i].rank0(r);
            ret <<= 1;
            if (k < r0 - l0) {
                l = l0;
                r = r0;
            } else {
                ret ^= T(1);
                l += vecs[i].all_zeros() - l0;
                r += vecs[i].all_zeros() - r0;
                k -= r0 - l0;
            }
        }
        return ret;
    }
    T kth_largest(int l, int r, int k) const {
        return kth_smallest(l, r, r - l - k - 1);
    }

    // no two ranges intersect
    T kth_smallest_many_ranges(std::vector<std::pair<int, int>> ranges,
                               int k) const {
        int s = 0;
        for (auto [l, r] : ranges) {
            assert(0 <= l && l <= r && r <= n);
            s += r - l;
        }
        assert(0 <= k && k < s);
        T ret = 0;
        for (int i = 0; i < ht; ++i) {
            int zs = 0;
            for (auto [l, r] : ranges) {
                zs += vecs[i].rank0(r) - vecs[i].rank0(l);
            }
            ret <<= 1;
            if (k < zs) {
                for (auto &[l, r] : ranges) {
                    l = vecs[i].rank0(l);
                    r = vecs[i].rank0(r);
                }
            } else {
                ret ^= T(1);
                for (auto &[l, r] : ranges) {
                    l = vecs[i].all_zeros() + vecs[i].rank1(l);
                    r = vecs[i].all_zeros() + vecs[i].rank1(r);
                }
                k -= zs;
            }
        }
        return ret;
    }

    // count i s.t. i \in [l, r) and a[i] = v
    int rank(int l, int r, T v) const {
        assert(0 <= l && l <= r && r <= n);
        if (v != 0 && floor_log2(v) >= ht) {
            return 0;
        }
        for (int i = 0; i < ht; ++i) {
            int l0 = vecs[i].rank0(l);
            int r0 = vecs[i].rank0(r);
            if (ith_bit(v, ht - 1 - i)) {
                l += vecs[i].all_zeros() - l0;
                r += vecs[i].all_zeros() - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return r - l;
    }

    // count i s.t. i \in [l, r) and a[i] < upper
    int range_freq(int l, int r, T upper) const {
        assert(0 <= l && l < r && r <= n);
        if (upper != 0 && floor_log2(upper) >= ht) {
            return r - l;
        }
        int cnt = 0;
        for (int i = 0; i < ht; ++i) {
            int l0 = vecs[i].rank0(l);
            int r0 = vecs[i].rank0(r);
            if (ith_bit(upper, ht - 1 - i)) {
                cnt += r0 - l0;
                l += vecs[i].all_zeros() - l0;
                r += vecs[i].all_zeros() - r0;
            } else {
                l = l0;
                r = r0;
            }
        }
        return cnt;
    }
    // count i s.t. i \in [l, r) and a[i] \in [lower, upper)
    int range_freq(int l, int r, T lower, T upper) const {
        if (lower >= upper) {
            return 0;
        } else {
            return range_freq(l, r, upper) - range_freq(l, r, lower);
        }
    }

    // max v s.t. v \in a[l, r) and v < upper
    int prev(int l, int r, T upper) const {
        int freq = range_freq(l, r, upper);
        if (freq == 0) {
            return T(-1);
        } else {
            return kth_smallest(l, r, freq - 1);
        }
    }

    // min v s.t. v \in a[l, r) and v \geq lower
    int next(int l, int r, T lower) const {
        int freq = range_freq(l, r, lower);
        if (freq == r - l) {
            return T(-1);
        } else {
            return kth_smallest(l, r, freq);
        }
    }
};