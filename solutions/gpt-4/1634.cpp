#include<bits/stdc++.h>
#define ll long long
#define inf 1000000007
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i=0; i<n; i++) cin >> c[i];
    vector<int> dp(x+1,inf);
    dp[0] = 0;
    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (i-c[j]>=0) dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    if (dp[x]==inf) cout << -1 << '\n';
    else cout << dp[x] << '\n';
}