C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    ll ans = 0;
    for(int i=1;i<n;++i){
        if(v[i] < v[i-1]){
            ans += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << ans;
    return 0;
}