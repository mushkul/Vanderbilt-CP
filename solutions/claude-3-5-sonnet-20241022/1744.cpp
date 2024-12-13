#include <bits/stdc++.h>
using namespace std;
 
int dp[501][501];
 
int solve(int a, int b) {
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    
    int ans = INT_MAX;
    
    for (int i = 1; i < a; i++) {
        ans = min(ans, 1 + solve(i, b) + solve(a-i, b));
    }
    
    for (int i = 1; i < b; i++) {
        ans = min(ans, 1 + solve(a, i) + solve(a, b-i));
    }
    
    return dp[a][b] = ans;
}
 
int main() {
    int a, b;
    cin >> a >> b;
    
    memset(dp, -1, sizeof(dp));
    cout << solve(a, b);
    
    return 0;
}