#include<bits/stdc++.h>
using namespace std;

int n, m, cnt, t;
vector<int> g[100002], art_point;
int visited[100002], in[100002], low[100002];
set<int> res;

void dfs(int u, int p = -1) {
    visited[u] = 1;
    in[u] = low[u] = ++t;
    for(int v: g[u]) {
      if(v == p) continue;
      if(visited[v]) {
        low[u] = min(low[u], in[v]);
      } else {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if(low[v] >= in[u] && p!=-1) {
          art_point.push_back(u);
          res.insert(u);
        }
        ++cnt;
      }
    }
    if(p == -1 && cnt > 1) {
      art_point.push_back(u);
      res.insert(u);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(!visited[i]) {
           t = 0;
           cnt = 0;
           dfs(i);
        }
    cout << res.size() << "\n";
    for(int i: res) cout << i << " ";
    cout << "\n";
}