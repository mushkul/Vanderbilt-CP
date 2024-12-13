#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, MAXN = 1002, MAXK = 502*500/2 + 2;
int comb[MAXK][MAXN], dp[MAXN][MAXK], n, k;
vector<int> diags;

void compute() {
    comb[0][0] = 1;
    for (int i = 1; i < MAXK; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= min(i,MAXN-1); j++) {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
        }
    }
    
    for (int num = 0; num < (int)diags.size(); num++) {
        dp[num][0] = 1;
        for (int placed = 1; placed < MAXK; placed++) {
            dp[num][placed] = dp[num][placed-1];
            if (num) {
                dp[num][placed] += dp[num-1][placed];
                if (placed >= diags[num]) {
                    dp[num][placed] += MOD - dp[num-1][placed-diags[num]];
                }
                dp[num][placed] %= MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    n *= 2;

    for (int x = 2; x <= n; x++) {
        diags.push_back(min(x-1, n-x+1));
    }

    compute();

    int answer = 0;
    
    for (int take = 0; take*2 <= k; take++) {
        int rest = k - 2*take;
        if (rest <= (int)diags.size()) {
            long long multiplier = comb[k][take] * comb[k-take][rest] % MOD;
            answer += multiplier * dp[(int)diags.size()-1][take * 2 + rest] % MOD;
            if (answer >= MOD) {
                answer -= MOD;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}