#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#define FAST_IO
#include "../../number_theory/primitive_root.hpp"
#include "../../template/template.hpp"

void solve() {
    U64(p);
    cout << find_primitive_root(p) << '\n';
}

int main() {
    i32 t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
