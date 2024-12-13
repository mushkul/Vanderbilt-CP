#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    bool operator < (const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

long long cross_product(const Point &o, const Point &a, const Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<Point> convex_hull(vector<Point> &points) {
    int n = points.size();
    if (n <= 1) return points;
    
    sort(points.begin(), points.end());
    
    vector<Point> hull;
    
    // Lower hull
    for (const Point &p : points) {
        while (hull.size() >= 2) {
            Point &a = hull[hull.size() - 2];
            Point &b = hull.back();
            if (cross_product(a, b, p) > 0) break;
            hull.pop_back();
        }
        hull.push_back(p);
    }
    
    // Upper hull
    int t = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        const Point &p = points[i];
        while (hull.size() >= t + 1) {
            Point &a = hull[hull.size() - 2];
            Point &b = hull.back();
            if (cross_product(a, b, p) > 0) break;
            hull.pop_back();
        }
        hull.push_back(p);
    }
    
    hull.pop_back();
    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<Point> hull = convex_hull(points);
    
    cout << hull.size() << "\n";
    for (const Point &p : hull) {
        cout << p.x << " " << p.y << "\n";
    }
    
    return 0;
}