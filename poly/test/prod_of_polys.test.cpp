#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
#include "../../poly/fft.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    i32 n;
    rd.read(n);
    if (n == 0) {
        wr.writeln(1);
        return 0;
    }
    deque<V<M>> deq;
    REP(i, n) {
        i32 d;
        rd.read(d);
        V<M> f(d + 1);
        REP(j, d + 1) {
            u32 v;
            rd.read(v);
            f[j] = M::raw(v);
        }
        deq.emplace_back(move(f));
    }
    while (LEN(deq) >= 2) {
        deq.emplace_back(convolve(deq[0], deq[1]));
        deq.pop_front();
        deq.pop_front();
    }
    V<M> ans = deq[0];
    REP(i, LEN(ans)) {
        wr.write(ans[i].val);
        if (i != LEN(ans) - 1) {
            wr.write(' ');
        } else {
            wr.writeln();
        }
    }
}
