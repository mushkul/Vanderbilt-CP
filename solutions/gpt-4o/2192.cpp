#include <iostream>
#include <vector>

using namespace std;

struct Point {
    long long x, y;
};

// Check if the point q lies on the segment pr
bool onSegment(Point p, Point q, Point r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

// To find orientation of ordered triplet (p, q, r).
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) -
                    (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Function to check if two segments (p1,q1) and (p2,q2) intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
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

// Returns true if the point p lies inside the polygon
string isInsidePolygon(vector<Point>& polygon, int n, Point p) {
    if (n < 3) return "OUTSIDE";

    Point extreme = {1e9 + 1, p.y};
    int count = 0, i = 0;

    do {
        int next = (i + 1) % n;
        if (doIntersect(polygon[i], polygon[next], p, extreme)) {
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]) ? "BOUNDARY" : "OUTSIDE";
            count++;
        }
        i = next;
    } while (i != 0);
    
    return (count % 2 == 1) ? "INSIDE" : "OUTSIDE";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    for (int i = 0; i < m; i++) {
        Point point;
        cin >> point.x >> point.y;
        cout << isInsidePolygon(polygon, n, point) << endl;
    }
    return 0;
}