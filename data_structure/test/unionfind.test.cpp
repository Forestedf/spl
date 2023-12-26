#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#define FAST_IO

#include "../../data_structure/union_find.hpp"
#include "../../template/template.hpp"

int main() {
    i32 n, q;
    cin >> n >> q;
    UnionFind uf(n);
    REP(qi, q) {
        i32 t;
        cin >> t;
        if (t == 0) {
            i32 u, v;
            cin >> u >> v;
            uf.unite(u, v);
        } else {
            i32 u, v;
            cin >> u >> v;
            cout << uf.same(u, v) << '\n';
        }
    }
}