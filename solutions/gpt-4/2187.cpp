#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
// define pre computed array for factorial, inverse factorial, power 
ll fac[2000005], ifac[2000005], pw[2000005];

ll power(ll a, ll b)
{
	if(!b) return 1;
	ll p = power(a, b/2);
	p = p*p%mod;
	if(b&1) p = p*a%mod;
	return p;
}

ll inv(ll a)
{
	return power(a, mod-2);
}

ll C(int n, int k)
{
	if(k < 0 || k > n) return 0;
	return fac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fac[0] = 1;
	for(int i=1;i<=2000000;++i) fac[i] = fac[i-1]*i%mod;
	ifac[2000000] = inv(fac[2000000]);
	for(int i=1999999;i>=0;--i) ifac[i] = ifac[i+1]*(i+1)%mod;
	pw[0] = 1;
	for(int i=1;i<=2000000;++i) pw[i] = pw[i-1]*2%mod;
	string s;
	int n;
	cin>>n>>s;
	int x = 0, op = 0, cl = 0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i] == '(') op++;
		else cl++;
	}
	x = min(op, cl) + max(op, cl) - min(op, cl)/2;
	cout<<(op >= cl? C(n/2, x): 0)<<"\n";
	return 0;
}