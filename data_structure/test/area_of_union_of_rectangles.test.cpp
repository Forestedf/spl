#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"
#define FAST_IO

#include "../../data_structure/union_of_rectangles.hpp"
#include "../../template/template.hpp"

int main() {
    i32 n;
    cin >> n;
    V<tuple<i64, i64, i64, i64>> rects(n);
    for (auto &[l, r, d, u] : rects) {
        cin >> l >> d >> r >> u;
    }
    cout << area_of_union_of_rectangles(rects) << '\n';
}
