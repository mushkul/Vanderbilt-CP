#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 5005;
ll pre[maxn], dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i = 1; i <= n; ++i) cin>>dp[i][i], pre[i] = pre[i - 1] + dp[i][i];
    for(int len = 2; len <= n; ++len) for(int l = 1; l + len - 1 <= n; ++l) {
        int r = l + len - 1; dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]) + pre[r] - pre[l - 1];
    }
    cout<<dp[1][n]<<endl;
    return 0;
}