#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    
    vector<array<ll,3>> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    
    sort(projects.begin(), projects.end());
    
    vector<ll> dp(n + 1);
    
    for (int i = n-1; i >= 0; i--) {
        ll next = n;
        ll low = i + 1, high = n-1;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (projects[mid][0] > projects[i][1]) {
                next = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        dp[i] = max(dp[i+1], projects[i][2] + dp[next]);
    }
    
    cout << dp[0] << endl;
    return 0;
}