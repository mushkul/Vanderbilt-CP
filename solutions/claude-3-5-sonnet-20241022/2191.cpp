#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    ll area = 0;
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += x[i] * y[j] - x[j] * y[i];
    }
    
    cout << abs(area) << "\n";
    
    return 0;
}