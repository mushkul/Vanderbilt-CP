#include<bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
int sz[200005];

void dfs(int node){
    sz[node] = 1;
    for(auto it: graph[node]){
        dfs(it);
        sz[node] += sz[it];
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x; 
        cin >> x;
        graph[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << sz[i] - 1 << " ";
    }
    return 0;
}