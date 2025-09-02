#pragma once
#include "../opt/monotone_minima.hpp"
#include <cassert>

template <typename T>
std::vector<T> min_plus_convolution_convex_convex(const std::vector<T> &a, const std::vector<T> &b) {
    if (a.empty() || b.empty()) {
        return std::vector<T>(0);
    }
    int n = (int)a.size();
    int m = (int)b.size();
    std::vector<T> c(n + m - 1);
    c[0] = a[0] + b[0];
    int ita = 0, itb = 0;
    for (int i = 0; i < n + m - 2; ++i) {
        if (itb == m - 1 || (ita != n - 1 && a[ita + 1] - a[ita] < b[itb + 1] - b[itb])) {
            c[i + 1] = c[i] + (a[ita + 1] - a[ita]);
            ++ita;
        } else {
            c[i + 1] = c[i] + (b[itb + 1] - b[itb]);
            ++itb;
        }
    }
    return c;
}

template <typename T>
std::vector<T> min_plus_convolution_convex_arbitrary(const std::vector<T> &a, const std::vector<T> &b) {
    if (a.empty() || b.empty()) {
        return std::vector<T>(0);
    }
    int n = (int)a.size();
    int m = (int)b.size();
    auto select = [&](int i, int j, int k) -> bool {
        if (i < k) {
            return false;
        }
        if (i - j >= n) {
            return true;
        }
        return a[i - j] + b[j] > a[i - k] + b[k];
    };
    std::vector<int> argmin = monotone_minima(n + m - 1, m, select);
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; ++i) {
        c[i] = a[i - argmin[i]] + b[argmin[i]];
    }
    return c;
}

template <typename T>
bool is_convex(const std::vector<T> &a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 2; ++i) {
        if (a[i + 1] - a[i] > a[i + 2] - a[i + 1]) {
            return false;
        }
    }
    return true;
}

// is_convex(a) || is_convex(b)
template <typename T>
std::vector<T> min_plus_convolution(const std::vector<T> &a, const std::vector<T> &b) {
    bool ica = is_convex(a);
    bool icb = is_convex(b);
    if (ica && icb) {
        return min_plus_convolution_convex_convex(a, b);
    } else if (ica) {
        return min_plus_convolution_convex_arbitrary(a, b);
    } else if (icb) {
        return min_plus_convolution_convex_arbitrary(b, a);
    } else {
        assert(false);
    }
}
