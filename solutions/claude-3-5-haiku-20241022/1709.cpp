#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> row_coins(n, 0);
    vector<int> col_coins(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'o') {
                row_coins[i]++;
                col_coins[j]++;
            }
        }
    }

    vector<int> moves;

    for (int i = 0; i < n; i++) {
        while (row_coins[i] > 0) {
            int max_col = -1;
            int max_coins = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'o' && col_coins[j] > max_coins) {
                    max_col = j;
                    max_coins = col_coins[j];
                }
            }
            moves.push_back(2);
            moves.push_back(max_col + 1);
            for (int k = 0; k < n; k++) {
                if (grid[k][max_col] == 'o') {
                    grid[k][max_col] = '.';
                    row_coins[k]--;
                    col_coins[max_col]--;
                }
            }
        }
    }

    for (int j = 0; j < n; j++) {
        while (col_coins[j] > 0) {
            int max_row = -1;
            int max_coins = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 'o' && row_coins[i] > max_coins) {
                    max_row = i;
                    max_coins = row_coins[i];
                }
            }
            moves.push_back(1);
            moves.push_back(max_row + 1);
            for (int k = 0; k < n; k++) {
                if (grid[max_row][k] == 'o') {
                    grid[max_row][k] = '.';
                    row_coins[max_row]--;
                    col_coins[k]--;
                }
            }
        }
    }

    cout << moves.size() / 2 << endl;
    for (int i = 0; i < moves.size(); i += 2) {
        cout << moves[i] << " " << moves[i + 1] << endl;
    }

    return 0;
}