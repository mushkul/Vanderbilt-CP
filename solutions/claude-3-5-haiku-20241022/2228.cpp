#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    
    for (int j = 1; j <= k; j++) {
        dp[1][j] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 1; x <= k; x++) {
                if (j != x) {
                    dp[i][j] = (dp[i][j] + dp[i-1][x]) % MOD;
                }
            }
        }
    }
    
    long long total = 0;
    for (int j = 1; j <= k; j++) {
        total = (total + dp[n][j]) % MOD;
    }
    
    vector<long long> factorial(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
    
    long long ways = factorial[n];
    for (int j = 1; j <= k; j++) {
        ways = (ways * k) % MOD;
    }
    
    ways = (ways - total + MOD) % MOD;
    
    cout << ways << endl;
    
    return 0;
}