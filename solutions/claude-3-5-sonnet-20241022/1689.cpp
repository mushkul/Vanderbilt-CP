#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<vector<int>> board(N, vector<int>(N));
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N && board[x][y] == 0;
}

bool solve(int x, int y, int move) {
    if (move == N * N + 1) return true;
    
    for (int i = 0; i < 8; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if (isSafe(next_x, next_y)) {
            board[next_x][next_y] = move;
            if (solve(next_x, next_y, move + 1)) 
                return true;
            board[next_x][next_y] = 0;
        }
    }
    
    return false;
}

int main() {
    int start_x, start_y;
    cin >> start_x >> start_y;
    start_x--; start_y--;
    
    board[start_x][start_y] = 1;
    
    if (solve(start_x, start_y, 2)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}