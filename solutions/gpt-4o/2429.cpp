#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int n;
vector<vector<char>> grid;
vector<bool> rowA, colA, rowB, colB;

bool isValid() {
    for (int i = 0; i < n; ++i) {
        if (rowA[i] && grid[i][i] == 'B') return false;
        if (rowB[i] && grid[i][i] == 'A') return false;
    }
    return true;
}

int solve(int index) {
    if (index == n) return isValid();
    int row = index / n, col = index % n;
    if (grid[row][col] != '.') {
        return solve(index + 1);
    }

    int ways = 0;
    if (!rowA[row] && !colA[col]) {
        grid[row][col] = 'A';
        rowA[row] = colA[col] = true;
        ways = (ways + solve(index + 1)) % MOD;
        rowA[row] = colA[col] = false;
    }

    if (!rowB[row] && !colB[col]) {
        grid[row][col] = 'B';
        rowB[row] = colB[col] = true;
        ways = (ways + solve(index + 1)) % MOD;
        rowB[row] = colB[col] = false;
    }

    grid[row][col] = '.';
    return ways;
}

int main() {
    cin >> n;
    grid.resize(n, vector<char>(n));
    rowA.resize(n, false);
    colA.resize(n, false);
    rowB.resize(n, false);
    colB.resize(n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') rowA[i] = colA[j] = true;
            else if (grid[i][j] == 'B') rowB[i] = colB[j] = true;
        }
    }
    
    cout << solve(0) << endl;
    return 0;
}