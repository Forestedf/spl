#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum"
#include "../../graph/dynamic_tree_dp_rerooting.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

using M = ModInt<998244353>;

struct TreeDP {
    using Value = pair<M, M>;
    using Func = tuple<M, M, M, M>; // apply (0, 1), add (2, 3)
    V<M> as;
    V<pair<M, M>> fs;
    Value id() const {
        return Value(0, M());
    }
    Value op(Value x, Value y) const {
        return Value(x.first + y.first, x.second + y.second);
    }
    Func composite(Func f, Func g) const {
        auto [f0, f1, f2, f3] = f;
        auto [g0, g1, g2, g3] = g;
        M h0 = f0 * g0;
        M h1 = f0 * g1 + f1;
        M h2 = f0 * g2 + f1 * g3 + f2;
        M h3 = f3 + g3;
        return Func(h0, h1, h2, h3);
    }
    Value apply(Func f, Value x) const {
        x.first = get<0>(f) * x.first + get<1>(f) * x.second;
        x.first += get<2>(f);
        x.second += get<3>(f);
        return x;
    }
    Value vertex(i32 v, Value val) const {
        val.first += as[v];
        val.second += M::raw(1);
        return val;
    }
    Func lift(i32 v, i32 p, i32 e, Value val) const {
        val = vertex(v, val);
        val.first = fs[e].first * val.first + fs[e].second * val.second;
        return tuple<M, M, M, M>(fs[e].first, fs[e].second, val.first, val.second);
    }
};

void solve() {
    i32 n, q;
    rd.read(n, q);
    TreeDP dp;
    dp.as.resize(n);
    REP(i, n) {
        rd.read(dp.as[i].val);
    }
    V<pi> es(n - 1);
    dp.fs.resize(n - 1);
    Graph<int> g(n);
    REP(i, n - 1) {
        i32 u, v;
        M a, b;
        rd.read(u, v, a.val, b.val);
        g.add_edge(u, v);
        dp.fs[i] = pair<M, M>(a, b);
        es[i] = pi(u, v);
    }
    g.build();
    DynamicRerootingDP<TreeDP> rer(g, dp);
    REP(qi, q) {
        i32 ty;
        rd.read(ty);
        if (ty == 0) {
            i32 w, r;
            M x;
            rd.read(w, x.val, r);
            dp.as[w] = x;
            rer.update(w);
            M ans = rer.get(r).first;
            wr.writeln(ans.val);
        } else {
            i32 e, r;
            M y, z;
            rd.read(e, y.val, z.val, r);
            dp.fs[e] = pair<M, M>(y, z);
            rer.update(es[e].first);
            rer.update(es[e].second);
            M ans = rer.get(r).first;
            wr.writeln(ans.val);
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
