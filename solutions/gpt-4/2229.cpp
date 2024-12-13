#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
    int N = 505;
    vector<vector<long long> > dp(N, vector<long long>(N * N / 2 + 5));
    dp[0][0] = 1;
    for(int n = 1; n < N; ++n) {
        for(int k = 0; k < N * N / 2 + 5; ++k) {
            dp[n][k] = dp[n-1][k];
            if(k >= n){
                dp[n][k] = (dp[n][k] + dp[n][k - n]) % mod;
            }
        }
    }
    int n,k; 
    cin >> n >> k;
    int res = 0;
    for(int i = 0; i <= k; ++i) {
        res = (res + dp[n][i]) % mod;
    }
    cout << res << endl;
    return 0;
}