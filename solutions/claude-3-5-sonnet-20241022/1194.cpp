#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int parent[MAXN][MAXN];
int n, m;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dir[] = {'D', 'R', 'U', 'L'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

bool isBoundary(int x, int y) {
    return x == 0 || x == n-1 || y == 0 || y == m-1;
}

int main() {
    cin >> n >> m;
    
    queue<pair<int,int>> q;
    int startX, startY;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            dist[i][j] = INT_MAX;
            if(grid[i][j] == 'M') {
                q.push({i,j});
                dist[i][j] = 0;
            }
            if(grid[i][j] == 'A') {
                startX = i;
                startY = j;
            }
        }
    }
    
    // BFS for monsters
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(isValid(newX, newY) && dist[newX][newY] == INT_MAX) {
                dist[newX][newY] = dist[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }
    
    // BFS for player
    queue<pair<int,int>> q2;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    q2.push({startX, startY});
    vis[startX][startY] = true;
    
    if(isBoundary(startX, startY)) {
        cout << "YES\n0";
        return 0;
    }
    
    bool possible = false;
    int endX, endY;
    
    while(!q2.empty() && !possible) {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(!isValid(newX, newY)) continue;
            if(vis[newX][newY]) continue;
            
            int playerDist = abs(newX - startX) + abs(newY - startY);
            if(playerDist < dist[newX][newY] || dist[newX][newY] == INT_MAX) {
                parent[newX][newY] = i;
                vis[newX][newY] = true;
                q2.push({newX, newY});
                
                if(isBoundary(newX, newY)) {
                    possible = true;
                    endX = newX;
                    endY = newY;
                    break;
                }
            }
        }
    }
    
    if(!possible) {
        cout << "NO";
        return 0;
    }
    
    cout << "YES\n";
    
    vector<char> path;
    int currX = endX;
    int currY = endY;
    
    while(currX != startX || currY != startY) {
        int p = parent[currX][currY];
        path.push_back(dir[p]);
        currX -= dx[p];
        currY -= dy[p];
    }
    
    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";
    for(char c : path) cout << c;
    
    return 0;
}