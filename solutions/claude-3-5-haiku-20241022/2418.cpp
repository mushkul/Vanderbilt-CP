#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(int n, int m, int y1, int x1, int y2, int x2) {
    if (abs(y1 - y2) + abs(x1 - x2) == n * m - 1) {
        vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
        vector<char> path;
        grid[y1][x1] = 1;
        
        function<bool(int, int, int)> dfs = [&](int y, int x, int steps) -> bool {
            if (steps == n * m - 1) {
                if (y == y2 && x == x2) return true;
                return false;
            }
            
            vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            vector<char> dirChars = {'U', 'D', 'L', 'R'};
            
            for (int i = 0; i < 4; i++) {
                int ny = y + dirs[i].first;
                int nx = x + dirs[i].second;
                
                if (ny >= 1 && ny <= n && nx >= 1 && nx <= m && grid[ny][nx] == 0) {
                    grid[ny][nx] = 1;
                    path.push_back(dirChars[i]);
                    
                    if (dfs(ny, nx, steps + 1)) return true;
                    
                    grid[ny][nx] = 0;
                    path.pop_back();
                }
            }
            
            return false;
        };
        
        if (dfs(y1, x1, 0)) {
            cout << "YES\n";
            for (char c : path) cout << c;
            cout << "\n";
            return true;
        }
    }
    
    cout << "NO\n";
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, y1, x1, y2, x2;
        cin >> n >> m >> y1 >> x1 >> y2 >> x2;
        solve(n, m, y1, x1, y2, x2);
    }
    
    return 0;
}