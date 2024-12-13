#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
    bool operator<(const Point &p) const {
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
};

ll cross(Point &a, Point &b, Point &c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(), points.end());
    int n = points.size();
    vector<Point> hull;
    
    for(int rep = 0; rep < 2; rep++) {
        int sz = hull.size();
        for(Point &p : points) {
            while(hull.size()-sz >= 2 && 
                  cross(hull[hull.size()-2], hull[hull.size()-1], p) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(points.begin(), points.end());
    }
    
    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<Point> points(n);
    
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Point> hull = convexHull(points);
    
    cout << hull.size() << "\n";
    for(Point &p : hull) {
        cout << p.x << " " << p.y << "\n";
    }
    
    return 0;
}