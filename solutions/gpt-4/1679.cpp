#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;
bool impossible = false;

void topoSort(int v, int p = -1) {
    visited[v] = true;
    for (int u : adj[v]) {
        if(!visited[u]) topoSort(u, v);
        else if (result.empty() || u != result.back()) impossible = true;
    }
    result.push_back(v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1);

    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i)
        if(!visited[i]) topoSort(i);

    if(impossible) cout << "IMPOSSIBLE";
    else for(int i = n-1; i>=0; --i) cout << result[i] << " ";

}