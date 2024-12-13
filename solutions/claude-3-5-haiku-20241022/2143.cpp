#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;

bitset<MAXN> reachability[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        reachability[i][i] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        reachability[a][b] = 1;
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                reachability[i][j] |= reachability[i][k] & reachability[k][j];
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << (reachability[a][b] ? "YES" : "NO") << "\n";
    }
    
    return 0;
}