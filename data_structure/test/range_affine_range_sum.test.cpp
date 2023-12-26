#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#define FAST_IO

#include "../../template/template.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../data_structure/lazy_segment_tree.hpp"

using Mint = ModInt<998244353>;

struct Node {
    i32 len;
    Mint sum;
};

struct Fn {
    Mint a, b;
};

struct Ops {
    using Value = Node;
    using Func = Fn;
    static Value id() {
        return Node{0, Mint()};
    }
    static Value op(const Value &x, const Value &y) {
        return Node{x.len + y.len, x.sum + y.sum};
    }
    static Func func_id() {
        return Fn{Mint(1), Mint()};
    }
    static Func composite(const Func &f, const Func &g) {
        return Fn{f.a * g.a, f.a * g.b + f.b};
    }
    static Value apply(const Func &f, const Value &x) {
        return Node{x.len, x.sum * f.a + Mint(x.len) * f.b};
    }
};

int main() {
    i32 n, q;
    cin >> n >> q;
    V<Node> a(n);
    REP(i, n) {
        a[i].len = 1;
        cin >> a[i].sum;
    }
    LazySegmentTree<Ops> seg(a);
    REP(qi, q) {
        i32 type;
        cin >> type;
        if (type == 0) {
            i32 l, r;
            Fn f;
            cin >> l >> r >> f.a >> f.b;
            seg.apply(l, r, f);
        } else {
            i32 l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).sum << '\n';
        }
    }
}