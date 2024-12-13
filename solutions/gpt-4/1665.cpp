#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;
ll n,x,i,j,k;
ll dp[102][5002],skill[102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    for(i=1;i<=n;i++)
        cin >> skill[i];
    sort(skill+1,skill+1+n);
    dp[0][0]=1LL;
    for(i=1;i<=n;i++)
    {
        for(j=i;j>=0;j--)
        {
            for(k=0;k<=x;k++)
            {
                if(k+skill[i]*j<=x)
                    dp[j][k+skill[i]*j] = (dp[j][k+skill[i]*j]%MOD + dp[j-1][k]%MOD)%MOD;
            }
        }
    }
    ll ans = 0;
    for(i=0;i<=x;i++)
        for(j=0;j<=n;j++)
            ans=(ans%MOD + dp[j][i]%MOD)%MOD;
    cout << ans << "\n";
    return 0;
}