#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5+10;
vector<int> g[maxN];
int sz[maxN], n;

void dfs(int v, int p = 0) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        sz[v] += sz[u];
    }
}

void solve(int v, int p = 0) {
    for (auto u : g[v]) {
        if(u != p && sz[u] > n / 2) {
            solve(u, v);
            return;
        }
    }
    cout << v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    solve(1);
    return 0;
}