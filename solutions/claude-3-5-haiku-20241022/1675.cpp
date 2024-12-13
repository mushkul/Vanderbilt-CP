#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unionSet(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<tuple<int, int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }
    
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n);
    long long totalCost = 0;
    int connectedEdges = 0;
    
    for(auto [cost, u, v] : edges) {
        if(uf.unionSet(u, v)) {
            totalCost += cost;
            connectedEdges++;
        }
    }
    
    if(connectedEdges != n-1) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << totalCost << '\n';
    }
    
    return 0;
}