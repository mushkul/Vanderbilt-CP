#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    int countComponents(int n) {
        unordered_set<int> roots;
        for (int i = 1; i <= n; i++) {
            roots.insert(find(i));
        }
        return roots.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<pair<int, int>> breakdowns(k);
    for (int i = 0; i < k; i++) {
        cin >> breakdowns[i].first >> breakdowns[i].second;
    }

    vector<bool> connect(m, true);
    for (const auto& breakdown : breakdowns) {
        for (int i = 0; i < m; i++) {
            if (edges[i] == breakdown || 
                (edges[i].first == breakdown.second && edges[i].second == breakdown.first)) {
                connect[i] = false;
            }
        }
    }

    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        if (connect[i]) {
            uf.unionSets(edges[i].first, edges[i].second);
        }
    }

    vector<int> componentCount;
    for (const auto& breakdown : breakdowns) {
        uf.unionSets(breakdown.first, breakdown.second);
        componentCount.push_back(uf.countComponents(n));
    }

    for (int count : componentCount) {
        cout << count << " ";
    }
    cout << "\n";

    return 0;
}