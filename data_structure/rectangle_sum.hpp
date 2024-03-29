#pragma once
#include "fenwick_tree.hpp"
#include <algorithm>
template <typename C, typename V>
class RectangleSum {
    struct Point {
        C x, y;
        V v;
    };
    struct Query {
        C xl, xr, yl, yr;
        int idx;
    };
    std::vector<Point> pts;
    std::vector<Query> qrs;
public:
    RectangleSum() : pts(), qrs() {}
    void add_point(C x, C y, V v) {
        pts.emplace_back(Point{x, y, v});
    }
    void add_query(C xl, C xr, C yl, C yr) {
        qrs.emplace_back(Query{xl, xr, yl, yr, (int)qrs.size()});
    }
    std::vector<V> solve() {
        std::sort(pts.begin(), pts.end(), [](const Point &p0, const Point &p1) -> bool {
            return p0.x < p1.x;
        });
        struct Q {
            C x, d, u;
            int id;
            bool is_positive;
        };
        std::vector<Q> q_;
        q_.reserve(2 * qrs.size());
        for (const Query &qr : qrs) {
            q_.push_back(Q{qr.xl, qr.yl, qr.yr, qr.idx, false});
            q_.push_back(Q{qr.xr, qr.yl, qr.yr, qr.idx, true});
        }
        std::sort(q_.begin(), q_.end(), [](const Q &q0, const Q &q1) -> bool {
            return q0.x < q1.x;
        });
        std::vector<C> ys;
        ys.reserve(pts.size());
        for (const Point &p : pts) {
            ys.push_back(p.y);
        }
        std::sort(ys.begin(), ys.end());
        ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
        FenwickTreeAdd<V> fw((int)ys.size());
        std::vector<V> ret(qrs.size(), 0);
        typename std::vector<Point>::iterator it = pts.begin();
        for (const Q &q : q_) {
            while (it != pts.end() && it->x < q.x) {
                int y = (int)(std::lower_bound(ys.begin(), ys.end(), it->y) - ys.begin());
                fw.add(y, it->v);
                ++it;
            }
            int d = (int)(std::lower_bound(ys.begin(), ys.end(), q.d) - ys.begin());
            int u = (int)(std::lower_bound(ys.begin(), ys.end(), q.u) - ys.begin());
            V sum = fw.sum(d, u);
            if (q.is_positive) {
                ret[q.id] += sum;
            } else {
                ret[q.id] -= sum;
            }
        }
        return ret;
    }
};