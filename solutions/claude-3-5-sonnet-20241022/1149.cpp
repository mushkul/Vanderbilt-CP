#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    
    vector<long long> dp(n + 1);
    map<char, int> last;
    
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        dp[i] = (dp[i-1] * 2) % MOD;
        
        if(last.count(s[i-1])) {
            dp[i] = (dp[i] - dp[last[s[i-1]]-1] + MOD) % MOD;
        }
        
        last[s[i-1]] = i;
    }
    
    cout << dp[n];
    
    return 0;
}