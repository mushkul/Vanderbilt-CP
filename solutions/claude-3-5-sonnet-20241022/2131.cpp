#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
const int INF = 1e9;

int n;
int row_req[MAXN], col_req[MAXN];
int grid[MAXN][MAXN];
int ans[MAXN][MAXN];

// Edmonds Karp algorithm for max flow
int flow[MAXN*2][MAXN*2], cap[MAXN*2][MAXN*2];
int par[MAXN*2];

bool bfs(int s, int t) {
    memset(par, -1, sizeof(par));
    queue<int> q;
    q.push(s);
    par[s] = s;
    
    while(!q.empty() && par[t] == -1) {
        int u = q.front();
        q.pop();
        
        for(int v = 0; v <= t; v++) {
            if(par[v] == -1 && cap[u][v] > flow[u][v]) {
                par[v] = u;
                q.push(v);
            }
        }
    }
    
    return par[t] != -1;
}

int maxflow(int s, int t) {
    memset(flow, 0, sizeof(flow));
    int total = 0;
    
    while(bfs(s, t)) {
        int curr = INF;
        for(int v = t; v != s; v = par[v]) {
            int u = par[v];
            curr = min(curr, cap[u][v] - flow[u][v]);
        }
        for(int v = t; v != s; v = par[v]) {
            int u = par[v];
            flow[u][v] += curr;
            flow[v][u] -= curr;
        }
        total += curr;
    }
    return total;
}

vector<pair<int,int>> edges;
bool possible;
int total_sum;

void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            if(u < n) {
                ans[u][v-n] = 1;
            }
            dfs(v, vis, adj);
        }
    }
}

int main() {
    cin >> n;
    total_sum = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> row_req[i];
        total_sum += row_req[i];
    }
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> col_req[i];
        sum += col_req[i];
    }
    
    if(sum != total_sum) {
        cout << -1 << endl;
        return 0;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    int source = 2*n;
    int sink = 2*n+1;
    
    memset(cap, 0, sizeof(cap));
    
    // Add edges from source to rows
    for(int i = 0; i < n; i++) {
        cap[source][i] = row_req[i];
    }
    
    // Add edges from columns to sink
    for(int i = 0; i < n; i++) {
        cap[i+n][sink] = col_req[i];
    }
    
    // Add edges between rows and columns
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] >= 0) {
                cap[i][j+n] = 1;
                edges.push_back({i,j});
            }
        }
    }
    
    int max_flow = maxflow(source, sink);
    
    if(max_flow != total_sum) {
        cout << -1 << endl;
        return 0;
    }
    
    // Construct actual solution
    vector<vector<int>> adj(2*n);
    for(auto e : edges) {
        int u = e.first, v = e.second + n;
        if(flow[u][v] > 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    vector<bool> vis(2*n, false);
    
    // Find actual squares chosen
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj);
        }
    }
    
    // Calculate total coins
    int total_coins = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ans[i][j]) {
                total_coins += grid[i][j];
            }
        }
    }
    
    cout << total_coins << "\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (ans[i][j] ? "X" : ".");
        }
        cout << "\n";
    }
    
    return 0;
}