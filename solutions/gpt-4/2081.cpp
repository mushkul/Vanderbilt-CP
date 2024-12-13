c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
vector<int>V[maxn];
ll dp[maxn][30];
int n,k1,k2;
ll solve(int v,int p,int l){
    ll &ret = dp[v][l];
    if(ret != -1)return ret;
    ret = 1;
    for(auto u:V[v]){
        if(u == p)continue;
        ret += solve(u,v,l-1);
    }
    return ret;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> k1 >> k2;
    for(int i = 1; i < n; i++){
        int a,b;cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int len = k1; len <= k2; len++)
            ans += solve(i,0,len);
    }
    ans /= 2;
    cout << ans << '\n';
    return 0;
}