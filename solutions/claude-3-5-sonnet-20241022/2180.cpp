#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    
    long long ans = 0;
    int coins_up = 0;
    
    for(int i=0; i<n; i++) {
        int up = a[i];
        int down = b[i];
        
        coins_up += up;
        int should_be = i + 1;
        
        if(coins_up > should_be) {
            int move_down = coins_up - should_be;
            ans += move_down;
            coins_up -= move_down;
        }
        
        if(coins_up < should_be) {
            int move_up = should_be - coins_up;
            ans += move_up; 
            coins_up += move_up;
        }
    }
    
    cout << ans << endl;
    return 0;
}