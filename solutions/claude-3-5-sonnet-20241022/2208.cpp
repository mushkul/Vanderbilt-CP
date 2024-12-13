#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool has_odd = false;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 1) {
            has_odd = true;
        }
    }
    
    cout << (has_odd ? "first" : "second") << '\n';
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