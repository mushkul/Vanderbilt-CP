#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 2e5+5;
vector<int> adj[maxN];
vector<int> dist[maxN];
vector<bool> vis;
int n, d;
vector<int> offices;
 
void dfs(int u, int p, int depth, vector<int>& distances) {
    distances[u] = depth;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u, depth+1, distances);
        }
    }
}
 
int findFarthest(int start) {
    vector<int> distances(n+1, 0);
    dfs(start, 0, 0, distances);
    int maxDist = 0, farthest = start;
    for(int i = 1; i <= n; i++) {
        if(distances[i] > maxDist) {
            maxDist = distances[i];
            farthest = i;
        }
    }
    return farthest;
}
 
void findOffices(int u, int p, int depth) {
    vis[u] = true;
    bool ok = true;
    
    for(int office : offices) {
        vector<int>& distances = dist[office];
        if(distances[u] < d) {
            ok = false;
            break;
        }
    }
    
    if(ok) {
        offices.push_back(u);
        vector<int>& distances = dist[u];
        dfs(u, 0, 0, distances);
    }
    
    for(int v : adj[u]) {
        if(v != p && !vis[v]) {
            findOffices(v, u, depth+1);
        }
    }
}
 
int main() {
    cin >> n >> d;
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vis.resize(n+1);
    for(int i = 1; i <= n; i++) {
        dist[i].resize(n+1);
    }
    
    int start = findFarthest(1);
    int end = findFarthest(start);
    
    findOffices(start, 0, 0);
    
    cout << offices.size() << "\n";
    for(int x : offices) {
        cout << x << " ";
    }
    
    return 0;
}