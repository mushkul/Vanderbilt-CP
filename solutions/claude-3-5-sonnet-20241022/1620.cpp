#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>& machines, ll time, ll target) {
    ll products = 0;
    for(ll k : machines) {
        products += time/k;
        if(products >= target) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, t;
    cin >> n >> t;
    
    vector<ll> machines(n);
    for(int i = 0; i < n; i++) {
        cin >> machines[i];
    }
    
    ll low = 0, high = 1e18;
    
    while(low < high) {
        ll mid = low + (high-low)/2;
        if(check(machines, mid, t)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    cout << low << "\n";
    
    return 0;
}