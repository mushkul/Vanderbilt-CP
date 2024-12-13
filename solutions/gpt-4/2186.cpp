#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sub_count[30][200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll n = s.size();
    for(ll i = 0; i < n; i++){
        sub_count[s[i] - 'a'][i + 1]++;
    }
    for(ll i = 0; i < 26; i++){
        for(ll j = 1; j <= n; j++){
            sub_count[i][j] += sub_count[i][j - 1];
        }
    }
    ll ans = n;
    for(ll len = 1; len <= n; len++){
        vector<ll> v(26);
        for(ll i = len; i <= n; i++){
            ll x = 0, y = 1e9;
            for(ll j = 0; j < 26; j++){
                ll k = sub_count[j][i] - sub_count[j][i - len];
                if(k > 0){
                    v[j] = k;
                    x = max(x, k);
                    y = min(y, k);
                }
            }
            if(x == y){
                ans++;
            }
            for(auto &j : v){
                j = 0;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}