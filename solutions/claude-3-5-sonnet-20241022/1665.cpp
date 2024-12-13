#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<vector<long long>> dp(x + 1, vector<long long>(1 << n, 0));
    dp[0][0] = 1;

    for(int penalty = 0; penalty <= x; penalty++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            if(dp[penalty][mask] == 0) continue;

            int pos = 0;
            while(pos < n && (mask & (1 << pos))) pos++;
            
            if(pos == n) {
                dp[penalty][mask] %= mod;
                continue;
            }

            dp[penalty][mask | (1 << pos)] = (dp[penalty][mask | (1 << pos)] + dp[penalty][mask]) % mod;

            for(int k = pos + 1; k < n; k++) {
                if(mask & (1 << k)) continue;
                int newPenalty = penalty + a[k] - a[pos];
                if(newPenalty > x) continue;

                int newMask = mask | (1 << pos) | (1 << k);
                dp[newPenalty][newMask] = (dp[newPenalty][newMask] + dp[penalty][mask]) % mod;

                for(int j = k + 1; j < n; j++) {
                    if(mask & (1 << j)) continue;
                    if(a[j] - a[pos] + penalty > x) break;
                    newMask |= (1 << j);
                }
            }
        }
    }

    long long ans = 0;
    for(int penalty = 0; penalty <= x; penalty++) {
        ans = (ans + dp[penalty][(1 << n) - 1]) % mod;
    }
    cout << ans << "\n";
    return 0;
}