#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point {
    ll x, y;
    bool operator<(const Point &p) {
        return x < p.x || (x == p.x && y < p.y);
    }
};
Point points[200005];
vector<Point> hull;
    
ll cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> points[i].x >> points[i].y;
        
    sort(points, points + n);
    for (int i=0; i<n; i++) {
        while(hull.size() >= 2 && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    for (int i=n-2, t=hull.size()+1; i>=0; i--) {
        while(hull.size() >= t && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) <= 0)
            hull.pop_back();
            hull.push_back(points[i]);
    }
    hull.pop_back();
        
    cout << hull.size() << "\n";
    for(auto &point : hull)
        cout << point.x << " " << point.y << "\n";
    
    return 0;
}