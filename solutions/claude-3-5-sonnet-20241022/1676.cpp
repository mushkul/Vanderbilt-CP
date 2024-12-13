#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;
    int components, maxSize;
    
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        components = n;
        maxSize = 1;
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if(pa == pb) return;
        
        components--;
        
        if(size[pa] < size[pb]) swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
        maxSize = max(maxSize, size[pa]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
        cout << dsu.components << " " << dsu.maxSize << "\n";
    }
    
    return 0;
}