#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#define FAST_IO
#include "../../number_theory/factorize.hpp"
#include "../../template/fastio.hpp"
#include "../../template/template.hpp"

void solve() {
    u64 n;
    rd.read(n);
    V<u64> ps = factorize(n);
    wr.write(LEN(ps));
    for (i64 p : ps) {
        wr.write(' ');
        wr.write(p);
    }
    wr.writeln();
}

int main() {
    i32 t = 1;
    rd.read(t);
    while (t--) {
        solve();
    }
}
