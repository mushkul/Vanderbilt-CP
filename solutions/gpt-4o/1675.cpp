#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long cost;
    bool operator<(Edge const& other) const {
        return cost < other.cost;
    }
};

class DSU {
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    
    int find(int a) {
        if (a != parent[a])
            parent[a] = find(parent[a]);
        return parent[a];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
            return true;
        }
        return false;
    }

private:
    vector<int> parent, rank;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_cost = 0;
    int edges_used = 0;

    for (auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            total_cost += edge.cost;
            edges_used++;
            if (edges_used == n - 1)
                break;
        }
    }

    if (edges_used == n - 1) {
        cout << total_cost << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}