#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#define FAST_IO
#include "../../number_theory/floor_sum.hpp"
#include "../../template/fastio.hpp"
#include "../../template/template.hpp"

void solve() {
    i32 n, m, a, b;
    rd.read(n, m, a, b);
    wr.writeln(floor_sum<i64, i64>(0, n, a, b, m));
}

int main() {
    i32 t = 1;
    rd.read(t);
    while (t--) {
        solve();
    }
}
