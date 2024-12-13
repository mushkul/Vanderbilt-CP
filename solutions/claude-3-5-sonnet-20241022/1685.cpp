#include <bits/stdc++.h>
using namespace std;

const int maxN = 100001;
vector<int> adj[maxN], adjRev[maxN];
vector<bool> vis;
vector<int> order, comp;
int sccID[maxN], inDeg[maxN], outDeg[maxN];
int n, m;

void dfs1(int v) {
    vis[v] = true;
    for(int u : adj[v]) {
        if(!vis[u]) dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int id) {
    comp.push_back(v);
    sccID[v] = id;
    vis[v] = true;
    for(int u : adjRev[v]) {
        if(!vis[u]) dfs2(u, id);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjRev[b].push_back(a);
    }
    
    vis.assign(n+1, false);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs1(i);
    }
    
    vis.assign(n+1, false);
    reverse(order.begin(), order.end());
    int sccCount = 0;
    
    for(int v : order) {
        if(!vis[v]) {
            comp.clear();
            dfs2(v, sccCount);
            sccCount++;
        }
    }
    
    if(sccCount == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j : adj[i]) {
            if(sccID[i] != sccID[j]) {
                outDeg[sccID[i]]++;
                inDeg[sccID[j]]++;
            }
        }
    }
    
    int noInDeg = 0, noOutDeg = 0;
    for(int i = 0; i < sccCount; i++) {
        if(inDeg[i] == 0) noInDeg++;
        if(outDeg[i] == 0) noOutDeg++;
    }
    
    cout << max(noInDeg, noOutDeg) << endl;
    
    vector<int> sources, sinks;
    for(int i = 1; i <= n; i++) {
        if(inDeg[sccID[i]] == 0) sources.push_back(i);
        if(outDeg[sccID[i]] == 0) sinks.push_back(i);
    }
    
    if(sources.size() > sinks.size()) {
        for(int i = 0; i < sources.size(); i++) {
            cout << sources[i] << " " << sinks[i % sinks.size()] << endl;
        }
    } else {
        for(int i = 0; i < sinks.size(); i++) {
            cout << sinks[i] << " " << sources[i % sources.size()] << endl;
        }
    }
    
    return 0;
}