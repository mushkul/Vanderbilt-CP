#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s;
  cin >> s;
  
  ll n = s.length();
  ll count = 1, max_count = 1;
  
  for(ll i = 1; i < n; i++){
    if(s[i-1] == s[i]){
      count++;
      max_count = max(count, max_count);
    }
    else{
      count = 1;
    }
  }
  cout << max_count;
  
  return 0;
}