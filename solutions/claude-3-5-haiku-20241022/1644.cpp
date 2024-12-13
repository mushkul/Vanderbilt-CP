#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<ll> arr(n+1);
    vector<ll> pref(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }
    
    ll ans = LLONG_MIN;
    deque<pair<ll, int>> dq;
    
    for (int i = a; i <= n; i++) {
        while (!dq.empty() && dq.front().second < i - b) {
            dq.pop_front();
        }
        
        while (!dq.empty() && dq.back().first > pref[i-a]) {
            dq.pop_back();
        }
        
        dq.push_back({pref[i-a], i-a});
        
        ll curr = pref[i] - dq.front().first;
        ans = max(ans, curr);
    }
    
    cout << ans << endl;
    
    return 0;
}