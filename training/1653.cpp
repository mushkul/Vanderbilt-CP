#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    dp[0] = {0, 0};

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            int newMask = mask | (1 << i);
            pair<int, int> option = dp[mask];
            if (option.second + w[i] <= x) {
                option.second += w[i];
            } else {
                option.first++;
                option.second = w[i];
            }
            dp[newMask] = min(dp[newMask], option);
        }
    }
    
    cout << dp[(1 << n) - 1].first + 1 << "\n";
    return 0;
}