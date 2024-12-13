#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
vector<vector<long long>> dp;
 
long long solve(int mask, int last, int n, vector<int>& used) {
    if (mask == (1 << n) - 1) return 1;
    
    if (dp[mask][last] != -1) return dp[mask][last];
    
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!(mask & (1 << (i-1))) && (abs(i - last) != 1 || last == 0)) {
            ans = (ans + solve(mask | (1 << (i-1)), i, n, used)) % MOD;
        }
    }
    
    return dp[mask][last] = ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    dp.assign(1 << n, vector<long long>(n + 1, -1));
    vector<int> used(n + 1);
    
    cout << solve(0, 0, n, used) << "\n";
    
    return 0;
}