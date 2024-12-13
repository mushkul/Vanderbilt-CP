#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+5;
vector<int> paths[MAX_N],path;
int visited[MAX_N],first[MAX_N],last[MAX_N],loop[MAX_N],ok[MAX_N];
bool impossible=false;

void dfs(int s){
    visited[s]=1;
    first[s]=path.size();
    path.push_back(s);
    for(int i=0;i<paths[s].size();i++){
        int child=paths[s][i];
        if(!visited[child])
            dfs(child);
        else if(loop[child])
            impossible=true;
    }
    if(!ok[s])
        impossible=true;
    ok[s]=1;
    last[s]=path.size();
    path.push_back(s);
    loop[s]=1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        paths[a].push_back(b);
    }
    dfs(1);
    if(impossible || !ok[n])
        cout<<"IMPOSSIBLE"<<"\n";
    else {
        for(int i=first[1];i<=last[n];i++)
            cout<<path[i]<<" ";
        cout<<"\n";
    }
    return 0;
}