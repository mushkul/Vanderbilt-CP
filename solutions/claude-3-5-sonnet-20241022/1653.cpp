#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int MAXN = 20;

int n;
ll x;
vector<ll> w;
vector<pii> dp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> x;
    w.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    dp.resize(1<<n, {n+1, 0});
    dp[0] = {1, 0};
    
    for(int s = 1; s < (1<<n); s++) {
        for(int p = 0; p < n; p++) {
            if(s & (1<<p)) {
                pii prev = dp[s^(1<<p)];
                ll weight = prev.second + w[p];
                
                if(weight <= x) {
                    pii cur = {prev.first, weight};
                    dp[s] = min(dp[s], cur);
                } else {
                    pii cur = {prev.first + 1, w[p]};
                    dp[s] = min(dp[s], cur);
                }
            }
        }
    }
    
    cout << dp[(1<<n)-1].first << '\n';
    
    return 0;
}