#include<bits/stdc++.h>
#define mod 1000000007
#define mx 22
#define maxM ((1<<20) + 5)
using namespace std;
typedef long long ll;

ll dp[maxM][mx], n, m;
vector<ll> adj[mx];

ll solve(ll mask, ll root){
    if(__builtin_popcount(mask) == n - 1 && root == n - 1) return dp[mask][root] = 1;
    else if(dp[mask][root] != -1) return dp[mask][root];
    else{
        ll ans = 0;
        for(ll x: adj[root]){
            if(!(mask&(1<<x))){
                ans = (ans + solve(mask|(1<<x), x))%mod;
            }
        }
        return dp[mask][root] = ans;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(ll i = 1; i <= m; i++){
        ll u, v;
        cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
    }
    memset(dp, -1, sizeof dp);
    cout<<solve(1, 0)<< '\n';
    return 0;
}