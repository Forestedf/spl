#pragma once
#include <iostream>
#include <cassert>
#include <vector>
template <typename T>
struct Edge {
    using W = T;
    int from, to, id;
    W weight;
    Edge<T> rev() const {
        return Edge<T>{to, from, id, weight};
    }
};
template <typename T>
void debug(const Edge<T> &e) {
    std::cerr << e.from << " -> " << e.to << " id = " << e.id << std::cerr << " weight = ";
    debug(e.weight);
}
template <typename T = int, bool DIR = false>
class Graph {
public:
    using E = Edge<T>;
    using W = T;
    static constexpr bool DIRECTED = DIR;
    struct Adjacency {
        using Iter = typename std::vector<E>::iterator;
        Iter be, en;
        Iter begin() const { return be; }
        Iter end() const { return en; }
        int size() const { return (int)std::distance(be, en); }
        E &operator[](int idx) const { return be[idx]; }
    };
    struct ConstAdjacency {
        using Iter = typename std::vector<E>::const_iterator;
        Iter be, en;
        Iter begin() const { return be; }
        Iter end() const { return en; }
        int size() const { return (int)std::distance(be, en); }
        const E &operator[](int idx) const { return be[idx]; }
    };

private:
    int n, m;
    std::vector<E> edges, csr;
    std::vector<int> sep;
    bool built;

public:
    Graph(int n) : n(n), m(0), built(false) {}
    int v() const { return n; }
    int e() const { return m; }
    int add_vertex() {
        return n++;
    }
    void add_edge(int from, int to, W weight = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        edges.emplace_back(E{from, to, m++, weight});
    }
    void build() {
        sep.assign(n + 1, 0);
        csr.resize(DIRECTED ? m : 2 * m);
        for (const E &e : edges) {
            ++sep[e.from + 1];
            if (!DIRECTED) {
                ++sep[e.to + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            sep[i + 1] += sep[i];
        }
        std::vector<int> c = sep;
        for (const E &e : edges) {
            csr[c[e.from]++] = e;
            if (!DIRECTED) {
                csr[c[e.to]++] = e.rev();
            }
        }
        built = true;
    }
    Adjacency operator[](int v) {
        assert(built && 0 <= v && v < n);
        return Adjacency{csr.begin() + sep[v], csr.begin() + sep[v + 1]};
    }
    ConstAdjacency operator[](int v) const {
        assert(built && 0 <= v && v < n);
        return ConstAdjacency{csr.begin() + sep[v], csr.begin() + sep[v + 1]};
    }
};
