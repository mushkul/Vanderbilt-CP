#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

int n, q, parent[MAXN][LOG];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    
    parent[1][0] = 0;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i][0];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = LOG - 1; j >= 0; j--) {
            if (k & (1 << j)) {
                x = parent[x][j];
            }
        }

        cout << (x == 0 ? -1 : x) << '\n';
    }

    return 0;
}