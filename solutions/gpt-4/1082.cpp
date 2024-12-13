#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
unordered_map<ll,ll>w;
  
ll sol(ll n) {
  if (n==0)
    return 0;

  if(w[n]!=0)
    return w[n];
  
  ll x=n/2;
  w[n]=((n*(n+1)/2)-((x*(x+1))/2)+mod)%mod;
  w[n]=((w[n]-2*sol(n/2))+mod)%mod;
  return w[n];
}

int main() {
  ll n;
  cin>>n;
  cout<<sol(n)<<endl;
  return 0;
}