#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include "../../poly/find_linear_recurrence.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"
#include "../../template/fastio.hpp"

int main() {
    using M = ModInt<998244353>;
    int n;
    rd.read(n);
    V<M> s(n);
    REP(i, n) {
        rd.read(s[i].val);
    }
    V<M> c = find_linear_recurrence(s);
    i32 d = LEN(c) - 1;
    wr.writeln(d);
    REP(i, 1, d + 1) {
        wr.write((-c[i]).val);
        wr.write(" \n"[i == d]);
    }
}
