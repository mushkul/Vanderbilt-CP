#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
 
int n, q;
int t[MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN];
vector<int> cycleNodes;
int cycleLen;
 
void dfs(int v) {
    vis[v] = true;
    int u = t[v];
    if (!vis[u]) {
        dfs(u);
    } else if (vis[u]) {
        int curr = u;
        cycleLen = 1;
        cycleNodes.push_back(curr);
        while (t[curr] != u) {
            curr = t[curr];
            cycleNodes.push_back(curr);
            cycleLen++;
        }
    }
}
 
void bfs(int start) {
    queue<int> q;
    q.push(start);
    memset(dist[start], -1, sizeof(dist[start]));
    dist[start][start] = 0;
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        int u = t[v];
        if(dist[start][u] == -1) {
            dist[start][u] = dist[start][v] + 1;
            q.push(u);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cycleNodes.clear();
            cycleLen = 0;
            dfs(i);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        bfs(i);
    }
    
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
    
    return 0;
}