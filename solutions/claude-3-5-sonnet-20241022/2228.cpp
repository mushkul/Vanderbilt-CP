#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> dp(k + 1);
    for (int i = 1; i <= k; i++) {
        dp[i] = binpow(i, n);
        for (int j = 1; j < i; j++) {
            dp[i] = (dp[i] - (dp[j] * (long long)binpow(i - j, MOD - 2)) % MOD * 
                    (long long)ncr[i][j]) % MOD;
            if (dp[i] < 0) dp[i] += MOD;
        }
    }
    
    cout << dp[k] << '\n';
    return 0;
}