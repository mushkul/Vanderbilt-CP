#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long solve(int n, string s) {
    int k = s.length();
    int open = 0, closed = 0;
    
    for (char c : s) {
        if (c == '(') open++;
        else closed++;
    }
    
    if (open > n/2 || closed > n/2 || closed > open) return 0;
    
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] == 0) continue;
            
            if (s[i] == '(') {
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
            } else {
                if (j > 0) {
                    dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
                }
            }
        }
    }
    
    long long result = 0;
    for (int j = 0; j <= n-k; j++) {
        if (open + j <= n/2 && closed + j <= n/2) {
            result = (result + dp[k][j]) % MOD;
        }
    }
    
    return result;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(n, s) << endl;
    return 0;
}