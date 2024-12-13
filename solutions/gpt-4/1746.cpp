C++
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
long long dp[100005][105],mod=1e9+7;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[1]==0)
        for(int j=1;j<=m;j++)
            dp[1][j]=1;
    else
        dp[1][a[1]]=1;
    for(int i=2;i<=n;i++)
        if(a[i]==0)
            for(int j=1;j<=m;j++)
    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
        else
    dp[i][a[i]]=(dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1])%mod;
    long long ans=0;
    if(a[n]==0)
        for(int j=1;j<=m;j++)
            ans=(ans+dp[n][j])%mod;
    else
        ans=dp[n][a[n]];
    cout<<ans<<endl;
    return 0;
}