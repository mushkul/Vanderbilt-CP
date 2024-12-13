#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            grid[i][j] = row[j] - '0';
        }
    }
    
    long long beautyCount = 0;
    
    for (int r1 = 0; r1 < n; r1++) {
        for (int r2 = r1 + 1; r2 < n; r2++) {
            int blackCount = 0;
            
            for (int c = 0; c < n; c++) {
                if (grid[r1][c] && grid[r2][c]) {
                    blackCount++;
                }
            }
            
            beautyCount += (blackCount * (blackCount - 1)) / 2;
        }
    }
    
    cout << beautyCount << endl;
    
    return 0;
}