#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cross(pair<ll,ll> p1, pair<ll,ll> p2) {
    return p1.first * p2.second - p1.second * p2.first;
}

ll countBoundaryPoints(pair<ll,ll> p1, pair<ll,ll> p2) {
    ll x = abs(p1.first - p2.first);
    ll y = abs(p1.second - p2.second);
    return __gcd(x, y) + 1;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> points(n);
    
    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    ll area = 0;
    ll boundary = 0;
    
    for(int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += cross(points[i], points[j]);
        boundary += countBoundaryPoints(points[i], points[j]) - 1;
    }
    
    area = abs(area);
    
    ll interior = (area - boundary + 2) / 2;
    
    cout << interior << " " << boundary << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}