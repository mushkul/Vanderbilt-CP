#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i <= n-k; i++) {
        vector<ll> window;
        for(int j = i; j < i+k; j++) {
            window.push_back(a[j]);
        }
        sort(window.begin(), window.end());
        
        ll median = window[k/2];
        ll cost = 0;
        
        for(int j = 0; j < k; j++) {
            cost += abs(window[j] - median);
        }
        
        cout << cost;
        if(i != n-k) cout << " ";
    }
    return 0;
}