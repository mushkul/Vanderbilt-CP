#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<ll> x(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        vector<ll> v;
        for(int i = l; i <= r; i++) {
            v.push_back(x[i]);
        }
        sort(v.begin(), v.end());
        
        ll res = 1;
        for(ll val : v) {
            if(val > res) break;
            res += val;
        }
        
        cout << res << "\n";
    }
    
    return 0;
}