#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e15;
const ll MAXN = 2505;
vector<pair<ll, ll>> g[MAXN];
ll dp[MAXN];

int main(){
    ll n, m, a, b, x;
    cin >> n >> m;
    for(ll i=0; i<m; ++i){
        cin >> a >> b >> x;
        g[a].push_back({b, x});
    }
    for(ll i=1; i<=n; ++i) dp[i]=-INF;
    dp[1]=0;
    for(ll j=0; j<n-1; ++j){
        for(ll i=1; i<=n; ++i){
            for(auto e : g[i]){
                dp[e.first] = max(dp[e.first], dp[i] + e.second);
            }
        }
    }
    ll ans = dp[n];
    for(ll j=0; j<n; ++j){
        for(ll i=1; i<=n; ++i){
            for(auto e : g[i]){
                if(dp[e.first] < dp[i] + e.second){
                    dp[e.first] = dp[i] + e.second;
                    if(e.first == n){
                        cout << "-1\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}