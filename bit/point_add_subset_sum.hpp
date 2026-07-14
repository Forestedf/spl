#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <vector>
#include "../template/random.hpp"

template <typename CommutativeMonoid>
class PointAddSubsetSum {
public:
    using Value = typename CommutativeMonoid::Value;

private:
    unsigned l, even;
    std::array<unsigned, 4> mask;
    std::vector<Value> arr;

public:
    PointAddSubsetSum(unsigned l_) : l((l_ + 1) / 2 * 2), even(0), mask(), arr(1 << l, CommutativeMonoid::id()) {
        std::fill(mask.begin(), mask.end(), 0);
        for (unsigned i = 0; i < l; i += 2) {
            mask[uniform(4)] |= 1u << i;
            even |= 1u << i;
        }
    }

    void read_queries(const std::vector<unsigned> &add, const std::vector<unsigned> &get) {
        auto eval = [&] {
            long long cost = 0;
            for (unsigned elem : add) {
                unsigned lo = elem & even;
                unsigned hi = (elem >> 1) & even;
                unsigned d0 = ~lo & ~hi & even;
                unsigned d1 = lo & ~hi;
                unsigned d2 = ~lo & hi;
                unsigned tot = (d0 & (mask[0] | mask[1] | mask[2])) | (d1 & (mask[1] | mask[2] | mask[3])) |
                          (d2 & (mask[0] | mask[2] | mask[3]));
                cost += 1LL << __builtin_popcount(tot);
            }
            for (unsigned elem : get) {
                unsigned lo = elem & even;
                unsigned hi = (elem >> 1) & even;
                unsigned d1 = lo & ~hi;
                unsigned d2 = ~lo & hi;
                unsigned d3 = lo & hi;
                unsigned tot = (d1 & (mask[1] | mask[2] | mask[3])) | (d2 & (mask[0] | mask[2] | mask[3])) |
                          (d3 & (mask[0] | mask[1] | mask[3]));
                cost += 1LL << __builtin_popcount(tot);
            }
            return cost;
        };
        fill(ALL(mask), 0);
        for (unsigned i = 0; i < l; i += 2) {
            long long c[4];
            for (int j = 0; j < 4; ++j) {
                mask[j] ^= 1u << (2 * i);
                c[j] = eval();
                mask[j] ^= 1u << (2 * i);
            }
            int idx = std::min_element(c, c + 4) - c;
            mask[idx] ^= 1u << (2 * i);
        }
    }

    void add(unsigned idx, Value v) {
        unsigned lo = idx & even;
        unsigned hi = (idx >> 1) & even;
        unsigned d0 = ~lo & ~hi & even;
        unsigned d1 = lo & ~hi;
        unsigned d2 = ~lo & hi;
        unsigned add1 = (mask[0] & (d0 | d2)) | ((mask[2] | mask[3]) & d2);
        unsigned add2 = (mask[1] & (d0 | d1)) | ((mask[2] | mask[3]) & d1);
        unsigned add3 = mask[2] & d0;
        unsigned sub = add1 | (add2 << 1);
        for (unsigned st = add3; st; st = (st - 1) & add3) {
            unsigned x = idx ^ st ^ (st << 1);
            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {
                arr[x ^ st2] = CommutativeMonoid::op(arr[x ^ st2], v);
            }
            arr[x] = CommutativeMonoid::op(arr[x], v);
        }
        {
            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {
                arr[idx ^ st2] = CommutativeMonoid::op(arr[idx ^ st2], v);
            }
            arr[idx] = CommutativeMonoid::op(arr[idx], v);
        }
    }

    Value get(unsigned idx) const {
        unsigned lo = idx & even;
        unsigned hi = (idx >> 1) & even;
        unsigned d1 = lo & ~hi;
        unsigned d2 = ~lo & hi;
        unsigned d3 = lo & hi;
        unsigned add1 = (mask[1] & (d1 | d3)) | ((mask[2] | mask[3]) & d1);
        unsigned add2 = (mask[0] & (d2 | d3)) | ((mask[2] | mask[3]) & d2);
        unsigned add3 = mask[3] & d3;
        unsigned sub = add1 | (add2 << 1);
        Value ans = CommutativeMonoid::id();
        for (unsigned st = add3; st; st = (st - 1) & add3) {
            unsigned x = idx ^ st ^ (st << 1);
            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {
                ans = CommutativeMonoid::op(ans, arr[x ^ st2]);
            }
            ans = CommutativeMonoid::op(ans, arr[x]);
        }
        {
            for (unsigned st2 = sub; st2; st2 = (st2 - 1) & sub) {
                ans = CommutativeMonoid::op(ans, arr[idx ^ st2]);
            }
            ans = CommutativeMonoid::op(ans, arr[idx]);
        }
        return ans;
    }
};
