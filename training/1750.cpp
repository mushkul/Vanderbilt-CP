#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
const int LOG = 30;
int n, q;
int t[MAX_N + 1];
int dp[MAX_N + 1][LOG + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        dp[i][0] = t[i];
    }

    for (int j = 1; j <= LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j <= LOG; ++j) {
            if (k & (1 << j)) {
                x = dp[x][j];
            }
        }
        cout << x << '\n';
    }

    return 0;
}