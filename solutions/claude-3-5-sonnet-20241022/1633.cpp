#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    const int mod = 1e9 + 7;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }
    
    cout << dp[n] << endl;
    return 0;
}