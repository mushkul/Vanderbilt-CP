#include <bits/stdc++.h>
using namespace std;

int grundy(long long x) {
    return x % 4;
}

void solve() {
    int n;
    cin >> n;
    int xorSum = 0;
    
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        xorSum ^= grundy(x);
    }
    
    if(xorSum) {
        cout << "first\n";
    } else {
        cout << "second\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}