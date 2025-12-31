#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#define FAST_IO
#include "../../graph/frequency_table_of_tree_distance.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n);
    Graph<> g(n);
    REP(i, n - 1) {
        I32(u, v);
        g.add_edge(u, v);
    }
    g.build();
    V<i64> cnt = frequency_table_of_tree_distance(g);
    REP(i, 1, n) {
        cout << cnt[i] << " \n"[i + 1 == n];
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
