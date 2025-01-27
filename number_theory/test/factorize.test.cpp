#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#define FAST_IO
#include "../../number_theory/factorize.hpp"
#include "../../template/template.hpp"

void solve() {
    U64(n);
    V<u64> ps = factorize(n);
    cout << LEN(ps);
    for (i64 p : ps) {
        cout << ' ' << p;
    }
    cout << '\n';
}

int main() {
    i32 t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
