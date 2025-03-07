#pragma once
#include <vector>
// trailing zeros が存在することがある
template <typename T>
std::vector<T> find_linear_recurrence(const std::vector<T> &s) {
    int n = (int)s.size(), d = 0, e = 0, m = 0;
    std::vector<T> b(n + 1, T(0)), c(n + 1, T(0));
    b[0] = T(1);
    c[0] = T(1);
    T v(1);
    for (int i = 0; i < n; ++i) {
        ++m;
        T delta = 0;
        for (int j = 0; j <= d; ++j) {
            delta += c[j] * s[i - j];
        }
        if (delta != T(0)) {
            T r = delta * v;
            if (2 * d <= i) {
                std::vector<T> cc = c;
                for (int j = m; j <= m + e; ++j) {
                    c[j] -= r * b[j - m];
                }
                b.swap(cc);
                e = d;
                d = i + 1 - d;
                m = 0;
                v = T(1) / delta;
            } else {
                for (int j = m; j <= m + e; ++j) {
                    c[j] -= r * b[j - m];
                }
            }
        }
    }
    c.resize(d + 1);
    return c;
}
