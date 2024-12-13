#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
int n, m;
string pat;
vector<vector<long long>> dp;
vector<int> pi;
 
void compute_pi() {
    pi = vector<int>(m);
    for(int i = 1; i < m; i++) {
        int j = pi[i-1];
        while(j > 0 && pat[i] != pat[j]) j = pi[j-1];
        if(pat[i] == pat[j]) j++;
        pi[i] = j;
    }
}
 
int next_state(int j, char c) {
    while(j > 0 && pat[j] != c) j = pi[j-1];
    if(pat[j] == c) j++;
    return j;
}
 
long long solve(int pos, int matched) {
    if(matched == m) return 0;
    if(pos == n) return 0;
    
    if(dp[pos][matched] != -1) return dp[pos][matched];
    
    long long ans = 0;
    for(char c = 'A'; c <= 'Z'; c++) {
        int next_match = next_state(matched, c);
        if(next_match < m) {
            ans = (ans + solve(pos+1, next_match)) % MOD;
        }
    }
    return dp[pos][matched] = ans;
}
 
int main() {
    cin >> n >> pat;
    m = pat.length();
    compute_pi();
    
    dp.assign(n, vector<long long>(m, -1));
    long long total = 1;
    for(int i = 0; i < n; i++) total = (total * 26) % MOD;
    
    long long invalid = 0;
    for(int i = 0; i < m; i++) {
        invalid = (invalid + solve(i, 0)) % MOD;
    }
    
    cout << (total - invalid + MOD) % MOD << endl;
    return 0;
}