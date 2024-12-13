#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXK = 60;
int n, q;
int teleport[MAXN];
int jump[MAXN][MAXK];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> teleport[i];
        jump[i][0] = teleport[i];
    }
    
    for (int k = 1; k < MAXK; k++) {
        for (int i = 1; i <= n; i++) {
            jump[i][k] = jump[jump[i][k-1]][k-1];
        }
    }
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        
        for (int bit = 0; bit < MAXK; bit++) {
            if (k & (1 << bit)) {
                x = jump[x][bit];
            }
        }
        
        cout << x << "\n";
    }
    
    return 0;
}