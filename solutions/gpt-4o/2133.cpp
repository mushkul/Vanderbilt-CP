#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n+1), rank(n+1, 0), components(n) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV) return false;

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        components--;
        return true;
    }

    bool disconnectSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) return false;
        components++;
        return true;
    }

    int count() const {
        return components;
    }

private:
    vector<int> parent, rank;
    int components;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    UnionFind uf(n);
    unordered_map<int, unordered_map<int, bool>> hasEdge;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unionSets(a, b);
        hasEdge[a][b] = hasEdge[b][a] = true;
    }

    vector<pair<int, pair<int, int>>> events(k);
    for (int i = 0; i < k; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        events[i] = {t, {a, b}};
    }

    vector<int> results;
    results.push_back(uf.count());

    for (const auto& event : events) {
        int t = event.first;
        int a = event.second.first;
        int b = event.second.second;
        if (t == 1) {
            if (!hasEdge[a][b]) {
                uf.unionSets(a, b);
                hasEdge[a][b] = hasEdge[b][a] = true;
            }
        } else if (t == 2) {
            if (hasEdge[a][b]) {
                uf.disconnectSets(a, b);
                hasEdge[a][b] = hasEdge[b][a] = false;
            }
        }
        results.push_back(uf.count());
    }

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}