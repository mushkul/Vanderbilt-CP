#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 505;

int dp[MAXN][MAXN];
string s;

int solve(int l, int r) {
    if (l > r) return 1;
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    
    int ways = 0;
    for (int k = l + 1; k <= r; k++) {
        if (s[l] == s[k]) {
            ways = (ways + 1LL * solve(l + 1, k - 1) * solve(k + 1, r)) % MOD;
        }
    }
    
    return dp[l][r] = ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, s.length() - 1) << endl;
    
    return 0;
}