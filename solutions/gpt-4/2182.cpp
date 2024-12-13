#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll modPow(ll base, ll power){
	ll res = 1;
	while(power>0){
		if(power%2 == 1){
			res = (res*base)%MOD;
			power--;
		}
		base = (base*base)%MOD;
		power /= 2;
	}
	return res;
}

int main(){
	int n;
	cin>>n;
	ll prod = 1;
	ll sum = 0, tsum = 1;
	ll num = 1, tnum = 1;

	for(int i=0;i<n;i++){
		ll p, k;
		cin>>p>>k;
		num = (num*(k+1))%MOD;
		ll cur = modPow(p, k+1)-1;
		cur = (cur*modPow(p-1, MOD-2))%MOD;
		sum = (sum+cur*tsum)%MOD;
		tsum = (tsum*cur)%MOD;
		ll div = modPow(prod, k);
		tnum = (tnum*div)%MOD;
		prod = (prod*(cur))%MOD;
	}
	cout<<num<<" "<<sum<<" "<<tnum<<endl;
	return 0;
}