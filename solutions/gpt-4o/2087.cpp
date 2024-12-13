#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> children(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> children[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, numeric_limits<long long>::max()));
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int median = (i + j) / 2;
            for (int p = i; p <= j; ++p) {
                dist[i][j] += abs(p - median) * children[p];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dist[1][i];
    }

    for (int j = 2; j <= k; ++j) {
        for (int i = j; i <= n; ++i) {
            for (int p = 0; p < i; ++p) {
                dp[i][j] = min(dp[i][j], dp[p][j-1] + dist[p+1][i]);
            }
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}