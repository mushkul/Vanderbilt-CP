#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
    bool operator<(const Point &p) const {
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
};

ll dist(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); 
}

ll solve(vector<Point> &points, int l, int r) {
    if(r-l <= 3) {
        ll minDist = LLONG_MAX;
        for(int i = l; i < r; i++)
            for(int j = i+1; j < r; j++)
                minDist = min(minDist, dist(points[i], points[j]));
        return minDist;
    }
    
    int mid = (l+r)/2;
    ll midx = points[mid].x;
    ll d1 = solve(points, l, mid);
    ll d2 = solve(points, mid, r);
    ll d = min(d1, d2);
    
    vector<Point> strip;
    for(int i = l; i < r; i++) {
        if((points[i].x - midx)*(points[i].x - midx) < d)
            strip.push_back(points[i]);
    }
    
    sort(strip.begin(), strip.end(), 
         [](const Point &a, const Point &b) {
             return a.y < b.y;
         });
             
    for(int i = 0; i < strip.size(); i++) {
        for(int j = i+1; j < strip.size() && j-i < 8; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    
    return d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end());
    cout << solve(points, 0, n) << "\n";
    
    return 0;
}