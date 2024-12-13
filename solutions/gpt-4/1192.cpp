#include<bits/stdc++.h>
using namespace std;
int n, m, cnt=0;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
vector<string> g;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i=0; i<4; i++){
        int nx=x+dx[i], ny=y+dy[i];
        if (nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && g[nx][ny]=='.'){
            dfs(nx, ny);
        }
    }
}

int main() {
    cin>>n>>m;
    g.resize(n);
    visited.resize(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) cin>>g[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && g[i][j]=='.') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}