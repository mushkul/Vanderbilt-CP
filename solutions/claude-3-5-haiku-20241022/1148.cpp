#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
char grid[MAXN][MAXN];
int left_clear[MAXN][MAXN];
int right_clear[MAXN][MAXN];
int up_clear[MAXN][MAXN];
int down_clear[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Calculate left clear spaces
    for (int i = 0; i < n; i++) {
        left_clear[i][0] = (grid[i][0] == '.');
        for (int j = 1; j < m; j++) {
            left_clear[i][j] = (grid[i][j] == '.') ? left_clear[i][j-1] + 1 : 0;
        }
    }
    
    // Calculate right clear spaces
    for (int i = 0; i < n; i++) {
        right_clear[i][m-1] = (grid[i][m-1] == '.');
        for (int j = m-2; j >= 0; j--) {
            right_clear[i][j] = (grid[i][j] == '.') ? right_clear[i][j+1] + 1 : 0;
        }
    }
    
    // Calculate up clear spaces
    for (int j = 0; j < m; j++) {
        up_clear[0][j] = (grid[0][j] == '.');
        for (int i = 1; i < n; i++) {
            up_clear[i][j] = (grid[i][j] == '.') ? up_clear[i-1][j] + 1 : 0;
        }
    }
    
    // Calculate down clear spaces
    for (int j = 0; j < m; j++) {
        down_clear[n-1][j] = (grid[n-1][j] == '.');
        for (int i = n-2; i >= 0; i--) {
            down_clear[i][j] = (grid[i][j] == '.') ? down_clear[i+1][j] + 1 : 0;
        }
    }
    
    // Calculate maximum buildings
    vector<vector<int>> result(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.') continue;
            
            for (int h = 1; h <= n - i; h++) {
                for (int w = 1; w <= m - j; w++) {
                    if (h > down_clear[i][j] + 1) break;
                    if (w > right_clear[i][j] + 1) break;
                    
                    bool valid = true;
                    for (int r = i; r < i + h; r++) {
                        if (left_clear[r][j] < w || right_clear[r][j] < w) {
                            valid = false;
                            break;
                        }
                    }
                    
                    if (valid) {
                        result[h-1][w-1]++;
                    }
                }
            }
        }
    }
    
    // Print result
    for (auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
    
    return 0;
}