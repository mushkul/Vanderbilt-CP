#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 5005;
const int MOD = 1e9+7;
int dp[MAX_N];
vector<int> hashval[MAX_N][26];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> s;
    n = s.length();
    cin >> k;
    vector<string> w(k);
    for(int i = 0; i < k; i++) cin >> w[i];
    reverse(s.begin(), s.end());
    for(int i = 0; i < k; i++) reverse(w[i].begin(), w[i].end());
    vector<int> pre(n+1), suf(n+1);
    dp[0] = 1;
    for(int i = 0; i < k; i++) {
        pre[0] = w[i][0] - 'a' + 1;
        for(int j = 1; j < (int)w[i].size(); j++) pre[j] = (26LL * pre[j - 1] + w[i][j] - 'a' + 1) % MOD;
        if((int)w[i].size() <= n) hashval[w[i].size()][w[i][0]-'a'].push_back(pre[(int)w[i].size()-1]);
    }
    suf[n] = 0;
    for(int i = n-1; i >= 0; i--) {
        suf[i] = ((s[i]-'a'+1) + 26LL * suf[i+1]) % MOD;
        dp[i] = dp[i+1];
        for(int j = 0; j < 26; j++) {
            if(hashval[i+1][j].size() == 0) continue;
            if(26LL * suf[i+1] + s[i] - 'a' - j < 0) continue;
            if((26LL * suf[i+1] + s[i] - 'a' - j) % MOD != suf[i]) continue;
            int z = lower_bound(hashval[i+1][j].begin(), hashval[i+1][j].end(), suf[i]) - hashval[i+1][j].begin();
            int zz = upper_bound(hashval[i+1][j].begin(), hashval[i+1][j].end(), suf[i]) - hashval[i+1][j].begin();
            dp[i] = (dp[i] + zz - z + dp[i+1-zz]) % MOD;
        } 
    }
    cout << dp[0] << "\n";
    return 0;
}