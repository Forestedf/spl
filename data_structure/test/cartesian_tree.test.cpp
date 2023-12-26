#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#define FAST_IO

#include "../../template/template.hpp"
#include "../../data_structure/cartesian_tree.hpp"

int main() {
    i32 n;
    cin >> n;
    V<i32> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    V<i32> p = cartesian_tree(a);
    REP(i, n) {
        cout << (p[i] == -1 ? i : p[i]) << " \n"[i + 1 == n];
    }
}