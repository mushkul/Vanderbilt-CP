#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int n,m;
char g[1001][1001];
ll ans[1001][1001];
int nextTree[1001][1001];
 
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    // Find next tree position to right for each cell
    for(int i = 0; i < n; i++) {
        nextTree[i][m] = m;
        for(int j = m-1; j >= 0; j--) {
            if(g[i][j] == '*')
                nextTree[i][j] = j;
            else
                nextTree[i][j] = nextTree[i][j+1];
        }
    }
    
    // Find number of ways for each cell as top-left corner
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '*') {
                ans[i][j] = 0;
                continue;
            }
            
            int minWidth = m;
            for(int height = 1; i + height - 1 < n; height++) {
                int row = i + height - 1;
                minWidth = min(minWidth, nextTree[row][j] - j);
                if(minWidth == 0) break;
                ans[i][j] += minWidth;
            }
        }
    }
    
    // Print answer
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j];
            if(j < m-1) cout << " ";
        }
        cout << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}