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
    
    ll ans = LLONG_MAX;
    
    for(int peak = 0; peak < n; peak++) {
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({a[i], i});
        }
        
        vector<int> target(n);
        int idx = 0;
        for(int i = 0; i <= peak; i++) {
            target[i] = idx++;
        }
        for(int i = peak+1; i < n; i++) {
            target[i] = n-1-(i-peak-1);
        }
        
        sort(v.begin(), v.end());
        vector<int> pos(n);
        for(int i = 0; i < n; i++) {
            pos[i] = v[i].second;
        }
        
        ll swaps = 0;
        vector<bool> vis(n);
        for(int i = 0; i < n; i++) {
            if(vis[i] || pos[i] == target[i]) continue;
            
            int cycle_size = 0;
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = target[j];
                cycle_size++;
            }
            swaps += cycle_size-1;
        }
        
        ans = min(ans, swaps);
    }
    
    cout << ans << "\n";
    
    return 0;
}