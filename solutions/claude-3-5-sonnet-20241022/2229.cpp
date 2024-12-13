#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 505;
long long dp[MAXN][MAXN*MAXN/2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    dp[1][0] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int pos = 0; pos < i; pos++) {
                if(j >= pos) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-pos]) % MOD;
                }
            }
        }
    }
    
    cout << dp[n][k] << '\n';
    
    return 0;
}