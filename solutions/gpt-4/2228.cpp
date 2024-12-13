#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5,mod=1e9+7;
ll f[maxn],finv[maxn],inv[maxn];
void init(){
    inv[1]=1;
    for(int i=2;i<maxn;i++){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
    f[0]=finv[0]=1;
    for(int i=1;i<maxn;i++){
        f[i]=f[i-1]*i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}
ll C(int n,int m){
    if(m>n || m<0)return 0;
    return f[n]*finv[m]%mod*finv[n-m]%mod;
}
ll pow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+(i&1?-1:1)*C(k,i)*pow(k-i,n)%mod+mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}