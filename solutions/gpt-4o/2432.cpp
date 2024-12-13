#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    vector<int> b_copy = b; // Copy of b to track column counts
    
    for (int i = 0; i < n; ++i) {
        int count = a[i];
        for (int j = 0; j < n && count > 0; ++j) {
            if (b_copy[j] > 0) {
                grid[i][j] = 'X';
                --b_copy[j];
                --count;
            }
        }
        if (count > 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int j = 0; j < n; ++j) {
        if (b_copy[j] != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}