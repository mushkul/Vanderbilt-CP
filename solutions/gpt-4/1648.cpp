#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n , q;
vector<ll> ar , bit;

void update(int i , ll val){
  for(; i <= n; i += i & -i)
    bit[i] += val;
}

ll sum(int i){
  ll s = 0;
  for(; i > 0; i -= i & -i)
    s += bit[i];
  return s;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  ar = vector<ll>(n+1); bit = vector<ll>(n+1,0);
  
  for(int i = 1; i <= n; i++){
    cin >> ar[i];
    update(i,ar[i]);
  }

  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int k;
      ll u;
      cin >> k >> u;
      update(k, u-ar[k]);
      ar[k] = u;
    }else{
      int a , b;
      cin >> a >> b;
      cout << sum(b) - sum(a-1) << "\n"; 
    }
  }
  return 0;
}