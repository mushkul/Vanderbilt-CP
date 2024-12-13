#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
vector<int> adj[MAXN];
int dist[MAXN], cycle[MAXN], vis[MAXN], cycleNo;

void dfs(int u) {
    vis[u] = 1;
    for(int v : adj[u]) {
        if(vis[v] == 0) {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
        else if(vis[v] == 1) {
            cycleNo = dist[u] - dist[v] + 1;
            cycle[v] = cycleNo;
        }
    }
    vis[u] = 2;
}

void solve() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dist[i] = 0;
            dfs(i);
        }
    }
    
    memset(vis, 0, sizeof(vis));
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int curr = i;
            vector<int> path;
            while(!vis[curr]) {
                path.push_back(curr);
                vis[curr] = 1;
                curr = adj[curr][0];
            }
            
            int cycleStart = curr;
            bool inCycle = false;
            int cycleLength = cycle[cycleStart];
            if(cycleLength == 0) cycleLength = 1;
            
            for(int j = path.size()-1; j >= 0; j--) {
                if(path[j] == cycleStart) inCycle = true;
                if(inCycle) ans[path[j]] = cycleLength;
                else ans[path[j]] = cycleLength + path.size()-j;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}