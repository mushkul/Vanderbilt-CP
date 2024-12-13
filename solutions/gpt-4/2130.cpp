#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<vector<int>> adj, radj;
vector<int> indeg, nxt, order, vis, path, ans;
vector<vector<int>> paths;
int n, m, k, odr;

int dfs(int cur) {
    ++odr;
    nxt[cur] = cur;
    for(auto anc: radj[cur]) nxt[cur] = max(nxt[cur], dfs(anc));
    vis[cur] = 1;
    return nxt[cur];
}

void dfs1(int cur) {
    order[cur] = odr--;
    vis[cur] = 1;
    for(auto ch: adj[cur]) {
        if(!vis[ch]) {
            path[ch] = cur;
            dfs1(ch);
        }
    }
}

void get_path(int a, int b) {
    while(b != a) {
        ans[b] = order[b];
        b = path[b];
    }
    ans[a] = order[a];
}

int main() {
    int a, b;
    cin >> n >> m >> k;
    adj.resize(n+1), radj.resize(n+1), indeg.resize(n+1, 0), nxt.resize(n+1, 0), vis.resize(n+1, 0), path.resize(n+1, 0);
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
        ++indeg[b];
    }
    for(int v=1; v<=n; v++) adj[0].pb(v), ++indeg[v];
    radj[1].pb(0);
    int source = 0;

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        dfs(i);
    }

    for(int i=0; i<=n; i++) vis[i] = 0;
    order.resize(n+1), ans.resize(n+1); odr = n+1;
    for(int i = source; i<=n; i++) {
        if(vis[i]) continue;
        dfs1(i);
    }

    for(int s=source; s<=n; s++) {
        if(indeg[s]==0) {
            paths.pb({s});
            for(int t=s; !paths.back().empty(); t=nxt[t]) {
                paths.back().pb(nxt[t]);
                --indeg[nxt[t]];
                if(nxt[t] != t) nxt[t] = nxt[nxt[t]];
            }
        }
    }

    map<pair<int,int>,vector<int>> mp;
    for(auto path: paths) {
        if(path[0]==0) path.erase(path.begin()), mp[make_pair(0, path[0])].pb(1);
        else mp[make_pair(path[0], path.back())].pb(1);
        for(int i=0; i<(int)path.size()-1; i++)
            ans[path[i]] = -1, get_path(path[i], path[i+1]), mp[make_pair(path[i], path[i+1])].pb(1);
    }

    odr=n+1;
    if(k < mp[make_pair(0, n)].size()) cout << -1;
    else if(k < mp[make_pair(0, 1)].size()+mp[make_pair(n-1, n)].size()) cout << 2*k;
    else {
        cout << mp[make_pair(0, n)].size() + mp[make_pair(n-1, n)].size() + 2*(k-mp[make_pair(n-1, n)].size());
        for(int i=1; i<=mp[make_pair(0, 1)].size()+mp[make_pair(n-1, n)].size()-k; i++) {
            cout << "\n" << 2 << "\n";
            cout << 1 << " " << n;
        }
        for(int i=1; i<=2*(k-mp[make_pair(n-1, n)].size()); i+=2) {
            cout << "\n" << 3 << "\n";
            cout << 1 << " " << n-1 << " " << n;
        }
    }
}