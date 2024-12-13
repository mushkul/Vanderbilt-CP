#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll cross_product(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c) {
    return (b.first - a.first) * (c.second - a.second) - 
           (b.second - a.second) * (c.first - a.first);
}

ll boundary_points(vector<pair<ll,ll>>& polygon) {
    ll boundary = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        auto p1 = polygon[i];
        auto p2 = polygon[(i+1)%n];
        boundary += gcd(abs(p2.first - p1.first), abs(p2.second - p1.second));
    }
    return boundary;
}

ll area_2x(vector<pair<ll,ll>>& polygon) {
    ll area = 0;
    int n = polygon.size();
    for (int i = 0; i < n; i++) {
        area += polygon[i].first * polygon[(i+1)%n].second - 
                polygon[i].second * polygon[(i+1)%n].first;
    }
    return abs(area);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll,ll>> polygon(n);
    
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].first >> polygon[i].second;
    }
    
    ll area = area_2x(polygon);
    ll boundary = boundary_points(polygon);
    ll interior = (area - boundary + 2) / 2;
    
    cout << interior << " " << boundary << "\n";
    
    return 0;
}