#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5005;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    set<string> dict;
    for (int i = 0; i < k; i++) {
        string word;
        cin >> word;
        dict.insert(word);
    }
    
    vector<long long> dp(s.length() + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= s.length(); i++) {
        for (int j = 0; j < i; j++) {
            string sub = s.substr(j, i - j);
            if (dict.count(sub)) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
    
    cout << dp[s.length()] << endl;
    
    return 0;
}