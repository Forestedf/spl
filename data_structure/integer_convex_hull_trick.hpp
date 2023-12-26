#pragma once

#include <cassert>
#include <functional>
#include <utility>
#include <vector>

template <typename T, typename Compare = std::less<T>>
class IntegerConvexHullTrick {
    Compare comp;
    std::vector<std::pair<T, T>> lines;

    inline T floor_div(T x, T y) const {
        if (y < 0) {
            return floor_div(-x, -y);
        } else {
            if (x < 0) {
                return -(-x + y - 1) / y;
            } else {
                return x / y;
            }
        }
    }

    inline bool need(const std::pair<T, T> &l0, const std::pair<T, T> &l1,
                     const std::pair<T, T> &l2) const {
        T x0 = floor_div(l1.second - l0.second, l0.first - l1.first);
        T x1 = floor_div(l2.second - l1.second, l1.first - l2.first);
        return x0 < x1;
    }

    inline T eval(const std::pair<T, T> &l, T x) const {
        return l.first * x + l.second;
    }

public:
    IntegerConvexHullTrick(Compare _c = Compare()) : comp(_c), lines() {}

    // \lambda x. ax + b
    void add(T a, T b) {
        if (!lines.empty()) {
            assert(!comp(lines.back().first, a));
            if (lines.back().first == a) {
                if (comp(b, lines.back().second)) {
                    lines.pop_back();
                } else {
                    return;
                }
            }
        }
        std::pair<T, T> l(a, b);
        while (lines.size() >= 2 &&
               !need(lines[lines.size() - 2], lines.back(), l)) {
            lines.pop_back();
        }
        lines.emplace_back(std::move(l));
    }

    T getmin(T x) const {
        assert(!lines.empty());
        int ok = 0;
        int ng = lines.size();
        while (ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if (comp(eval(lines[mid], x), eval(lines[mid - 1], x))) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return eval(lines[ok], x);
    }

    const std::vector<std::pair<T, T>> &ref_lines() const { return lines; }

    friend IntegerConvexHullTrick<T> merge_two_chts(
        const IntegerConvexHullTrick<T> &cht0,
        const IntegerConvexHullTrick<T> &cht1) {
        Compare comp;
        IntegerConvexHullTrick<T> ret;
        auto it0 = cht0.lines.begin();
        auto it1 = cht1.lines.begin();
        while (it0 != cht0.lines.end() || it1 != cht1.lines.end()) {
            if (it1 == cht1.lines.end() ||
                (it0 != cht0.lines.end() && !comp(it0->first, it1->first))) {
                ret.add(it0->first, it0->second);
                ++it0;
            } else {
                ret.add(it1->first, it1->second);
                ++it1;
            }
        }
        return ret;
    }
};
