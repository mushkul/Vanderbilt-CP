#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll boundary_points(const vector<pair<ll, ll>>& points, int n) {
    ll boundary = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        ll dx = abs(points[j].first - points[i].first);
        ll dy = abs(points[j].second - points[i].second);
        boundary += gcd(dx, dy);
    }
    return boundary;
}

ll area_twice(const vector<pair<ll, ll>>& points, int n) {
    ll area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += points[i].first * points[j].second - points[j].first * points[i].second;
    }
    return abs(area);
}

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    ll b = boundary_points(points, n);
    ll a2 = area_twice(points, n);
    ll i = (a2 - b + 2) / 2;

    cout << i << " " << b << endl;

    return 0;
}