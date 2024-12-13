#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
const int maxN = 501;
long long dp[maxN][maxN*maxN/2+1];
 
int main() {
    int n;
    cin >> n;
    
    long long target = (long long)n*(n+1)/2;
    if(target%2) {
        cout << 0;
        return 0;
    }
    target /= 2;
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int sum = 0; sum <= target; sum++) {
            dp[i][sum] = dp[i-1][sum];
            if(sum >= i) {
                dp[i][sum] = (dp[i][sum] + dp[i-1][sum-i]) % mod;
            }
        }
    }
    
    cout << dp[n][target] * ((mod+1)/2) % mod;
    return 0;
}