#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../template/random.hpp"
template <typename T>
class SubsetRangeAddPointGet {
    unsigned l, ty0, ty1, ty2;
    std::vector<T> arr;

    static long long eval(unsigned ty0, unsigned ty1, unsigned ty2,
                          const std::vector<std::pair<unsigned, unsigned>> &add,
                          const std::vector<unsigned> &get) {
        long long cost = 0;
        for (auto [low, high] : add) {
            unsigned tot = ty0 & (low ^ high);
            tot |= ty1 & low;
            tot |= ty2 & high;
            cost += 1LL << __builtin_popcount(tot);
        }
        for (unsigned idx : get) {
            unsigned tot = (ty1 & ~idx) | (ty2 & idx);
            cost += 1LL << __builtin_popcount(tot);
        }
        return cost;
    }

public:
    SubsetRangeAddPointGet(unsigned l) : l(l), ty0(0), ty1(0), ty2(0), arr(1 << l, T()) {
        for (unsigned i = 0; i < l; ++i) {
            int t = uniform(3);
            (t == 0 ? ty0 : (t == 1 ? ty1 : ty2)) += 1u << i;
        }
    }
    void read_queries(const std::vector<std::pair<unsigned, unsigned>> &add,
                      const std::vector<unsigned> &get) {
        ty0 = ty1 = ty2 = 0;
        for (unsigned i = 0; i < l; ++i) {
            unsigned c0 = eval(ty0 | (1u << i), ty1, ty2, add, get);
            unsigned c1 = eval(ty0, ty1 | (1u << i), ty2, add, get);
            unsigned c2 = eval(ty0, ty1, ty2 | (1u << i), add, get);
            unsigned c = std::min({c0, c1, c2});
            (c0 == c ? ty0 : (c1 == c ? ty1 : ty2)) |= 1u << i;
        }
    }
    void add(unsigned low, unsigned high, T v) {
        assert((low | high) == high);
        assert(high < (1u << l));
        unsigned tot = ty0 & (low ^ high);
        tot |= ty1 & low;
        tot |= ty2 & ~high;
        unsigned base = ty0 & low;
        base |= ty1 & (low ^ high);
        base |= ty2 & low;
        unsigned q = (ty1 & low) | (ty2 & ~high);
        T mv = -v;
        if (__builtin_parity(ty1 & low)) {
            std::swap(v, mv);
        }
        for (unsigned st = tot; st; st = (st - 1) & tot) {
            arr[base | st] += (__builtin_parity(q & st) ? mv : v);
        }
        arr[base] += v;
    }
    T get(unsigned idx) const {
        assert(idx < (1u << l));
        unsigned tot = (ty1 & ~idx) | (ty2 & idx);
        unsigned base = (ty0 | ty1) & idx;
        T ans = arr[base];
        for (unsigned st = tot; st; st = (st - 1) & tot) {
            ans += arr[base | st];
        }
        return ans;
    }
};
