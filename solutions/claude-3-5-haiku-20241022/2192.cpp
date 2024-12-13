#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

long long cross_product(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool on_segment(const Point& a, const Point& b, const Point& p) {
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool intersect(const Point& a, const Point& b, const Point& c, const Point& d) {
    long long cross1 = cross_product(a, b, c);
    long long cross2 = cross_product(a, b, d);
    long long cross3 = cross_product(c, d, a);
    long long cross4 = cross_product(c, d, b);

    if (cross1 * cross2 < 0 && cross3 * cross4 < 0) return true;
    if (cross1 == 0 && on_segment(a, b, c)) return true;
    if (cross2 == 0 && on_segment(a, b, d)) return true;
    if (cross3 == 0 && on_segment(c, d, a)) return true;
    if (cross4 == 0 && on_segment(c, d, b)) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    for (int j = 0; j < m; ++j) {
        Point p;
        cin >> p.x >> p.y;

        bool on_boundary = false;
        for (int i = 0; i < n; ++i) {
            Point a = polygon[i];
            Point b = polygon[(i + 1) % n];
            if (cross_product(a, b, p) == 0 && on_segment(a, b, p)) {
                on_boundary = true;
                break;
            }
        }

        if (on_boundary) {
            cout << "BOUNDARY\n";
            continue;
        }

        int intersections = 0;
        Point ray_end = {1000000001LL, p.y};

        for (int i = 0; i < n; ++i) {
            Point a = polygon[i];
            Point b = polygon[(i + 1) % n];
            if (intersect(p, ray_end, a, b)) {
                intersections++;
            }
        }

        cout << (intersections % 2 == 1 ? "INSIDE" : "OUTSIDE") << "\n";
    }

    return 0;
}