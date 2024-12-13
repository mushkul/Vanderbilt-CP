#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
    vector<vector<ll>> sum(n, vector<ll>(n));
    vector<vector<int>> opt(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        dp[i][i] = 0;
        sum[i][i] = arr[i];
        opt[i][i] = i;
        for(int j = i+1; j < n; j++) {
            sum[i][j] = sum[i][j-1] + arr[j];
        }
    }
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            int optLeft = opt[i][j-1];
            int optRight = opt[i+1][j];
            
            for(int k = optLeft; k <= optRight; k++) {
                ll val = 0;
                if(k > i) val += dp[i][k-1];
                if(k < j) val += dp[k+1][j];
                val += sum[i][j];
                
                if(val < dp[i][j]) {
                    dp[i][j] = val;
                    opt[i][j] = k;
                }
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    return 0;
}