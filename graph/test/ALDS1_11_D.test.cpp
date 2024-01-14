#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D"
#define FAST_IO
#include "../../graph/connected_components.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n, m);
    Graph<> g(n);
    REP(i, m) {
        I32(u, v);
        g.add_edge(u, v);
    }
    g.build();
    V<i32> comp = connected_components(g);
    I32(q);
    REP(qi, q) {
        I32(u, v);
        cout << (comp[u] == comp[v] ? "yes\n" : "no\n");
    }
}

int main() {
    solve();
}