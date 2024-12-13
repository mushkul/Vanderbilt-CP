#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

struct Segment {
    Point p, q;
};

int ccw(Point a, Point b, Point c) {
    ll cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

bool intersect(Segment a, Segment b) {
    return ccw(a.p, a.q, b.p) * ccw(a.p, a.q, b.q) <= 0
        && ccw(b.p, b.q, a.p) * ccw(b.p, b.q, a.q) <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        Segment a, b;
        cin >> a.p.x >> a.p.y >> a.q.x >> a.q.y;
        cin >> b.p.x >> b.p.y >> b.q.x >> b.q.y;
        cout << (intersect(a, b) ? "YES" : "NO") << '\n';
    }
    return 0;
}