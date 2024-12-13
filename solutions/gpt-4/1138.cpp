#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN = 2e5 + 10;
vector<int> adj[maxN];
int par[maxN], depth[maxN], heavy[maxN], head[maxN], pos[maxN];
int value[maxN], fen[maxN], timer;

void dfs(int v){
    heavy[v] = -1;
    for(auto u : adj[v]){
        if(u != par[v]){
            par[u] = v, depth[u] = depth[v] + 1;
            dfs(u);
            if(heavy[v] == -1 || adj[u].size() > adj[heavy[v]].size())
                heavy[v] = u;
        }
    }
}
void decompose(int v, int h){
    head[v] = h, pos[v] = timer++;
    if(heavy[v] != -1)
        decompose(heavy[v], h);
    for(auto u : adj[v])
        if(u != par[v] && u != heavy[v])
            decompose(u, u);
}

int sum(int p){
    int res = 0;
    for(p++; p; p -= p & -p)
        res += fen[p];
    return res; 
}
void add(int p, int x){
    for(p++; p < maxN; p += p & -p)
        fen[p] += x;
}
int get(int v){
    int res = 0, h;
    while(v != 0){
        h = head[v];
        res += sum(pos[v]) - sum(pos[h] - 1);
        v = par[h];
    }
    return res;
}
 
main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> value[i];
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
 
    dfs(1), decompose(1, 1);

    for(int i = 1; i <= n; i++)
        add(pos[i], value[i]);
 
    while(q--){
        int tp;
        cin >> tp;
        if(tp == 1){
            int v, x;
            cin >> v >> x;
            add(pos[v], x - value[v]);
            value[v] = x;
        }
        else{
            int v;
            cin >> v;
            cout << get(v) << '\n';
        }
    }
}