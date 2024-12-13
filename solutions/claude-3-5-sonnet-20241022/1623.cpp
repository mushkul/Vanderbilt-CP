#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> p(n);
    ll total = 0;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }
    
    ll minDiff = total;
    for(int mask = 0; mask < (1<<n); mask++) {
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) {
                sum += p[i];
            }
        }
        ll diff = abs(total - 2*sum);
        minDiff = min(minDiff, diff);
    }
    
    cout << minDiff << endl;
    return 0;
}