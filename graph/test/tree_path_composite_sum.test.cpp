#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#define FAST_IO
#include "../../graph/rerooting.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

using M = ModInt<998244353>;

void solve() {
    i32 n;
    rd.read(n);
    V<M> a(n);
    REP(i, n) {
        rd.read(a[i].val);
    }
    V<pair<M, M>> fs(n - 1);
    Graph<> g(n);
    REP(i, n - 1) {
        i32 u, v;
        rd.read(u, v, fs[i].first.val, fs[i].second.val);
        g.add_edge(u, v);
    }
    g.build();
    
    // sum, cnt
    using Data = pair<M, M>;
    auto rake = [](Data x, Data y) {
        return Data(x.first + y.first, x.second + y.second);
    };
    auto add_vertex = [&](Data x, int v) -> Data {
        return Data(x.first + a[v], x.second + M(1));
    };
    auto add_edge = [&](Data x, int v, int nr, int e) -> Data {
        auto [a, b] = fs[e];
        return Data(x.first * a + x.second * b, x.second);
    };
    Data id;
    
    RerootingDP<Data> dp(g, rake, add_vertex, add_edge, id);
    REP(i, n) {
        M ans = dp[i].first;
        wr.writeln(ans.val);
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
