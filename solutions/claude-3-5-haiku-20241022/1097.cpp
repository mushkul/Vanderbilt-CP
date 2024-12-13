#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (len == 1) {
                dp[i][j] = arr[i];
            } else {
                dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
            }
        }
    }
    
    long long total = 0;
    for (int x : arr) total += x;
    
    cout << (total + dp[0][n-1]) / 2 << endl;
    
    return 0;
}