C++
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> last(26, -1);
    vector<long long> dp(n+1);
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        dp[i+1] = dp[i] * 2 % mod;
        if(last[s[i] - 'a'] >= 0)
            dp[i+1] -= dp[last[s[i]-'a']];
        dp[i+1]%=mod;
        if(dp[i+1]<0)
            dp[i+1]+=mod;
        last[s[i] - 'a'] = i;
    }
    cout << dp[n] << '\n';
}