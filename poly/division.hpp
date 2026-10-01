#pragma once
#include <utility>
#include "fps_inv.hpp"
// (quotient, remainder)
template <typename T>
std::pair<std::vector<T>, std::vector<T>> poly_div(std::vector<T> f, std::vector<T> g) {
    while (!g.empty() && g.back() == T(0)) {
        g.pop_back();
    }
    assert(!g.empty());
    if (f.size() < g.size()) {
        return std::make_pair(std::vector<T>(0), f);
    }
    int siz = (int)f.size() - (int)g.size() + 1;
    std::vector<T> rf = f, rg = g;
    std::reverse(rf.begin(), rf.end());
    std::reverse(rg.begin(), rg.end());
    rg = fps_inv(rg, siz);
    rf.resize(siz);
    std::vector<T> q = convolve(rf, rg);
    q.resize(siz);
    std::reverse(q.begin(), q.end());
    std::vector<T> gq = convolve(g, q);
    for (int i = 0; i < (int)f.size(); ++i) {
        f[i] -= gq[i];
    }
    while (!f.empty() && f.back() == T(0)) {
        f.pop_back();
    }
    return std::make_pair(q, f);
}
