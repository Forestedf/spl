#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#define FAST_IO

#include "../../data_structure/segment_tree.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../template/template.hpp"

using Mint = ModInt<998244353>;

struct Linear {
    Mint a, b;
    Linear() : a(Mint(1)), b(Mint(0)) {}
    Linear(Mint _a, Mint _b) : a(_a), b(_b) {}
    Mint operator()(Mint x) { return a * x + b; }
};

// f \circ g
Linear composite(const Linear &f, const Linear &g) {
    return Linear(f.a * g.a, f.a * g.b + f.b);
}

struct Ops {
    using Value = Linear;
    static Value id() { return Linear(); }
    static Value op(const Value &x, const Value &y) { return composite(y, x); }
};

int main() {
    i32 n, q;
    cin >> n >> q;
    V<Linear> fs(n);
    REP(i, n) { cin >> fs[i].a >> fs[i].b; }

    SegmentTree<Ops> seg(fs);

    REP(qi, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            i32 p;
            Linear f;
            cin >> p >> f.a >> f.b;
            seg.update(p, f);
        } else {
            i32 l, r;
            Mint x;
            cin >> l >> r >> x;
            cout << seg.prod(l, r)(x) << '\n';
        }
    }
}