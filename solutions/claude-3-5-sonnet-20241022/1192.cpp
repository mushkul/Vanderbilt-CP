#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int i, int j) {
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='#' || visited[i][j]) return;
    
    visited[i][j] = true;
    
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int rooms = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && grid[i][j]=='.') {
                dfs(i,j);
                rooms++;
            }
        }
    }
    
    cout << rooms;
    
    return 0;
}