C++
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
    }
    multiset<ll> s;
    ll ans = INT64_MIN;
    for(int i = a; i <= n; i++) {
        if(i>b) s.erase(s.find(v[i-b-1]));
        s.insert(v[i-a]);
        ans = max(ans, v[i] - *s.begin());
    }
    cout << ans;
    return 0;
}