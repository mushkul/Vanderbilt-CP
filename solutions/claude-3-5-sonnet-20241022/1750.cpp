#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
const int MAXK = 31;

int up[MAXN][MAXK];
int n,q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> up[i][0];
    }
    
    for(int j = 1; j < MAXK; j++) {
        for(int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    
    while(q--) {
        int x, k;
        cin >> x >> k;
        
        for(int j = 0; j < MAXK; j++) {
            if(k & (1 << j)) {
                x = up[x][j];
            }
        }
        
        cout << x << "\n";
    }
    
    return 0;
}