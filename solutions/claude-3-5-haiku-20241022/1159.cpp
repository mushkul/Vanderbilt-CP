#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> h(n), s(n), k(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> k[i];
    
    vector<int> prices, pages;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k[i]; j *= 2) {
            prices.push_back(h[i] * j);
            pages.push_back(s[i] * j);
            k[i] -= j;
        }
        if (k[i] > 0) {
            prices.push_back(h[i] * k[i]);
            pages.push_back(s[i] * k[i]);
        }
    }
    
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < prices.size(); i++) {
        for (int j = x; j >= prices[i]; j--) {
            dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
        }
    }
    
    cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}