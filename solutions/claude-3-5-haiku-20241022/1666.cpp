#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        
        if (rank[px] < rank[py])
            swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py])
            rank[px]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    int components = n;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (dsu.unite(a, b)) {
            components--;
        }
    }
    
    vector<pair<int, int>> new_roads;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dsu.unite(i, j)) {
                new_roads.push_back({i, j});
                components--;
                if (components == 1) break;
            }
        }
        if (components == 1) break;
    }
    
    cout << new_roads.size() << "\n";
    for (auto [a, b] : new_roads) {
        cout << a << " " << b << "\n";
    }
    
    return 0;
}