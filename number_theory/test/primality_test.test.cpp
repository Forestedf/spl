#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#define FAST_IO
#include "../../number_theory/primality.hpp"
#include "../../template/template.hpp"

void solve() {
    I32(q);
    REP(qi, q) {
        U64(x);
        cout << (is_prime(x) ? "Yes\n" : "No\n");
    }
}

int main() {
    i32 t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}