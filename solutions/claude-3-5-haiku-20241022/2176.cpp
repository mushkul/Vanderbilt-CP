#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 510;

long long choose[MAXN][MAXN];
vector<long long> white_diag[2 * MAXN];
vector<long long> black_diag[2 * MAXN];

void precompute_combinations(int n) {
    for (int i = 0; i < n; i++) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % MOD;
        }
    }
}

long long solve(int n, int k) {
    precompute_combinations(n);
    
    for (int i = 0; i < 2 * n; i++) {
        white_diag[i].clear();
        black_diag[i].clear();
        white_diag[i].resize(n+1, 0);
        black_diag[i].resize(n+1, 0);
    }
    
    white_diag[0][0] = 1;
    black_diag[0][0] = 1;
    
    for (int d = 1; d < 2 * n - 1; d++) {
        for (int cnt = 0; cnt <= min(d, n-1); cnt++) {
            if (d % 2 == 0) {
                white_diag[d][cnt] = white_diag[d-1][cnt];
                if (cnt > 0) white_diag[d][cnt] += white_diag[d-1][cnt-1];
                white_diag[d][cnt] %= MOD;
            } else {
                black_diag[d][cnt] = black_diag[d-1][cnt];
                if (cnt > 0) black_diag[d][cnt] += black_diag[d-1][cnt-1];
                black_diag[d][cnt] %= MOD;
            }
        }
    }
    
    vector<vector<long long>> dp(2*n, vector<long long>(k+1, 0));
    dp[0][0] = 1;
    
    for (int d = 1; d < 2*n; d++) {
        for (int cnt = 0; cnt <= k; cnt++) {
            for (int w = 0; w <= min(cnt, n-1); w++) {
                int b = cnt - w;
                if (b > n-1) continue;
                
                if (d % 2 == 0) {
                    dp[d][cnt] += dp[d-1][cnt-w] * white_diag[d-1][w];
                } else {
                    dp[d][cnt] += dp[d-1][cnt-b] * black_diag[d-1][b];
                }
                dp[d][cnt] %= MOD;
            }
        }
    }
    
    return dp[2*n-1][k];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    cout << solve(n, k) << "\n";
    
    return 0;
}