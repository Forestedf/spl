#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#define FAST_IO
#include "../../string/z_algorithm.hpp"
#include "../../template/template.hpp"

void solve() {
    STR(s);
    V<i32> z = z_algorithm(s);
    REP(i, LEN(s)) { cout << z[i] << " \n"[i + 1 == LEN(s)]; }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
