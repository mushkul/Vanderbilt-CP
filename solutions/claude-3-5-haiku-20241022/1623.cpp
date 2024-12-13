#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    ll total = accumulate(p.begin(), p.end(), 0LL);
    ll minDiff = total;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        ll group1 = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1 += p[i];
            }
        }
        ll group2 = total - group1;
        minDiff = min(minDiff, abs(group1 - group2));
    }
    
    cout << minDiff << endl;
    return 0;
}