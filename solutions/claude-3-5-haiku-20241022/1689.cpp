#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int board[9][9];
bool visited[9][9];

bool solve(int x, int y, int step) {
    board[x][y] = step;
    visited[x][y] = true;

    if (step == 64) return true;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && !visited[nx][ny]) {
            if (solve(nx, ny, step + 1)) return true;
        }
    }

    visited[x][y] = false;
    board[x][y] = 0;
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;

    solve(x, y, 1);

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}