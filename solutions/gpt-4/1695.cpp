C++
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define pb push_back
#define INF 1000000000

vector<vi> AdjList;
vi dfs_num, dfs_low, S, visited; 
int dfsNumberCounter, numSCC;
vector<vector<ii>> SCC;

void tarjanSCC(int u,int p=-1,int pe=-1) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
    S.pb(u); 
    visited[u] = 1;
    for (int j=0;j<AdjList[u].size();j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == INF)
            tarjanSCC(v.first,u,j);
        if (visited[v.first]) 
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        vi toAdd;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            toAdd.pb(v);
            if (u == v) break;
        }
        if(toAdd.size() > 1 || (toAdd.size() == 1 && AdjList[u].size() > 1))
            SCC.pb(vector<ii>());
        for(int i=0;i<toAdd.size();i++) {
            int v = toAdd[i];
            for(int j=0;j<AdjList[v].size();j++) {
                ii w = AdjList[v][j];
                if(find(toAdd.begin(),toAdd.end(),w.first) == toAdd.end())
                    SCC[SCC.size()-1].push_back({v+1,w.first+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    SCC.clear(); AdjList.assign(n,vector<ii>());
    for(int i=0;i<m;i++) {
        int a,b; cin >> a >> b; a--; b--;
        AdjList[a].pb(ii(b,i)); AdjList[b].pb(ii(a,i));
    }
    dfs_num.assign(n, INF); dfs_low.assign(n, 0); visited.assign(n, 0);
    dfsNumberCounter = numSCC = 0;
    for(int i=0;i<n;i++)
        if(dfs_num[i] == INF)
            tarjanSCC(i);
    vector<ii> ans;
    for(int i=0;i<SCC.size();i++)
        if(SCC[i].size() > ans.size())
            ans = SCC[i];
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
}