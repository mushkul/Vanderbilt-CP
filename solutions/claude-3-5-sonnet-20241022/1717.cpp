#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
 
int main() {
    int n;
    cin >> n;
    
    vector<long long> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;
    
    for(int i = 3; i <= n; i++) {
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % mod;
    }
    
    cout << dp[n] << endl;
    
    return 0;
}