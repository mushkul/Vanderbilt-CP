#include<bits/stdc++.h>
using namespace std;
#define double long double
#define fi first
#define se second

typedef pair<double, double> dd;

const int MAX = 1e9;
const double eps = 1e-9;
vector<dd> hull;

dd operator - (dd a, dd b) { return {a.fi - b.fi, a.se - b.se}; }
double cross(dd a, dd b) { return a.fi * b.se - a.se * b.fi; }
double cross(dd a, dd b, dd c) { return cross(b - a, c - a); }

bool inConvexPolygon(dd a) {
    int n = hull.size();
    if (cross(hull[0], hull[1], a) < -eps || cross(hull[0], hull[n-1], a) > eps) return 0;

    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (cross(hull[0], hull[mid], a) < -eps) r = mid;
        else l = mid;
    }

    if (fabs(cross(hull[0], hull[l], a)) < eps || fabs(cross(hull[l], hull[r], a)) < eps || fabs(cross(hull[r], a, hull[0])) < eps) return 2;
    return cross(hull[0], hull[l], hull[r]) > cross(hull[0], hull[l], a) + cross(hull[l], hull[r], a) + cross(hull[r], a, hull[0]) - eps;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    hull.resize(n+1);
    for (int i = 1; i <= n; ++i) cin >> hull[i].fi >> hull[i].se;
    hull[0] = hull[n];
    while (m--) {
        dd p; cin >> p.fi >> p.se;
        int res = inConvexPolygon(p);
        if (res == 0) cout << "OUTSIDE\n";
        else if (res == 1) cout << "INSIDE\n";
        else cout << "BOUNDARY\n";
    }
}