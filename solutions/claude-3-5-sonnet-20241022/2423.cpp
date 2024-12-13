#include <bits/stdc++.h>
using namespace std;

char grid[101][101];
char letter = 'A';

bool fill(int x, int y, int n, int m) {
    if(letter > 'Z') letter = 'A';
    
    if(x+1 < n && y+1 < m) {
        // Try L shape rotated 4 ways
        if(x+1 < n && y+1 < m && grid[x][y]=='.' && grid[x+1][y]=='.' && grid[x][y+1]=='.') {
            grid[x][y] = grid[x+1][y] = grid[x][y+1] = letter++;
            return true;
        }
        if(x+1 < n && y+1 < m && grid[x][y]=='.' && grid[x+1][y]=='.' && grid[x+1][y+1]=='.') {
            grid[x][y] = grid[x+1][y] = grid[x+1][y+1] = letter++;
            return true;
        }
        if(x+1 < n && y+1 < m && grid[x][y]=='.' && grid[x][y+1]=='.' && grid[x+1][y+1]=='.') {
            grid[x][y] = grid[x][y+1] = grid[x+1][y+1] = letter++;
            return true;
        }
        if(x+1 < n && y-1 >= 0 && grid[x][y]=='.' && grid[x+1][y]=='.' && grid[x+1][y-1]=='.') {
            grid[x][y] = grid[x+1][y] = grid[x+1][y-1] = letter++;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    if((n*m) % 3 != 0) {
        cout << "NO\n";
        return;
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            grid[i][j] = '.';
        }
    }
    
    letter = 'A';
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == '.') {
                if(!fill(i,j,n,m)) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    
    cout << "YES\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}