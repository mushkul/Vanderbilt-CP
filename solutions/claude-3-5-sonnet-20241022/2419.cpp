#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int len = n-1; len > 0; len--) {
        for(int i = 0; i < len; i++) {
            a[i] = a[i] ^ a[i+1];
        }
    }
    
    cout << a[0] << "\n";
    
    return 0;
}