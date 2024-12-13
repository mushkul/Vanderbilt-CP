#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll n,m;

ll modpow(ll base, ll exp, ll modulus) {
  base %= modulus;
  ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

ll modInv(ll a, ll b){
    return 1<a ? b - modInv(b%a,a)*b/a : 1;
}

int main(){
    cin >> n >> m;
    ll result = modpow(m,n,MOD) - m*modpow(m,n-1,MOD);
    for (ll k=2; k<=n; ++k) {
        result += (m*modInv(k,MOD)%MOD)*modpow(m,n-k,MOD)%MOD;
    }
    cout << (result%MOD+MOD)%MOD;
    return 0;
}