#include <bits/stdc++.h>
using namespace std;

const int N = 8;
double dp[101][8][8];

double solve(int k) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[0][i][j] = 1.0;

    for (int step = 1; step <= k; ++step) {
        double next_dp[8][8] = {};
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                double prob = 0;
                if (x > 0) prob += dp[step - 1][x - 1][y];
                if (x < N - 1) prob += dp[step - 1][x + 1][y];
                if (y > 0) prob += dp[step - 1][x][y - 1];
                if (y < N - 1) prob += dp[step - 1][x][y + 1];
                next_dp[x][y] = prob / 4.0;
            }
        }
        memcpy(dp[step], next_dp, sizeof(next_dp));
    }

    double expected_empty = 0;
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < N; ++y)
            expected_empty += (1.0 - dp[k][x][y]);

    return expected_empty;
}

int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(6) << solve(k) << endl;
    return 0;
}