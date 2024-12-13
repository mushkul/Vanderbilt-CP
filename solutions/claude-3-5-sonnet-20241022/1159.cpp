#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> price(n), pages(n), copies(n);
    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];
    for(int i = 0; i < n; i++) cin >> copies[i];
    
    vector<pair<int,int>> items;
    
    for(int i = 0; i < n; i++) {
        for(int k = 1; k <= copies[i]; k *= 2) {
            items.push_back({k * price[i], k * pages[i]});
            copies[i] -= k;
        }
        if(copies[i] > 0) {
            items.push_back({copies[i] * price[i], copies[i] * pages[i]});
        }
    }
    
    vector<int> dp(x + 1);
    
    for(auto [p, s] : items) {
        for(int j = x; j >= p; j--) {
            dp[j] = max(dp[j], dp[j-p] + s);
        }
    }
    
    cout << dp[x] << endl;
    
    return 0;
}