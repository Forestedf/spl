#pragma once
#include <cassert>
#include <utility>
#include <functional>

template <typename F, typename I, typename Comp = std::less<>>
auto golden_search(const F &f, I mn, I mx, Comp comp = Comp()) -> std::pair<I, decltype(f(mn))> {
    using V = decltype(f(mn));
    assert(mn <= mx);
    I x0, x1, x2;
    {
        x0 = mn - 1;
        I s = 1, t = 1;
        while (x0 + s + t <= mx) {
            I u = s + t;
            s = t;
            t = u;
        }
        x1 = x0 + s + t;
        x2 = x0 + s;
    }
    V fx2 = f(x2);
    V fx3 = 0;
    while (2 * x2 != x0 + x1) {
        I x3 = x0 + x1 - x2;
        if (x3 > mx) {
            x1 = x0;
            x0 = x3;
        } else {
            fx3 = f(x3);
            if (comp(fx2, fx3)) {
                x1 = x0;
                x0 = x3;
            } else {
                x0 = x2;
                x2 = x3;
                fx2 = fx3;
            }
        }
    }
    return std::pair<I, V>(x2, fx2);
}
