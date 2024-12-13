#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        ll ops = 0;
        vector<ll> tmp;
        for(int i = l; i <= r; i++) tmp.push_back(a[i]);
        
        ll mx = tmp[0];
        for(int i = 1; i < (int)tmp.size(); i++) {
            if(tmp[i] < mx) {
                ops += mx - tmp[i];
                tmp[i] = mx;
            }
            mx = tmp[i];
        }
        
        mx = tmp.back();
        for(int i = (int)tmp.size()-2; i >= 0; i--) {
            if(tmp[i] > mx) {
                ops += tmp[i] - mx;
                tmp[i] = mx;
            }
            mx = tmp[i];
        }
        
        cout << ops << '\n';
    }
}