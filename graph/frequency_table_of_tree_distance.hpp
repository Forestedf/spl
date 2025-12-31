#include "centroid_decomposition.hpp"
#include "../poly/fft.hpp"
#include <queue>
template <typename T>
std::vector<long long> frequency_table_of_tree_distance(const Graph<T, false> &g) {
    CentroidDecomposition cd(g);
    using M0 = ModInt<998244353>;
    using M1 = ModInt<924844033>;
    std::vector<M0> cnt0(2 * g.v());
    std::vector<M1> cnt1(2 * g.v());
    std::vector<bool> used(g.v(), false);
    auto tree = cd.get_tree();
    auto rec = [&](auto rec, int cent) -> void {
        used[cent] = true;
        std::vector<M0> prod0(2);
        std::vector<M1> prod1(2);
        for (const Edge<T> &e : g[cent]) {
            if (used[e.to]) {
                continue;
            }
            std::queue<std::tuple<int, int, int>> que;
            std::vector<M0> f0(2);
            std::vector<M1> f1(2);
            que.emplace(e.to, cent, 1);
            while (!que.empty()) {
                auto [v, p, d] = que.front();
                que.pop();
                if (d == (int)f0.size()) {
                    f0.push_back(M0());
                    f1.push_back(M1());
                }
                f0[d] += M0(1);
                f1[d] += M1(1);
                cnt0[d] += M0(2);
                cnt1[d] += M1(2);
                if (d == (int)prod0.size()) {
                    prod0.push_back(M0());
                    prod1.push_back(M1());
                }
                prod0[d] += M0(1);
                prod1[d] += M1(1);
                for (const Edge<T> &e : g[v]) {
                    if (e.to != p && !used[e.to]) {
                        que.emplace(e.to, v, d + 1);
                    }
                }
            }
            f0 = convolve_square(f0);
            f1 = convolve_square(f1);
            for (int i = 0; i < (int)f0.size(); ++i) {
                cnt0[i] -= f0[i];
                cnt1[i] -= f1[i];
            }
        }
        prod0 = convolve_square(prod0);
        prod1 = convolve_square(prod1);
        for (int i = 0; i < (int)prod0.size(); ++i) {
            cnt0[i] += prod0[i];
            cnt1[i] += prod1[i];
        }
        for (const Edge<int> &e : cd[cent]) {
            rec(rec, e.to);
        }
    };
    rec(rec, cd.first_centroid());
    std::vector<long long> ret(g.v());
    constexpr M1 INV = M1(M0::get_mod()).inv();
    for (int i = 0; i < g.v(); ++i) {
        M1 cf = INV * (cnt1[i] - M1(cnt0[i].val));
        ret[i] = (cnt0[i].val + 1LL * M0::get_mod() * cf.val) / 2;
    }
    return ret;
}
