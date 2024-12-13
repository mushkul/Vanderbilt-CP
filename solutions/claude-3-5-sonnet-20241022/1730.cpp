#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        ll xorSum = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            xorSum ^= x;
        }
        
        if(xorSum == 0) {
            cout << "second\n";
        } else {
            cout << "first\n";
        }
    }
    
    return 0;
}