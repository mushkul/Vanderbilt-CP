#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5+7;
vector<int> g[maxn], leaf;
bool vis[maxn];

void dfs(int u, int pre){
    int child = 0;
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if (vis[v]||v==pre) continue;
        dfs(v,u);
        child++;  
    }
    if(child == 0) leaf.push_back(u);
    vis[u] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin>>n;
    for(int i=1; i<n; i++) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    cout<<leaf.size()-1<<"\n";
    for(int i=0; i<leaf.size()-1; i++) {
        cout<<leaf[i]<<" "<<leaf[i+1]<<"\n";
    }
    return 0;
}