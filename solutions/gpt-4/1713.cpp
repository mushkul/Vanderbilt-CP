#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll divisors[1000005] = {0};
void sieve(){
  for(ll i=1; i<=1000000; i++){
    for(ll j=i; j<=1000000; j+=i){
      divisors[j]++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();

  ll n, x;
  cin >> n;
  while(n--){
    cin >> x;
    cout << divisors[x] << "\n";
  }

  return 0;
}