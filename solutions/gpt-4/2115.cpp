#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll n = s.length();
    vector<ll> count(n+2, 0), freq(n+2, 0);
    for(int i=1;i<=n;i++) {
        count[i] = count[i-1] + (s[i-1] == '1');
        if(s[i-1] == '1') freq[count[i]]++;
    }
    ll res = 0, no_of_1 = count[n];
    freq[no_of_1+1] = 0;
    for(int i=no_of_1;i>=0;i--) res += freq[i+1], count[i] = res;
    for(ll k=0;k<=n;k++) cout<<count[k]<<" ";
    return 0;
}