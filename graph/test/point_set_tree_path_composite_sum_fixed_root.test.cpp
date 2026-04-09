#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"
#define FAST_IO
#include "../../graph/dynamic_tree_dp.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

using M = ModInt<998244353>;

struct TreeDP {
    using Value = pair<M, M>;
    using Func = tuple<M, M, M, M>;
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
    Func lift(i32 vtx, Value val) const {
        val.first += as[vtx];
        val.second += M::raw(1);
        val.first = fs[vtx].first * val.first + fs[vtx].second * val.second;
        return Func(fs[vtx].first, fs[vtx].second, val.first, val.second);
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
    Graph<pair<M, M>> g(n);
    REP(i, n - 1) {
        i32 u, v;
        M a, b;
        rd.read(u, v, a.val, b.val);
        g.add_edge(u, v, pair<M, M>(a, b));
    }
    g.build();
    dp.fs.resize(n);
    dp.fs[0] = pair<M, M>(M::raw(1), M());
    V<i32> es(n - 1);
    {
        queue<pi> que;
        que.emplace(0, -1);
        while (!que.empty()) {
            auto [v, p] = que.front();
            que.pop();
            for (const auto &e : g[v]) {
                if (e.to != p) {
                    es[e.id] = e.to;
                    dp.fs[e.to] = e.weight;
                    que.emplace(e.to, v);
                }
            }
        }
    }
    DynamicTreeDP<TreeDP> tree(g, dp);
    REP(qi, q) {
        i32 ty;
        rd.read(ty);
        if (ty == 0) {
            i32 w;
            M x;
            rd.read(w, x.val);
            dp.as[w] = x;
            wr.writeln(tree.update(w).first.val);
        } else {
            i32 e;
            M y, z;
            rd.read(e, y.val, z.val);
            dp.fs[es[e]] = pair<M, M>(y, z);
            wr.writeln(tree.update(es[e]).first.val);
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
