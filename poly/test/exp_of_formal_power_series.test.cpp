#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "../../poly/fps_exp.hpp"
#include "../../template/fastio.hpp"
#include "../../template/template.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    V<M> f(n);
    REP(i, n) { rd.read(f[i].val); }
    V<M> g = fps_exp(f);
    REP(i, n) {
        wr.write(g[i].val);
        wr.write(" \n"[i + 1 == n]);
    }
}
