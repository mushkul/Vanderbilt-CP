#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 105;
const int MAXX = 5005;

int n, x;
int skills[MAXN];
int dp[MAXN][MAXN][MAXX];

int solve() {
    sort(skills, skills + n);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= x; k++) {
                if (dp[i][j][k] == 0) continue;

                // Leave current coder alone
                dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % MOD;

                // Add current coder to current team if possible
                if (j > 0) {
                    int penalty = max(skills[i] - skills[i-j+1], 0);
                    if (k + penalty <= x) {
                        dp[i+1][j+1][k+penalty] = (dp[i+1][j+1][k+penalty] + dp[i][j][k]) % MOD;
                    }
                }

                // Start a new team with current coder
                dp[i+1][1][k] = (dp[i+1][1][k] + dp[i][j][k]) % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= x; k++) {
            result = (result + dp[n][j][k]) % MOD;
        }
    }

    return result;
}

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }
    cout << solve() << endl;
    return 0;
}