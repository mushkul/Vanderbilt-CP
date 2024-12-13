#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cross(pair<ll,ll> a, pair<ll,ll> b) {
    return a.first * b.second - a.second * b.first;
}

int orientation(pair<ll,ll> p, pair<ll,ll> q, pair<ll,ll> r) {
    ll val = (q.second - p.second) * (r.first - q.first) - 
             (q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

bool onSegment(pair<ll,ll> p, pair<ll,ll> q, pair<ll,ll> r) {
    return q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
           q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second);
}

bool intersect(pair<ll,ll> p1, pair<ll,ll> q1, pair<ll,ll> p2, pair<ll,ll> q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(intersect({x1,y1}, {x2,y2}, {x3,y3}, {x4,y4})) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}