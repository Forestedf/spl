#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"
#define FAST_IO
#include "../../graph/enumerate_triangles.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

void solve() {
    using M = ModInt<998244353>;
    i32 n, m;
    rd.read(n, m);
    V<M> x(n);
    REP(i, n) {
        rd.read(x[i].val);
    }
    Graph<> g(n);
    REP(i, m) {
        i32 u, v;
        rd.read(u, v);
        g.add_edge(u, v);
    }
    g.build();
    M ans;
    auto f = [&](i32 u, i32 v, i32 w) -> void {
        ans += x[u] * x[v] * x[w];
    };
    enumerate_triangles(g, f);
    cout << ans << '\n';
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
