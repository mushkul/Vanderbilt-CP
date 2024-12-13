#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
 
int n, m;
vector<int> mask_list;
vector<vector<ll>> dp;
 
bool valid_mask(int mask) {
    int count = 0;
    bool valid = true;
    for(int i = 0; i < n; i++) {
        if(mask & (1<<i)) {
            count++;
        } else {
            if(count % 2) {
                valid = false;
                break;
            }
            count = 0;
        }
    }
    return valid && (count % 2 == 0);
}
 
bool can_transition(int mask1, int mask2) {
    for(int i = 0; i < n; i++) {
        if((mask1 & (1<<i)) && (mask2 & (1<<i))) return false;
    }
    return true;
}
 
ll solve(int col, int mask) {
    if(col == m) return mask == 0;
    if(dp[col][mask] != -1) return dp[col][mask];
    
    ll ans = 0;
    for(int next_mask : mask_list) {
        if(can_transition(mask, next_mask)) {
            ans = (ans + solve(col + 1, next_mask)) % MOD;
        }
    }
    return dp[col][mask] = ans;
}
 
int main() {
    cin >> n >> m;
    
    for(int mask = 0; mask < (1<<n); mask++) {
        if(valid_mask(mask)) {
            mask_list.push_back(mask);
        }
    }
    
    dp.assign(m, vector<ll>(1<<n, -1));
    cout << solve(0, 0) << endl;
    
    return 0;
}