#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 8;
const int dx[8] = {2, 2, 1, -1, -2, -2, 1, -1};
const int dy[8] = {1, -1, 2, 2, 1, -1, -2, -2};

bool valid(int x, int y, vector<vector<int>>& board) {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0;
}

bool knightTour(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N) return true;
    vector<pair<int, int>> candidates;
    for (int i = 0; i < 8; ++i) {
        int nextX = x + dx[i], nextY = y + dy[i];
        if (valid(nextX, nextY, board)) {
            int count = 0;
            for (int j = 0; j < 8; ++j) {
                int xx = nextX + dx[j], yy = nextY + dy[j];
                if (valid(xx, yy, board)) count++;
            }
            candidates.push_back({count, i});
        }
    }
    sort(candidates.begin(), candidates.end());
    for (auto [count, i] : candidates) {
        int nextX = x + dx[i], nextY = y + dy[i];
        board[nextX][nextY] = movei + 1;
        if (knightTour(nextX, nextY, movei + 1, board)) return true;
        board[nextX][nextY] = 0;
    }
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> board(N, vector<int>(N, 0));
    board[x - 1][y - 1] = 1;
    knightTour(x - 1, y - 1, 1, board);
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}