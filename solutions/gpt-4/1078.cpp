#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0)), grid(n+5, vector<int>(n+5, 1));
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 0;
    }
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) continue;
			if (grid[i][j]) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
				if (dp[i][j] >= MOD) dp[i][j] -= MOD;
			}
		}
	}
	cout << dp[n][n];
    return 0;
}