#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> price(n), pages(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= price[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-price[i-1]] + pages[i-1]);
            }
        }
    }
    
    cout << dp[n][x];
    return 0;
}