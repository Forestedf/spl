#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../template/template.hpp"
#include "../../template/fastio.hpp"
#include "../../number_theory/mod_int.hpp"
#include "../../data_structure/dual_segment_tree.hpp"

using M = ModInt<998244353>;

struct Fn {
    M a, b;
};

struct Ops {
    using Value = M;
    using Func = Fn;
    static Func func_id() {
        return Fn{M(1), M()};
    }
    static Func composite(const Func &f, const Func &g) {
        return Fn{f.a * g.a, f.a * g.b + f.b};
    }
    static Value apply(const Func &f, const Value &x) {
        return f.a * x + f.b;
    }
};

int main() {
    i32 n, q;
    rd.read(n, q);
    V<M> a(n);
    REP(i, n) {
        rd.read(a[i].val);
    }
    DualSegmentTreeWithValues<Ops> seg(a);
    REP(qi, q) {
        i32 type;
        rd.read(type);
        if (type == 0) {
            i32 l, r;
            Fn f;
            rd.read(l, r, f.a.val, f.b.val);
            seg.apply(l, r, f);
        } else {
            i32 i;
            rd.read(i);
            wr.writeln(seg.get(i).val);
        }
    }
}
