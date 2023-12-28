#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#define FAST_IO
#include "../../data_structure/fenwick_tree.hpp"
#include "../../graph/heavy_light_decomposition.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n, q);
    VEC(i32, a, n);
    Graph<> g(n);
    REP(i, n - 1) {
        I32(u, v);
        g.add_edge(u, v);
    }
    g.build();
    HeavyLightDecomposition hld(g);
    FenwickTreeAdd<i64> fw(n);
    REP(i, n) {
        fw.add(hld.in[i], a[i]);
    }
    REP(qi, q) {
        I32(type);
        if (type == 0) {
            I32(p, x);
            fw.add(hld.in[p], x);
        } else {
            I32(u, v);
            i64 ans = 0;
            for (auto [x, y] : hld.path(u, v, false)) {
                if (x > y) {
                    swap(x, y);
                }
                ans += fw.sum(x, y + 1);
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}