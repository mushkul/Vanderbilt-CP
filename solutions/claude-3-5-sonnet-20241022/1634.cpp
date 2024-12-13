#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<int> dp(x+1, 1e9);
    dp[0] = 0;
    
    for(int sum = 1; sum <= x; sum++) {
        for(int coin : coins) {
            if(sum-coin >= 0) {
                dp[sum] = min(dp[sum], dp[sum-coin] + 1);
            }
        }
    }
    
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
    
    return 0;
}