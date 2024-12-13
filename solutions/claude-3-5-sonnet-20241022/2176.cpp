#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll dp[501][501][2];
ll n, k;
pair<int, int> cells[250001];

ll solve(int pos, int rem, bool color) {
    if (rem == 0) return 1;
    if (pos >= n*n || rem > (n*n-pos)) return 0;
    
    if (dp[pos][rem][color] != -1) return dp[pos][rem][color];
    
    ll ways = solve(pos + 1, rem, !color);
    
    int r = cells[pos].first, c = cells[pos].second;
    bool safe = true;
    
    for (int i = 0; i < pos; i++) {
        int pr = cells[i].first, pc = cells[i].second;
        if (abs(r - pr) == abs(c - pc)) {
            safe = false;
            break;
        }
    }
    
    if (safe) {
        ways = (ways + solve(pos + 1, rem - 1, !color)) % MOD;
    }
    
    return dp[pos][rem][color] = ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cells[idx++] = {i, j};
        }
    }
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, k, 0) << "\n";
    
    return 0;
}