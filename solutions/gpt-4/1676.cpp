C++
#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
int parent[MAXN], sz[MAXN], numComps, maxSize;
 
int Find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}
 
void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        maxSize = max(maxSize, sz[a]);
        numComps--;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    numComps = n; maxSize = 1;
    while(m--) {
        int u, v; cin >> u >> v;
        Union(u, v);
        cout << numComps << " " << maxSize << '\n';
    }
    return 0;
}