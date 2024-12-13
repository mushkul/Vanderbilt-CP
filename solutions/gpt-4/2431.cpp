#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll x){
    ll c=1;
    ll l=1;
    ll num=9;
    while(x>l*num){
        x-=l*num;
        l++;
        num*=10;
        c*=10;
    }
    c--;
    c+=x/l;
    x%=l;
    if(x==0)
        x=l;
    else
        c++;
    ll r;
    while(x--){
        r=c%10;
        c/=10;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        cout<<func(k)<<"\n";
    }
    return 0;
}