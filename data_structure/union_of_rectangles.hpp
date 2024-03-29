#pragma once
#include "lazy_segment_tree.hpp"
#include <algorithm>
template <typename T>
struct CountMin {
    using Value = std::pair<int, T>;
    using Func = int;
    static Value id() {
        return Value(10010001001, 0);
    }
    static Value op(const Value &x, const Value &y) {
        int m = std::min(x.first, y.first);
        T c = 0;
        if (x.first == m) {
            c += x.second;
        }
        if (y.first == m) {
            c += y.second;
        }
        return Value(m, c);
    }
    static Func func_id() {
        return 0;
    }
    static Func composite(Func f, Func g) {
        return f + g;
    }
    static Value apply(Func f, const Value &x) {
        return Value(f + x.first, x.second);
    }
};
// (l, r, d, u) -> [l, r) * [d, u)
template <typename T>
T area_of_union_of_rectangles(const std::vector<std::tuple<T, T, T, T>> &rects) {
    if (rects.empty()) {
        return 0;
    }
    std::vector<T> xs, ys;
    xs.reserve(2 * rects.size());
    ys.reserve(2 * rects.size());
    for (const auto &[l, r, d, u] : rects) {
        xs.push_back(l);
        xs.push_back(r);
        ys.push_back(d);
        ys.push_back(u);
    }
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    LazySegmentTree<CountMin<T>> seg((int)xs.size() - 1);
    for (int i = 0; i < (int)xs.size() - 1; ++i) {
        seg.update(i, std::pair<int, T>(0, xs[i + 1] - xs[i]));
    }
    std::vector<std::vector<std::pair<int, int>>> add(ys.size()), sub(ys.size());
    for (const auto &[l, r, d, u] : rects) {
        int l_ = (int)(std::lower_bound(xs.begin(), xs.end(), l) - xs.begin());
        int r_ = (int)(std::lower_bound(xs.begin(), xs.end(), r) - xs.begin());
        int d_ = (int)(std::lower_bound(ys.begin(), ys.end(), d) - ys.begin());
        int u_ = (int)(std::lower_bound(ys.begin(), ys.end(), u) - ys.begin());
        add[d_].emplace_back(l_, r_);
        sub[u_].emplace_back(l_, r_);
    }
    T ans = 0;
    T xlen = xs.back() - xs.front();
    for (int i = 0; i < (int)ys.size() - 1; ++i) {
        for (auto [l, r] : add[i]) {
            seg.apply(l, r, 1);
        }
        for (auto [l, r] : sub[i]) {
            seg.apply(l, r, -1);
        }
        T dy = ys[i + 1] - ys[i];
        std::pair<int, T> p = seg.all_prod();
        if (p.first == 0) {
            ans += (xlen - p.second) * dy;
        } else {
            ans += xlen * dy;
        }
    }
    return ans;
}