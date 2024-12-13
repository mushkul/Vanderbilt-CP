#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=2e1+5,MOD=1e9+7,INF=1e18+5;
vector<ll>v;
ll n,sum=0,ans=INF;
void cal(ll i,ll s){
    if(i==n){
        ans=min(ans,abs(sum-2*s));
        return ;
    }
    cal(i+1,s+v[i]);
    cal(i+1,s);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(auto &a:v){
        cin>>a;
        sum+=a;
    }
    cal(0,0);
    cout<<ans;
    return 0;
}