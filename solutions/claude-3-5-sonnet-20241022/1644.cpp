#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<ll> psum(n+1);
    for(int i = 0; i < n; i++) {
        psum[i+1] = psum[i] + arr[i]; 
    }
    
    ll result = LLONG_MIN;
    multiset<ll> sums;
    
    for(int i = a; i <= n; i++) {
        if(i > b) {
            sums.erase(sums.find(psum[i-b-1]));
        }
        sums.insert(psum[i-a]);
        result = max(result, psum[i] - *sums.begin());
    }
    
    cout << result << "\n";
    return 0;
}