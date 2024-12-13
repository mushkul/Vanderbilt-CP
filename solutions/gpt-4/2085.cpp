#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5+5;
ll s[MAXN], f[MAXN], dp[MAXN];
vector<pair<ll, ll>> v; 

int main(){
    ll n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) cin >> f[i];
    for(int i = 1; i <= n; i++) v.push_back({f[i], s[i]});
    sort(v.begin(), v.end());
    for(int i = n-1; i >= 0; i--) v[i].second = max(v[i].second, v[i+1].second);
    dp[0] = x*v[0].second;
    for(int i = 1; i < n; i++) dp[i] = min(dp[i-1], v[i].first*v[i].second);
    cout << dp[n-1] << "\n";
    return 0;
}