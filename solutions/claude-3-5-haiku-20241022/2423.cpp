#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n % 2 == 1 && m % 2 == 1) {
        cout << "NO\n";
        return;
    }
    
    vector<vector<char>> grid(n, vector<char>(m));
    char letter = 'A';
    
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            grid[i][j] = letter;
            grid[i][j+1] = letter;
            grid[i+1][j] = letter;
            letter++;
            
            if (j + 2 < m) {
                grid[i][j+2] = letter;
                grid[i+1][j+1] = letter;
                grid[i+1][j+2] = letter;
                letter++;
            }
        }
    }
    
    if (m % 2 == 1) {
        for (int i = 0; i < n; i++) {
            grid[i][m-1] = grid[i][m-2];
        }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}