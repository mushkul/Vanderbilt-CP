#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll binary_expo(ll a,ll b)
{
    if(b==0)
    return 1;
    ll res=binary_expo(a,b/2);
    if(b%2)
    return ((res*res)%MOD*a)%MOD;
    else
    return (res*res)%MOD;
}

ll phi(ll n)
{
    return MOD-1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a%=MOD;
        ll x=binary_expo(b,c);
        cout<<binary_expo(a,x)<<"\n";
    }
    return 0;
}