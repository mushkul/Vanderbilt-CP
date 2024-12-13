#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<pair<int, int>> dp(1 << n, {n + 1, 0});
    dp[0] = {0, 0};

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue;
            int prev = mask ^ (1 << i);
            auto [prev_rides, prev_weight] = dp[prev];

            if (prev_weight + w[i] <= x) {
                auto curr = make_pair(prev_rides, prev_weight + w[i]);
                if (curr.first < dp[mask].first || (curr.first == dp[mask].first && curr.second > dp[mask].second)) {
                    dp[mask] = curr;
                }
            } else {
                auto curr = make_pair(prev_rides + 1, w[i]);
                if (curr.first < dp[mask].first || (curr.first == dp[mask].first && curr.second > dp[mask].second)) {
                    dp[mask] = curr;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1].first + (dp[(1 << n) - 1].second > 0) << endl;
    return 0;
}