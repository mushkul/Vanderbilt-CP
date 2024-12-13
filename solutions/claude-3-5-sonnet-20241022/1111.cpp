#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    int start = 0, maxLength = 1;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    for(int i = 0; i < n-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
    
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i < n-len+1; i++) {
            int j = i + len - 1;
            
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if(len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }
    
    return s.substr(start, maxLength);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    
    return 0;
}