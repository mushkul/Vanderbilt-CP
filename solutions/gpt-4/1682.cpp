#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> adj[N], radj[N], order, component;
int vis[N];
void dfs1(int node){
    vis[node] = 1;
    for(int child : adj[node]){
        if(!vis[child]) dfs1(child);
    }
    order.push_back(node);
}
void dfs2(int node){
    vis[node] = 1;
    component.push_back(node);
    for(int child : radj[node]){
        if(!vis[child]) dfs2(child);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    dfs1(1);
    memset(vis, 0, sizeof(vis));
    for(int i=n-1; i>=0; i--){
        if(!vis[order[i]]){
            dfs2(order[i]);
            if(component.size()!=n){
                cout << "NO\n" << component[0] << ' ' << order[i+1] << '\n';
                return 0;
            }
            component.clear();
        }
    }
    cout << "YES\n";
    return 0;
}