#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

ll dp[MAXN][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < MAXN; i++) {
        dp[i][0] = (dp[i-1][0] * 4 + dp[i-1][1] * 1) % MOD;
        dp[i][1] = (dp[i-1][0] * 1 + dp[i-1][1] * 3) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }

    return 0;
}