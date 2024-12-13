#include <bits/stdc++.h>
using namespace std;
#define ll long long

const double EPS = 1e-9;

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
};

int sign(ll x) {
    return (x > 0) - (x < 0);
}

ll cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool onSegment(Point p, Point a, Point b) {
    return cross(p, a, b) == 0 && 
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

string pointInPolygon(vector<Point>& poly, Point p) {
    int n = poly.size();
    bool on_boundary = false;
    
    for(int i = 0; i < n; i++) {
        Point cur = poly[i];
        Point next = poly[(i + 1) % n];
        
        if(onSegment(p, cur, next)) {
            return "BOUNDARY";
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        Point cur = poly[i];
        Point next = poly[(i + 1) % n];
        
        if(cur.y <= p.y) {
            if(next.y > p.y && cross(cur, next, p) > 0)
                cnt++;
        }
        else {
            if(next.y <= p.y && cross(cur, next, p) < 0)
                cnt--;
        }
    }
    
    return cnt != 0 ? "INSIDE" : "OUTSIDE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<Point> polygon(n);
    for(int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    
    while(m--) {
        Point p;
        cin >> p.x >> p.y;
        cout << pointInPolygon(polygon, p) << "\n";
    }
    
    return 0;
}