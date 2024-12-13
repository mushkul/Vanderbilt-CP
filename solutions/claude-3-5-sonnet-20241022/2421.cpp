#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
 
int freq[26];
vector<vector<ll>> dp;
int n;
 
ll solve(int prev, int pos) {
    if (pos == n) return 1;
    
    if (dp[prev][pos] != -1) return dp[prev][pos];
    
    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0 && i != prev) {
            freq[i]--;
            ans = (ans + solve(i, pos + 1)) % MOD;
            freq[i]++;
        }
    }
    
    return dp[prev][pos] = ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    n = s.length();
    
    memset(freq, 0, sizeof(freq));
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    dp.assign(26, vector<ll>(n, -1));
    ll result = solve(26, 0);
    cout << result << "\n";
    
    return 0;
}