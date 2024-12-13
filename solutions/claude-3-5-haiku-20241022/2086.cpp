#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;
long long dp[MAXN][MAXN];
long long prefixSum[MAXN];

long long getSubarraySum(int l, int r) {
    return prefixSum[r] - prefixSum[l-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            for (int p = 0; p < i; p++) {
                long long sum = getSubarraySum(p+1, i);
                dp[i][j] = min(dp[i][j], dp[p][j-1] + sum * sum);
            }
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}