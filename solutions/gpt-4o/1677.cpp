#include <iostream>
#include <vector>
#include <map>
using namespace std;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }
    
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;
        
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; i++) {
        cin >> connections[i].first >> connections[i].second;
    }
    
    vector<pair<int, int>> breakdowns(k);
    map<pair<int, int>, bool> isBroken;
    for (int i = 0; i < k; i++) {
        cin >> breakdowns[i].first >> breakdowns[i].second;
        isBroken[breakdowns[i]] = true;
        isBroken[{breakdowns[i].second, breakdowns[i].first}] = true;
    }
    
    DSU dsu(n);
    int components = n;

    for (const auto& [a, b] : connections) {
        if (!isBroken[{a, b}] && dsu.unite(a, b)) {
            components--;
        }
    }
    
    vector<int> results(k);
    for (int i = k - 1; i >= 0; i--) {
        results[i] = components;
        const auto& [a, b] = breakdowns[i];
        if (dsu.unite(a, b)) {
            components--;
        }
    }
    
    for (int i = 0; i < k; i++) {
        cout << results[i] << ' ';
    }
    return 0;
}