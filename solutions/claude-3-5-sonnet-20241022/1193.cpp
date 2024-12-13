#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
pair<int,int> prev_move[MAXN][MAXN];
int di[] = {-1, 1, 0, 0}; 
int dj[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !vis[i][j];
}

int main() {
    cin >> n >> m;
    pair<int,int> start, end;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') start = {i,j};
            if(grid[i][j] == 'B') end = {i,j};
        }
    }
    
    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    
    while(!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int ni = curr.first + di[k];
            int nj = curr.second + dj[k];
            
            if(valid(ni, nj)) {
                vis[ni][nj] = true;
                prev_move[ni][nj] = curr;
                q.push({ni,nj});
            }
        }
    }
    
    if(!vis[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    string path = "";
    pair<int,int> curr = end;
    
    while(curr != start) {
        pair<int,int> p = prev_move[curr.first][curr.second];
        
        if(curr.first == p.first + 1) path += 'D';
        if(curr.first == p.first - 1) path += 'U';
        if(curr.second == p.second + 1) path += 'R';
        if(curr.second == p.second - 1) path += 'L';
        
        curr = p;
    }
    
    reverse(path.begin(), path.end());
    cout << path.length() << "\n" << path << "\n";
    
    return 0;
}