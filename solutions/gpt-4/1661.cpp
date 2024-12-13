#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll& v : a)
        cin>>v;

    ll sum=0, ans=0;
    map<ll,ll> counts;
    counts[0]++;
    for(ll i=0; i<n; i++) {
        sum += a[i];
        ans += counts[sum-x];
        counts[sum]++;
    }
    cout << ans;

    return 0;
}