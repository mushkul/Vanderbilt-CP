#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

long long derangement(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    
    long long dp[n+1];
    dp[0] = 1;
    dp[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % MOD;
    }
    
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << derangement(n) << endl;
    return 0;
}