#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll res=0,l=1,rest=n,m=1;
    for (ll T=1;; T*=10){
        ll round=min(m,rest/l);
        rest-=round*l;
        res+=round*T;
        if (round<m) break;
        m++;
        l=1ll*l*m/(m-1);
    }
    cout<<res<<'\n';
    return 0;
}