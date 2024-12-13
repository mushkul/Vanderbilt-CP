#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int from, to;
    ll cost;
};

struct DSU {
    vector<int> parent;
    vector<int> size;
    
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;
        if(size[pa] < size[pb]) swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
    
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    
    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    
    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.cost < b.cost;
    });
    
    DSU dsu(n);
    ll total = 0;
    int taken = 0;
    
    for(auto e : edges) {
        if(!dsu.same(e.from, e.to)) {
            dsu.unite(e.from, e.to);
            total += e.cost;
            taken++;
        }
    }
    
    if(taken == n-1 && dsu.getSize(1) == n) {
        cout << total << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}