#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse"
#include "../../poly/fps_log_sparse.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n, k;
    rd.read(n, k);
    V<M> f(n);
    REP(i, k) {
        i32 pos;
        M val;
        rd.read(pos, val.val);
        f[pos] = val;
    }
    V<M> g = fps_log_sparse(f);
    REP(i, n) {
        wr.write(g[i].val);
        wr.write(" \n"[i + 1 == n]);
    }
}
