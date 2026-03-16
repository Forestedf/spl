#pragma once
#include "fps_exp.hpp"
#include "fps_log.hpp"
template <typename T>
std::vector<T> fps_pow_constant_1(const std::vector<T> &f, T m, int len = -1) {
    if (len == -1) {
        len = (int)f.size();
    }
    assert(!f.empty() && f[0] == T(1) && 0 <= len);
    if (len == 0) {
        return std::vector<T>();
    }
    std::vector<T> g = fps_log(f, len);
    for (T &elem : g) {
        elem *= m;
    }
    return fps_exp(g);
}
template <typename T>
std::vector<T> fps_pow(const std::vector<T> &f, long long m, int len = -1) {
    if (len == -1) {
        len = (int)f.size();
    }
    assert(0 <= m && 0 <= len);
    int n = (int)f.size();
    if (m == 0) {
        std::vector<T> g(len);
        if (len) {
            g[0] = T(1);
        }
        return g;
    }
    if (n == 0) {
        return std::vector<T>(len);
    }
    int ord = -1;
    for (int i = 0; i < n; ++i) {
        if (f[i] != T()) {
            ord = i;
            break;
        }
    }
    // ord * m >= len
    if (ord == -1 || (long long)ord >= ((long long)len + m - 1) / m) {
        return std::vector<T>(len);
    }
    int off = ord * m;
    std::vector<T> g(f.begin() + ord, f.end());
    T c = g[0];
    T c_inv = T(1) / c;
    for (T &elem : g) {
        elem *= c_inv;
    }
    g = fps_pow_constant_1(g, T(m), len - off);
    c = c.pow(m);
    std::vector<T> h(len);
    for (int i = 0; i < (int)g.size(); ++i) {
        h[off + i] = g[i] * c;
    }
    return h;
}
