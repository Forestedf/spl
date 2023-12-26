#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

template <typename T>
class GRangeTree {
    std::vector<T> xs;
    std::vector<std::pair<T, int>> arr;
    std::vector<int> rngs;

    static bool compare_by_first(const std::pair<T, int> &p0,
                                 const std::pair<T, int> &p1) {
        return p0.first < p1.first;
    }

public:
    GRangeTree(const std::vector<std::pair<T, T>> &pts) : xs(), arr(), rngs() {
        xs.reserve(pts.size());
        for (const auto &[x, _y] : pts) {
            xs.push_back(x);
        }
        std::sort(xs.begin(), xs.end());
        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
        int xs_sz = (int)xs.size();
        std::vector<std::vector<std::pair<T, int>>> nodes(2 * xs_sz);
        for (int i = 0; i < (int)pts.size(); ++i) {
            int xi =
                (int)(std::lower_bound(xs.begin(), xs.end(), pts[i].first) -
                      xs.begin());
            nodes[xs_sz + xi].emplace_back(pts[i].second, i);
        }
        for (int i = xs_sz; i < 2 * xs_sz; ++i) {
            std::sort(nodes[i].begin(), nodes[i].end(), compare_by_first);
        }
        for (int i = xs_sz - 1; i > 0; --i) {
            nodes[i].reserve(nodes[2 * i].size() + nodes[2 * i + 1].size());
            std::merge(nodes[2 * i].begin(), nodes[2 * i].end(),
                       nodes[2 * i + 1].begin(), nodes[2 * i + 1].end(),
                       std::back_inserter(nodes[i]), compare_by_first);
        }
        int tot = 0;
        for (int i = 1; i < 2 * xs_sz; ++i) {
            tot += (int)nodes[i].size();
        }
        arr.reserve(tot);
        for (int i = 1; i < 2 * xs_sz; ++i) {
            for (auto ele : nodes[i]) {
                arr.emplace_back(ele);
            }
        }
        rngs.resize(2 * xs_sz, 0);
        for (int i = 1; i < 2 * xs_sz; ++i) {
            rngs[i] = rngs[i - 1] + (int)nodes[i].size();
        }
    }

    int size() const { return (int)arr.size(); }
    int operator[](int i) const { return arr[i].second; }

    // [xl, xr), [yl, yr)
    std::vector<std::pair<int, int>> rectangle(T xl, T xr, T yl, T yr) const {
        int xli =
            (int)(std::lower_bound(xs.begin(), xs.end(), xl) - xs.begin());
        int xri =
            (int)(std::lower_bound(xs.begin(), xs.end(), xr) - xs.begin());
        std::vector<std::pair<int, int>> ret;
        xli += (int)xs.size();
        xri += (int)xs.size();
        while (xli < xri) {
            if (xli % 2 == 1) {
                int l = rngs[xli - 1];
                int r = rngs[xli];
                ret.emplace_back(
                    (int)(std::lower_bound(arr.begin() + l, arr.begin() + r,
                                           std::pair<T, int>(yl, 0),
                                           compare_by_first) -
                          arr.begin()),
                    (int)(std::lower_bound(arr.begin() + l, arr.begin() + r,
                                           std::pair<T, int>(yr, 0),
                                           compare_by_first) -
                          arr.begin()));
                ++xli;
            }
            if (xri % 2 == 1) {
                --xri;
                int l = rngs[xri - 1];
                int r = rngs[xri];
                ret.emplace_back(
                    (int)(std::lower_bound(arr.begin() + l, arr.begin() + r,
                                           std::pair<T, int>(yl, 0),
                                           compare_by_first) -
                          arr.begin()),
                    (int)(std::lower_bound(arr.begin() + l, arr.begin() + r,
                                           std::pair<T, int>(yr, 0),
                                           compare_by_first) -
                          arr.begin()));
            }
            xli /= 2;
            xri /= 2;
        }
        return ret;
    }
};