#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
long long dp[501][501];
 
long long solve(string& s, int l, int r) {
    if (l > r) return 1;
    if (dp[l][r] != -1) return dp[l][r];
    
    dp[l][r] = 0;
    for (int i = l + 1; i <= r; i++) {
        if (s[i] == s[l]) {
            long long left = solve(s, l + 1, i - 1);
            long long right = solve(s, i + 1, r);
            dp[l][r] = (dp[l][r] + (left * right) % MOD) % MOD;
        }
    }
    return dp[l][r];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << solve(s, 0, s.length() - 1) << "\n";
    return 0;
}