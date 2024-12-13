#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    vector<int> count(26, 0);
    
    for (char c : s) {
        count[c - 'a']++;
    }
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(26, vector<int>(26, 0)));
    dp[0][26][26] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int last1 = 0; last1 <= 26; last1++) {
            for (int last2 = 0; last2 <= 26; last2++) {
                if (dp[i][last1][last2] == 0) continue;
                
                for (int j = 0; j < 26; j++) {
                    if (count[j] == 0) continue;
                    
                    if (j != last1 && j != last2) {
                        count[j]--;
                        dp[i + 1][j][last1] += dp[i][last1][last2];
                        dp[i + 1][j][last1] %= 1000000007;
                        count[j]++;
                    }
                }
            }
        }
    }
    
    int result = 0;
    for (int last1 = 0; last1 < 26; last1++) {
        for (int last2 = 0; last2 < 26; last2++) {
            result += dp[n][last1][last2];
            result %= 1000000007;
        }
    }
    
    cout << result << endl;
    return 0;
}