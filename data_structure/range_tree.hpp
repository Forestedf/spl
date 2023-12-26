#pragma once

#include <algorithm>
#include <vector>
#include <tuple>

template <typename Coordinate, typename CommutativeGroup>
class RangeTree {
public:
    using Value = typename CommutativeGroup::Value;

private:
    struct Node {
        std::vector<Coordinate> ys;
        std::vector<Value> cum;

        Value sum(Coordinate yl, Coordinate yr) const {
            int yli =
                (int)(std::lower_bound(ys.begin(), ys.end(), yl) - ys.begin());
            int yri =
                (int)(std::lower_bound(ys.begin(), ys.end(), yr) - ys.begin());
            return CommutativeGroup::op(CommutativeGroup::inv(cum[yli]),
                                        cum[yri]);
        }
    };

    static void dedup(std::vector<Coordinate> &xs) {
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    }
    static int index(const std::vector<Coordinate> &xs, int x) {
        return (int)(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin());
    }

    std::vector<Node> nodes;
    std::vector<Coordinate> xs;

public:
    RangeTree(const std::vector<std::tuple<Coordinate, Coordinate, Value>> &pts)
        : nodes(), xs() {
        xs.reserve(pts.size());
        for (const auto &[x, _y, _w] : pts) {
            xs.push_back(x);
        }
        dedup(xs);
        nodes.resize(xs.size());
        for (const auto &[x, y, _w] : pts) {
            int xi = index(xs, x);
            for (; xi < (int)xs.size(); xi |= xi + 1) {
                nodes[xi].ys.push_back(y);
            }
        }
        for (Node &node : nodes) {
            dedup(node.ys);
            node.cum.resize(node.ys.size() + 1, CommutativeGroup::id());
        }
        for (const auto &[x, y, w] : pts) {
            int xi = index(xs, x);
            for (; xi < (int)xs.size(); xi |= xi + 1) {
                int yi = index(nodes[xi].ys, y);
                nodes[xi].cum[yi + 1] =
                    CommutativeGroup::op(nodes[xi].cum[yi + 1], w);
            }
        }
        for (Node &node : nodes) {
            for (int i = 1; i < (int)node.cum.size(); ++i) {
                node.cum[i] =
                    CommutativeGroup::op(node.cum[i - 1], node.cum[i]);
            }
        }
    }

    Value sum(Coordinate xr, Coordinate yl, Coordinate yr) const {
        int xri = index(xs, xr);
        Value s = CommutativeGroup::id();
        for (; xri > 0; xri &= xri - 1) {
            s = CommutativeGroup::op(s, nodes[xri - 1].sum(yl, yr));
        }
        return s;
    }

    Value sum(Coordinate xl, Coordinate xr, Coordinate yl,
              Coordinate yr) const {
        Value l = sum(xl, yl, yr), r = sum(xr, yl, yr);
        return CommutativeGroup::op(r, CommutativeGroup::inv(l));
    }
};