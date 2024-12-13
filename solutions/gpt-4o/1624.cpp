#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countWays(int row, int columns, int diag1, int diag2, vector<string>& board) {
    if (row == 8) return 1;
    int count = 0;
    for (int col = 0; col < 8; ++col) {
        if (board[row][col] == '.' && !(columns & (1 << col)) && !(diag1 & (1 << (row + col))) && !(diag2 & (1 << (row - col + 7)))) {
            count += countWays(row + 1, columns | (1 << col), diag1 | (1 << (row + col)), diag2 | (1 << (row - col + 7)), board);
        }
    }
    return count;
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }
    cout << countWays(0, 0, 0, 0, board) << endl;
    return 0;
}