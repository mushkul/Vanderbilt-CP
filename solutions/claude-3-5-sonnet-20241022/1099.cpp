#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int xor_sum = 0;
        
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(i > 0) {
                xor_sum ^= x;
            }
        }
        
        if(xor_sum > 0) {
            cout << "first\n";
        } else {
            cout << "second\n";
        }
    }
    
    return 0;
}