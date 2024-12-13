#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, x;
    cin >> n >> x;
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll sum = 0, count = 0;
    map<ll, ll> prefix_sums;
    prefix_sums[0] = 1;
    
    for(int i = 0; i < n; i++) {
        sum += a[i];
        count += prefix_sums[sum - x];
        prefix_sums[sum]++;
    }
    
    cout << count;
    return 0;
}