#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll n;
  cin >> n;
  vector<ll> p(n);
  for(ll i=0; i<n; i++)
    cin >> p[i];
  sort(p.begin(), p.end());
  ll median = p[n/2];
  ll cost = 0;
  for(ll i=0; i<n; i++)
    cost += abs(p[i]-median);
  cout << cost;
  
  return 0;
}