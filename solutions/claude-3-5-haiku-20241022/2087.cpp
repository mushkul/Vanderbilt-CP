#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 3005;
int n, k;
int children[MAXN];
long long dp[MAXN][MAXN];
long long pref[MAXN];
 
long long cost(int l, int r) {
    int mid = (l + r) / 2;
    long long curr = 0;
    for (int i = l; i <= r; i++) {
        curr += children[i] * abs(i - mid);
    }
    return curr;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> children[i];
        pref[i] = pref[i-1] + children[i];
    }
 
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
 
    for (int j = 1; j <= k; j++) {
        for (int i = j; i <= n; i++) {
            for (int p = j-1; p < i; p++) {
                dp[i][j] = min(dp[i][j], dp[p][j-1] + cost(p+1, i));
            }
        }
    }
 
    cout << dp[n][k] << endl;
    return 0;
}