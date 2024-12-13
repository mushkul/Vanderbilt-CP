#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll cross_product(ll x1, ll y1, ll x2, ll y2) {
    return x1 * y2 - y1 * x2;
}

bool on_segment(ll x1, ll y1, ll x2, ll y2, ll x, ll y) {
    return min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2);
}

bool check_intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll d1 = cross_product(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
    ll d2 = cross_product(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
    ll d3 = cross_product(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    ll d4 = cross_product(x2 - x1, y2 - y1, x4 - x1, y4 - y1);

    if ((d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) && (d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0))
        return true;

    if (d1 == 0 && on_segment(x3, y3, x4, y4, x1, y1)) return true;
    if (d2 == 0 && on_segment(x3, y3, x4, y4, x2, y2)) return true;
    if (d3 == 0 && on_segment(x1, y1, x2, y2, x3, y3)) return true;
    if (d4 == 0 && on_segment(x1, y1, x2, y2, x4, y4)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (check_intersect(x1, y1, x2, y2, x3, y3, x4, y4))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}