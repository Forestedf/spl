#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#define FAST_IO
#include "spl/graph/biconnected_components.hpp"
#include "spl/template/template.hpp"

void solve() {
    I32(n, m);
    Graph<> g(n);
    REP(i, m) {
        I32(u, v);
        g.add_edge(u, v);
    }
    g.build();
    auto bccs = bi_connected_components(g);
    cout << LEN(bccs) << '\n';
    for (const auto &bcc : bccs) {
        cout << LEN(bcc.vertices);
        for (i32 v : bcc.vertices) {
            cout << ' ' << v;
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