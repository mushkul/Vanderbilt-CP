#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll x, n;
    cin >> x >> n;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    
    for(int i = 0; i < n; i++) {
        ll d;
        cin >> d;
        pq.push(d);
    }
    
    ll cost = 0;
    while(pq.size() > 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    
    cout << cost << '\n';
    
    return 0;
}