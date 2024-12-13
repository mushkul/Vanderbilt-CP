#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i <= n; i++) 
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    int unionSet(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a != b) {
            if (size[a] < size[b]) 
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
        
        return size[a];
    }
    
    int getComponents(int n) {
        unordered_set<int> roots;
        for (int i = 1; i <= n; i++) 
            roots.insert(find(i));
        return roots.size();
    }
    
    int getMaxSize(int n) {
        int maxSize = 0;
        for (int i = 1; i <= n; i++) 
            maxSize = max(maxSize, size[find(i)]);
        return maxSize;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unionSet(a, b);
        int components = dsu.getComponents(n);
        int maxSize = dsu.getMaxSize(n);
        cout << components << " " << maxSize << "\n";
    }
    
    return 0;
}