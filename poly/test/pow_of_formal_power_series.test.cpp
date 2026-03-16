#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "../../poly/fps_pow.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    i64 m;
    rd.read(n, m);
    V<M> f(n);
    REP(i, n) {
        rd.read(f[i].val);
    }
    V<M> g = fps_pow(f, m);
    REP(i, n) {
        wr.write(g[i].val);
        wr.write(" \n"[i + 1 == n]);
    }
}
