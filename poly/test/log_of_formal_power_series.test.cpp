#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "../../poly/fps_log.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    V<M> f(n);
    REP(i, n) {
        rd.read(f[i].val);
    }
    V<M> g = fps_log(f);
    REP(i, n) {
        wr.write(g[i].val);
        wr.write(" \n"[i + 1 == n]);
    }
}
