#pragma once

#include <algorithm>
#include <cassert>
#include <utility>

// f :: I -> I -> bool
template <typename I, typename F>
std::pair<I, I> get_lim_true(I bound, F f) {
    assert(bound >= 1);
    std::pair<I, I> ok(0, 1), ng(1, 0);
    if (!f(0, 1)) {
        std::swap(ok, ng);
    }
    while (true) {
        std::pair<I, I> now(ok.first + ng.first, ok.second + ng.second);
        bool rt = f(now.first, now.second);
        std::pair<I, I> &from = (rt ? ok : ng), &to = (rt ? ng : ok);
        I l = 1, r = 2;
        while (f(from.first + to.first * r, from.second + to.second * r) == rt) {
            l *= 2;
            r *= 2;
            if (std::max(from.first + to.first * l, from.second + to.second * l) > bound) {
                if (rt) {
                    I t = l;
                    if (to.first != 0) {
                        t = std::min(t, (bound - from.first) / to.first);
                    }
                    if (to.second != 0) {
                        t = std::min(t, (bound - from.second) / to.second);
                    }
                    return std::pair<I, I>(from.first + to.first * t, from.second + to.second * t);
                } else {
                    return ok;
                }
            }
        }
        while (r - l > 1) {
            I mid = (l + r) / 2;
            std::pair<I, I> nxt(from.first + to.first * mid, from.second + to.second * mid);
            if (std::max(nxt.first, nxt.second) <= bound && f(nxt.first, nxt.second) == rt) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (std::max(from.first + to.first * r, from.second + to.second * r) > bound) {
            if (rt) {
                return std::pair<I, I>(from.first + to.first * l, from.second + to.second * l);
            } else {
                return to;
            }
        }
        from.first += to.first * l;
        from.second += to.second * l;
    }
    assert(false);
}