#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<ll> prefixSum(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;
            ll currentSum = prefixSum[j + 1] - prefixSum[i];
            
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + currentSum);
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    return 0;
}