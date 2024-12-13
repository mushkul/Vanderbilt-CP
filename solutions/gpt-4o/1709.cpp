#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    
    vector<bool> rowHasCoin(n, false), colHasCoin(n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'o') {
                rowHasCoin[i] = true;
                colHasCoin[j] = true;
            }
        }
    }

    vector<pair<int, int>> moves;
    for (int i = 0; i < n; ++i) {
        if (rowHasCoin[i]) {
            moves.push_back({1, i + 1});
        }
    }
    for (int j = 0; j < n; ++j) {
        if (colHasCoin[j]) {
            moves.push_back({2, j + 1});
        }
    }
    
    cout << moves.size() << endl;
    for (auto &move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}