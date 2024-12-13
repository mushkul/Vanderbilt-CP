#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, x[3005], dp[3005][3005], s[3005], p[3005];

ll get(int l, int r) {
    return p[r] - p[l-1] - s[l-1] * (s[r] - s[l-1]);
}

void solve (int l, int r, int optl, int optr) {
    if (l > r) return;
    int mid = (l + r) >> 1, opt = -1;
    dp[mid][k] = 1e18;
    for (int i = optl; i <= min(mid, optr); i++) {
        ll cur = dp[i-1][k-1] + get(i, mid);
        if (cur < dp[mid][k]) {
            dp[mid][k] = cur;
            opt = i;
        }
    }
    solve(l, mid - 1, optl, opt);
    solve(mid + 1, r, opt, optr);
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        s[i] = s[i-1] + x[i];
        p[i] = p[i-1] + x[i] * s[i];
    }
    for (int i = 0; i <= n; i++) dp[i][0] = 1e18;
    dp[0][0] = 0;
    for (k = 1; k <= n; k++) solve(k, n, 1, n);
    cout << dp[n][k-1] << '\n';
    return 0;
}