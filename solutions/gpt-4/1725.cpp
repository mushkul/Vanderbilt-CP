#include <bits/stdc++.h>
using namespace std;

int n,a,b;
double dp[105][705];

double solve(int rem, int sum){
    if(sum>b)return 0;
    if(rem==0)return sum>=a && sum<=b;
    if(dp[rem][sum]>-0.5)return dp[rem][sum];

    double ans=0;
    for(int i=1;i<=6;i++){
        ans+=solve(rem-1,sum+i);
    }

    return dp[rem][sum]=ans/6;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(6);

    cin>>n>>a>>b;
    for(int i=0;i<105;i++)for(int j=0;j<705;j++)dp[i][j]=-1;
    cout<<solve(n,0);

    return 0;
}