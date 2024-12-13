#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;
vector<int> adj[MAX];
bool vis[MAX];
vector<int> city;
int n, m;

void dfs(int node) {
    vis[node] = true;
    for(int e : adj[node]) {
        if(!vis[e]) dfs(e);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0, start = 1;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if (cnt) city.push_back(i);
            dfs(i);
            cnt++;
        }
    }

    cout <<cnt-1<<"\n";
    for (int i =0; i<city.size(); i++)
        cout <<start<<" "<<city[i]<<"\n";
    return 0;
}