#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#define FAST_IO
#include "../../graph/block_cut_tree.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n, m);
    Graph<> g(n);
    REP(i, m) {
        I32(u, v);
        g.add_edge(u, v);
    }
    g.build();
    Graph<> bct = block_cut_tree(g);
    cout << bct.v() - n << '\n';
    REP(i, n, bct.v()) {
        cout << LEN(bct[i]);
        for (auto e : bct[i]) {
            cout << ' ' << e.to;
        }
        cout << '\n';
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}