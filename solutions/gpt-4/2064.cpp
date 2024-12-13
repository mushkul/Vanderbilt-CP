#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
 
ll inv[1000001],fact[1000001],ifact[1000001];

void pre()
{
    fact[0]=ifact[0]=fact[1]=ifact[1]=inv[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        inv[i] = mod - (mod/i)*inv[mod%i]%mod;
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i] = (ifact[i-1]*inv[i])%mod;
    }
}

ll nCr(int n, int r)
{
    if(r>n || r<0)
        return 0;
    return fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int n;
    cin>>n;
    if(n%2)
        cout<<"0\n";
    else
        cout<<(nCr(n,n/2)*inv[n/2+1])%mod<<"\n";
    return 0;
}