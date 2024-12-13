#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<vector<int>> projects(n, vector<int>(3));
    
    for (int i = 0; i < n; i++) {
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];
    }
    
    sort(projects.begin(), projects.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    vector<long long> dp(n);
    dp[0] = projects[0][2];
    
    for (int i = 1; i < n; i++) {
        long long currentProfit = projects[i][2];
        int lastProjectIndex = -1;
        
        for (int j = i - 1; j >= 0; j--) {
            if (projects[j][1] < projects[i][0]) {
                lastProjectIndex = j;
                break;
            }
        }
        
        if (lastProjectIndex != -1) {
            currentProfit += dp[lastProjectIndex];
        }
        
        dp[i] = max(currentProfit, dp[i-1]);
    }
    
    cout << dp[n-1] << endl;
    return 0;
}