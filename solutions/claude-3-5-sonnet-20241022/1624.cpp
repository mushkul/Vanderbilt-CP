#include <bits/stdc++.h>
using namespace std;

char board[8][8];
int ans = 0;
bool col[8], diag1[15], diag2[15];

void solve(int row) {
    if (row == 8) {
        ans++;
        return;
    }
    
    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '*') continue;
        if (!col[c] && !diag1[row+c] && !diag2[row-c+7]) {
            col[c] = diag1[row+c] = diag2[row-c+7] = 1;
            solve(row+1);
            col[c] = diag1[row+c] = diag2[row-c+7] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) 
            cin >> board[i][j];
            
    solve(0);
    cout << ans;
    return 0;
}