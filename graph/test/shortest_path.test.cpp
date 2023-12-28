#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#define FAST_IO
#include "../../graph/dijkstra.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(n, m, s, t);
    Graph<i64, true> g(n);
    REP(i, m) {
        I32(a, b, c);
        g.add_edge(a, b, c);
    }
    g.build();
    auto [dist, par] = dijkstra(g, s, INF64);
    if (dist[t] == INF64) {
        cout << -1 << '\n';
    } else {
        i64 x = dist[t];
        V<i32> route;
        i32 cur = t;
        while (cur != s) {
            route.push_back(cur);
            cur = par[cur];
        }
        route.push_back(s);
        reverse(ALL(route));
        i32 y = LEN(route) - 1;
        cout << x << ' ' << y << '\n';
        REP(i, LEN(route) - 1) {
            cout << route[i] << ' ' << route[i + 1] << '\n';
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
