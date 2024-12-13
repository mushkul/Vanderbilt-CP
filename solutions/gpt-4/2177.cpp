#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
 
const int arr = 2e5+10;
vector<int> gr[arr];
int vis[arr];
vector<int> ord;
 
void dfs(int cur){
    vis[cur] = 1;
    for(auto x:gr[cur]){
        if(!vis[x]) dfs(x);
    }
    ord.pb(cur);
}
 
void solve(){
    int n,m;
    cin>>n>>m;
 
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
    }
 
    for(int i=1; i<=n; i++){
        if(!vis[i])
        dfs(i);
    }
 
    for(int i=1; i<ord.size(); i++){
        bool found = false;
        for(auto x:gr[ord[i-1]]){
            if(x==ord[i]){
                found = true;
            }
        }
        if(!found){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
 
    reverse(ord.begin(),ord.end());
 
    for(int i=0; i<n; i++){
        cout<<ord[i]<<" ";
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int test_cases=1;
    while(test_cases--){
        solve();
    }
}