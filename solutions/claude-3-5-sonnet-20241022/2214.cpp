#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    cin >> n >> k;
    
    vector<int> ans(n);
    long long remaining = k;
    
    for(int i = 0; i < n; i++) {
        ans[i] = i + 1;
    }
    
    for(int i = n-1; i > 0 && remaining > 0; i--) {
        int steps = min((long long)i, remaining);
        int pos = i - steps;
        int val = ans[i];
        
        for(int j = i; j > pos; j--) {
            ans[j] = ans[j-1];
        }
        ans[pos] = val;
        
        remaining -= steps;
    }
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}