#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#define FAST_IO
#include "../../graph/heavy_light_decomposition.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n, q);
    VEC(i32, p, n - 1);
    Graph<void, true> g(n);
    REP(i, n - 1) {
        g.add_edge(p[i], i + 1);
    }
    g.build();
    HeavyLightDecomposition hld(g);
    REP(qi, q) {
        I32(u, v);
        cout << hld.lca(u, v) << '\n';
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}