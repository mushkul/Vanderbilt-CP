#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int n, m;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || 
        grid[x][y] == '#' || visited[x][y]) {
        return;
    }
    
    visited[x][y] = true;
    
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                rooms++;
            }
        }
    }
    
    cout << rooms << "\n";
    
    return 0;
}