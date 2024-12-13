#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 3005;
ll n, k, c[maxn], s[maxn], dp[maxn][maxn];
deque<int> dq[maxn];

ll sum(int i, int j) {
    return s[j] - s[i-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=1; i<=n; i++) s[i] = s[i-1] + c[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        dq[i-1].push_back(i-1);
        for(int j=1; j<=k; j++) {
            while(!dq[j-1].empty() && dq[j-1].front() < i-j) dq[j-1].pop_front();
            dp[i][j] = dp[dq[j-1].front()][j-1] + sum(dq[j-1].front()+1, i);
            while(!dq[j-1].empty() && dp[i][j-1] - sum(i+1, dq[j-1].back()) <= dp[dq[j-1].back()][j-1] - sum(dq[j-1].back()+1, i)) dq[j-1].pop_back();
            dq[j-1].push_back(i);
        }
    }
    ll ans = 1e18;
    for(int i=k; i<=n; i++) ans = min(ans, dp[i][k]);
    cout << ans << "\n";
    return 0;
}