#include <bits/stdc++.h>
using namespace std;

int dp[501][501];

int solve(int a, int b) {
    if (a == b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    
    dp[a][b] = INT_MAX;
    
    for (int i = 1; i < a; i++) {
        dp[a][b] = min(dp[a][b], 1 + solve(i, b) + solve(a-i, b));
    }
    
    for (int j = 1; j < b; j++) {
        dp[a][b] = min(dp[a][b], 1 + solve(a, j) + solve(a, b-j));
    }
    
    return dp[a][b];
}

int main() {
    int a, b;
    cin >> a >> b;
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(a, b) << endl;
    
    return 0;
}