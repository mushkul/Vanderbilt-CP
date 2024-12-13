#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> row_constraints(n);
    vector<int> col_constraints(n);
    
    for (int i = 0; i < n; i++) {
        cin >> row_constraints[i];
    }
    
    for (int j = 0; j < n; j++) {
        cin >> col_constraints[j];
    }
    
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<int> row_count(n, 0);
    vector<int> col_count(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (row_count[i] < row_constraints[i] && col_count[j] < col_constraints[j]) {
                grid[i][j] = 'X';
                row_count[i]++;
                col_count[j]++;
            }
        }
    }
    
    bool valid = true;
    for (int i = 0; i < n; i++) {
        if (row_count[i] != row_constraints[i] || col_count[i] != col_constraints[i]) {
            valid = false;
            break;
        }
    }
    
    if (!valid) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}