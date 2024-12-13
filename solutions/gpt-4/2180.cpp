#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> a, b;
vector<vector<ll>> dp, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n);
    b.resize(n);
    dp.assign(n+1, vector<ll>(n+1, 1e18));
    sum.assign(n+1, vector<ll>(n+1));
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    a.insert(a.begin(), b.begin(), b.end());
    sort(a.begin(), a.end());
    for (int i = 1; i <= 2*n; ++i) {
        sum[i] = sum[i-1];
        sum[i][lower_bound(a.begin(), a.end(), i) - a.begin()]++;
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) if (dp[i][j] < 1e18){
            int k = i+j;
            if (i < n) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + abs(sum[k+1][i] - b[i]));
            if (j < n) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + abs(sum[k+1][k] - a[j]));
        }
    }
    cout << dp[n][n] << '\n';     
}