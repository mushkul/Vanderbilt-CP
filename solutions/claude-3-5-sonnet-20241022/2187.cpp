#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
 
ll dp[1000001];
 
ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n % 2) {
        cout << 0;
        return 0;
    }
    
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) {
            cout << 0;
            return 0;
        }
    }
    
    int rem = n - s.size();
    int need = n/2 - count(s.begin(), s.end(), '(');
    
    if (need < 0 || need > rem) {
        cout << 0;
        return 0;
    }
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        if (i >= 2) {
            dp[i] = dp[i-2];
            if (i >= 4) dp[i] = (dp[i] + dp[i-4]) % MOD;
        }
    }
    
    ll ans = 0;
    for (int i = bal; i <= rem; i += 2) {
        if (i-bal > 2*(need-1)) break;
        ll ways = dp[rem-i];
        ll choose = 1;
        int positions = (rem-i)/2;
        if (need <= positions) {
            choose = 1;
            for (int j = 0; j < need; j++) {
                choose = (choose * (positions-j)) % MOD;
            }
            for (int j = 1; j <= need; j++) {
                choose = (choose * pow_mod(j, MOD-2)) % MOD;
            }
            ans = (ans + (ways * choose) % MOD) % MOD;
        }
    }
    
    cout << ans;
    return 0;
}