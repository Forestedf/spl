#pragma once
#include <vector>

// f(i, j, k) = true <=> (i, j) -> (i, k)
// j < k.
template <typename F>
std::vector<int> monotone_minima(int h, int w, F f) {
    std::vector<int> argmin(h);
    auto rec = [&](auto rec, int xl, int xr, int yl, int yr) -> void {
        if (xl == xr) {
            return;
        }
        int xm = (xl + xr) / 2;
        argmin[xm] = yl;
        for (int i = yl + 1; i < yr; ++i) {
            if (f(xm, argmin[xm], i)) {
                argmin[xm] = i;
            }
        }
        rec(rec, xl, xm, yl, argmin[xm] + 1);
        rec(rec, xm + 1, xr, argmin[xm], yr);
    };
    rec(rec, 0, h, 0, w);
    return argmin;
}
