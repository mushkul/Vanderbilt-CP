#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 505, Mod = 1e9 + 7;
int dp[MX][MX], Next[MX][26];
string S;
int n;

int solve(int l, int r){
    if(l > r) return 1;
    if(~dp[l][r]) return dp[l][r];
    int x = solve(l+1,r), y = Next[l][S[l]-'a'];
    while(y <= r){
        x = (x + 1LL * solve(l+1, y-1) * solve(y+1,r)) % Mod;
        y = Next[y][S[l]-'a'];
    }
    return dp[l][r] = x;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin>>S;
    n = S.size();
    for(int i=n-1; i>=0; --i){
        for(int j=0; j<26; ++j) Next[i][j] = (i+1<n) ? Next[i+1][j] : n;
        Next[i][S[i]-'a'] = i+1;
    }
    cout<<solve(0,n-1);
    return 0;
}