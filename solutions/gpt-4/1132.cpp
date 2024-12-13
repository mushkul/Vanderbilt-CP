#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int n, mx1[MAXN], mx2[MAXN], h[MAXN];
vector<int> g[MAXN];

void dfs(int u, int p){
    for(auto v : g[u]){
        if(v==p) continue;
        h[v] = h[u] + 1;
        dfs(v, u);
        if(mx1[v] + 1 > mx1[u]){
            mx2[u] = mx1[u];
            mx1[u] = mx1[v] + 1;
          }
        else if(mx1[v] + 1 > mx2[u]){
            mx2[u] = mx1[v] + 1;
        }
    }
}

void dfs2(int u, int p){
    for(auto v : g[u]){
        if(v==p) continue;
        int up = mx1[u];
        if(up == mx1[v] + 1) up = mx2[u];
        mx1[v] = max(mx1[v], up + 1);
        dfs2(v, u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++){
        cout << mx1[i] << " ";
    }
}