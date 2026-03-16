#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"
#include "../../poly/fps_pow_sparse.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, k;
    i64 m;
    rd.read(n, k, m);
    V<M> f(n);
    REP(i, k) {
        i32 pos;
        M val;
        rd.read(pos, val.val);
        f[pos] = val;
    }
    V<M> g = fps_pow_sparse(f, m);
    REP(i, n) {
        wr.write(g[i].val);
        wr.write(" \n"[i + 1 == n]);
    }
}
