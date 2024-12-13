C++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int N = 1e6+5;
ll fact[N], inv[N];
ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll C(int n, int r){
    if(n < r) return 0;
    ll ans = fact[n];
    ans = (ans * inv[n-r]) % mod;
    ans = (ans * inv[r]) % mod;
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = inv[0] = 1;
    for(ll i=1;i<N;i++){
        fact[i] = (i * fact[i-1]) % mod;
        inv[i] = power(fact[i], mod-2);
    }
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for(char c : s) cnt[c-'a']++;
    ll ans = fact[s.size()];
    for(int i=0;i<26;i++)
        ans = (ans * inv[cnt[i]]) % mod;
    cout << ans;
    return 0;
}