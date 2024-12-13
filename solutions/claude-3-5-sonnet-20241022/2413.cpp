#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main() {
    int t;
    cin >> t;
    
    vector<ll> dp1(1000001), dp2(1000001); 
    dp1[1] = dp2[1] = 1;
    
    for(int i = 2; i <= 1000000; i++) {
        dp1[i] = (2LL * dp1[i-1] + dp2[i-1]) % mod;
        dp2[i] = (4LL * dp2[i-1] + dp1[i-1]) % mod;
    }
    
    while(t--) {
        int n;
        cin >> n;
        cout << (dp1[n] + dp2[n]) % mod << '\n';
    }
    
    return 0;
}