#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
int power(int x,int y,int p){
    int res=1;
    x=x%p;
    if (x==0) return 0;
    while (y>0){
        if (y&1) res=(1ll*res*x)%p;
        y=y>>1;
        x=(1ll*x*x)%p;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll x=power(2,n*n,MOD),y=power(2,n,MOD),z=power(2,(n*n)/2,MOD),ans=0;
    for(int i=n/2;i<n+n/2;i++){
        ans=((1ll*ans+power(x,i,MOD))%MOD+MOD)%MOD;
    }
    ans=(ans-y+MOD+MOD)%MOD;
    ans=(ans+z)%MOD;
    cout<<ans<<"\n";
    return 0;
}