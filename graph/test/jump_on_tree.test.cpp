#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#define FAST_IO
#include "../../graph/heavy_light_decomposition.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n, q);
    Graph<i32, false> g(n);
    REP(i, n - 1) {
        I32(a, b);
        g.add_edge(a, b);
    }
    g.build();
    HeavyLightDecomposition hld(g);
    REP(qi, q) {
        I32(s, t, i);
        cout << hld.jump(s, t, i) << '\n';
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}