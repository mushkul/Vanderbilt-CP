#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define sz 1003
typedef long long ll;
ll dp[sz][sz][2];
int n;
ll solve(int pos, int prev, int flag){
  if(pos==n){
    return 1;
  }
  if(dp[pos][prev][flag]!=-1){
    return dp[pos][prev][flag];
  }
  ll ans=0;
  if(prev==0){
    ans=((n-1)*solve(pos+1,1,1))%mod;
    ans+=(solve(pos+1,0,0))%mod;
  }
  else if(flag){
    ans=((n-pos)*solve(pos+1,1,1))%mod;
    ans+=((pos-1)*solve(pos+1,1,0))%mod;
  }
  else{
    ans=(pos*solve(pos+1,1,0))%mod;
    ans+=((n-pos)*solve(pos+1,1,1))%mod;
  }
  ans%=mod;
  return dp[pos][prev][flag]=ans;
}
int main(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll ans=0;
    for(int i=1;i<n;i++){
        ans=(ans+solve(1,0,0))%mod;
    }
    cout<<ans<<endl;
    return 0;
}