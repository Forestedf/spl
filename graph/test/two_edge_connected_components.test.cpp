#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#define FAST_IO
#include "../../graph/two_edge_connected_components.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n, m);
    Graph<> g(n);
    REP(i, m) {
        I32(u, v);
        g.add_edge(u, v);
    }
    g.build();
    V<i32> comp = two_edge_connected_components(g);
    VV<i32> groups(n);
    REP(i, n) { groups[comp[i]].push_back(i); }
    while (groups.back().empty()) {
        groups.pop_back();
    }
    cout << LEN(groups) << '\n';
    for (const V<i32> &gr : groups) {
        cout << LEN(gr);
        for (i32 v : gr) {
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