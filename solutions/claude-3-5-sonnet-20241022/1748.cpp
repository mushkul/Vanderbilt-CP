#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int mod = 1e9+7;
 
int main() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<ll> dp(n);
    map<int,ll> mp;
    
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(auto it = mp.begin(); it != mp.end() && it->first < nums[i]; it++) {
            dp[i] = (dp[i] + it->second) % mod;
        }
        mp[nums[i]] = (mp[nums[i]] + dp[i]) % mod;
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans + dp[i]) % mod;
    }
    
    cout << ans << endl;
    
    return 0;
}