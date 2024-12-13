#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> left(n, vector<int>(m, 0));
    vector<vector<int>> right(n, vector<int>(m, 0));
    vector<vector<int>> height(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                height[i][j] = (i > 0 ? height[i-1][j] + 1 : 1);
                left[i][j] = (j > 0 && grid[i][j-1] == '.' ? left[i][j-1] : j);
                right[i][j] = (j < m-1 && grid[i][j+1] == '.' ? right[i][j+1] : j);
            }
        }
    }
    
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                int h = height[i][j];
                int l = left[i][j];
                int r = right[i][j];
                int area = h * (r - l + 1);
                maxArea = max(maxArea, area);
            }
        }
    }
    
    cout << maxArea << endl;
    
    return 0;
}