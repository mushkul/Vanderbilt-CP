#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<int> dp(1 << n, INF);
    vector<int> parent(1 << n, -1);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        int k = __builtin_popcount(mask);
        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                int newMask = mask | (1 << j);
                if (dp[newMask] > dp[mask] + cost[k][j]) {
                    dp[newMask] = dp[mask] + cost[k][j];
                    parent[newMask] = mask;
                }
            }
        }
    }

    int finalMask = (1 << n) - 1;
    cout << dp[finalMask] << '\n';

    vector<pair<int, int>> assignment;
    int current = finalMask;
    while (current) {
        int prev = parent[current];
        int diff = current ^ prev;
        int task = __builtin_ctz(diff);
        int emp = __builtin_popcount(prev);
        assignment.emplace_back(emp + 1, task + 1);
        current = prev;
    }

    reverse(assignment.begin(), assignment.end());
    for (auto [a, b] : assignment) {
        cout << a << ' ' << b << '\n';
    }

    return 0;
}