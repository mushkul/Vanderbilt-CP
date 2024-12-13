#include <iostream>
#include <vector>
using namespace std;

int queens = 0;

bool isValid(vector<string>& board, int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    
    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    
    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    
    return true;
}

void backtrack(vector<string>& board, int row) {
    if (row == 8) {
        queens++;
        return;
    }
    
    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '.' && isValid(board, row, col)) {
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    
    backtrack(board, 0);
    
    cout << queens << endl;
    
    return 0;
}