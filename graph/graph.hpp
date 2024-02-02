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
template<>
struct Edge<void> {
    int from, to, id;
    Edge<void> rev() const {
        return Edge<void>{to, from, id};
    }
};
template <typename T>
void debug(const Edge<T> &e) {
    std::cerr << e.from << " -> " << e.to << " id = " << e.id;
    if constexpr (!std::is_same_v<T, void>) {
        std::cerr << " weight = ";
        debug(e.weight);
    }
}
template <typename T = void, bool DIR = false>
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
    template <std::nullptr_t P = nullptr>
    auto add_edge(int from, int to) -> std::enable_if_t<std::is_same_v<T, void> && P == nullptr> {
        assert(0 <= from && from < n && 0 <= to && to < n);
        edges.emplace_back(E{from, to, m++});
    }
    template <std::nullptr_t P = nullptr>
    auto add_edge(int from, int to, auto weight) -> std::enable_if_t<!std::is_same_v<T, void> && P == nullptr> {
        assert(0 <= from && from < n && 0 <= to && to < n);
        edges.emplace_back(E{from, to, m++, weight});
    }
    void add_edge(E e) {
        assert(0 <= e.from && e.from < n && 0 <= e.to && e.to < n);
        edges.emplace_back(e);
        ++m;
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