#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        ll ops = 0;
        ll curr_max = arr[a];
        
        for (int i = a + 1; i <= b; i++) {
            if (arr[i] < curr_max) {
                ops += curr_max - arr[i];
                arr[i] = curr_max;
            }
            curr_max = max(curr_max, arr[i]);
        }
        
        cout << ops << "\n";
        
        // Restore original array
        for (int i = a; i <= b; i++) {
            arr[i] = arr[i];
        }
    }
    
    return 0;
}