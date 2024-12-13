#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    
    vector<ll> a(2*n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    
    int ans = n;
    for(int start = 0; start < n; start++) {
        int count = 1;
        ll sum = 0;
        int j = start;
        
        for(int len = 0; len < n; len++) {
            if(sum + a[j] <= k) {
                sum += a[j];
            } else {
                sum = a[j];
                count++;
            }
            j++;
        }
        ans = min(ans, count);
    }
    
    cout << ans << endl;
    return 0;
}