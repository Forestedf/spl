#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "../../poly/fps_div_at.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 d;
    i64 k;
    rd.read(d, k);
    V<M> a(d);
    REP(i, d) {
        rd.read(a[i].val);
    }
    V<M> c(d);
    REP(i, d) {
        rd.read(c[i].val);
    }
    V<M> den(d + 1);
    den[0] = M(1);
    REP(i, d) {
        den[i + 1] = -c[i];
    }
    V<M> num = convolve(a, den);
    num.resize(d);
    M ans = fps_div_at(num, den, k);
    wr.writeln(ans.val);
}
