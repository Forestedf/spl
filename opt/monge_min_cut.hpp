#pragma once
#include <atcoder/maxflow>
template <typename T>
class MongeMinCut {
    int n;
    std::vector<int> k;
    std::vector<int> offset;
    int s;
    int t;
    T all;
    atcoder::mf_graph<T> graph;
    T big;
    void add_v(int v, T f0, T f1) {
        if (f0 <= f1) {
            add_0(f0);
            graph.add_edge(s, v, f1 - f0);
        } else {
            add_0(f1);
            graph.add_edge(v, t, f0 - f1);
        }
    }

public:
    MongeMinCut(const std::vector<int> &k, T big)
        : n((int)k.size()),
          k(k),
          offset(n, 0),
          s(0),
          t(0),
          all(0),
          graph(0),
          big(big) {
        for (int i = 0; i < n; ++i) {
            assert(k[i] >= 1);
        }
        for (int i = 0; i < n - 1; ++i) {
            offset[i + 1] = offset[i] + k[i] - 1;
        }
        s = 0;
        for (int i = 0; i < n; ++i) {
            s += k[i];
        }
        t = s + 1;
        graph = atcoder::mf_graph<T>(s + 2);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k[i] - 2; ++j) {
                graph.add_edge(offset[i] + j + 1, offset[i] + j, big);
            }
        }
    }
    void add_0(T v) { all += v; }
    void add_1(int i, const std::vector<T> &f) {
        assert(0 <= i && i < n && (int)f.size() == k[i]);
        add_0(f[0]);
        for (int j = 0; j < k[i] - 1; ++j) {
            add_v(offset[i] + j, f[j + 1] - f[j], 0);
        }
    }
    void add_2(int x, int y, std::vector<std::vector<T>> f) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        assert((int)f.size() == k[x]);
        for (int i = 0; i < k[x]; ++i) {
            assert((int)f[i].size() == k[y]);
        }
        std::vector<T> tmp(k[x]);
        for (int i = 0; i < k[x]; ++i) {
            tmp[i] = f[i][0];
        }
        add_1(x, tmp);
        for (int i = 0; i < k[x]; ++i) {
            for (int j = 0; j < k[y]; ++j) {
                f[i][j] -= tmp[i];
            }
        }
        tmp = f[0];
        add_1(y, tmp);
        for (int i = 0; i < k[x]; ++i) {
            for (int j = 0; j < k[y]; ++j) {
                f[i][j] -= tmp[j];
            }
        }
        for (int i = 0; i < k[x] - 1; ++i) {
            for (int j = 0; j < k[y] - 1; ++j) {
                T val = f[i][j] + f[i + 1][j + 1] - f[i + 1][j] - f[i][j + 1];
                assert(val <= 0);
                add_0(val);
                graph.add_edge(offset[x] + i, offset[y] + j, -val);
                graph.add_edge(s, offset[x] + i, -val);
            }
        }
    }
    std::pair<T, std::vector<int>> solve() {
        T cost = graph.flow(s, t) + all;
        std::vector<bool> cut = graph.min_cut(s);
        std::vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k[i] - 1; ++j) {
                if (cut[offset[i] + j]) {
                    ++ans[i];
                }
            }
        }
        return std::pair<T, std::vector<int>>(cost, ans);
    }
};
