#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj1[MAXN], adj2[MAXN];
string encode1[MAXN], encode2[MAXN];

void dfs1(int u, int p) {
    vector<string> child;
    for(int v : adj1[u]) {
        if(v != p) {
            dfs1(v, u);
            child.push_back(encode1[v]); 
        }
    }
    sort(child.begin(), child.end());
    encode1[u] = "1";
    for(string s : child) encode1[u] += s;
}

void dfs2(int u, int p) {
    vector<string> child;
    for(int v : adj2[u]) {
        if(v != p) {
            dfs2(v, u);
            child.push_back(encode2[v]);
        }
    }
    sort(child.begin(), child.end());
    encode2[u] = "1";
    for(string s : child) encode2[u] += s;
}

void solve() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        adj1[i].clear();
        adj2[i].clear();
        encode1[i] = encode2[i] = "";
    }
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    
    dfs1(1, 0);
    dfs2(1, 0);
    
    if(encode1[1] == encode2[1]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}