#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[100001],route(100001);
queue<int> q;
void bfs(int s){
    route[s] = s;
    q.push(s);
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        for(int to : adj[cur]){
            if(route[to] == 0){
                route[to] = cur;
                q.push(to);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    int a,b;
    for(int i = 0;i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    if(route[n] == 0) cout << "IMPOSSIBLE";
    else{
        vector<int> ans;
        for(int u = n;u!=1;u = route[u]) ans.push_back(u);
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        cout << ans.size() << "\n";
        for(int u : ans) cout << u << " ";
    }
    return 0;
}