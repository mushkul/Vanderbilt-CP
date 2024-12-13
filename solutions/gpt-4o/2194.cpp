#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> Point;

bool compareY(const Point &a, const Point &b) {
    return a.second < b.second;
}

ll distSquared(const Point &a, const Point &b) {
    return (ll)(a.first - b.first) * (a.first - b.first) + (ll)(a.second - b.second) * (a.second - b.second);
}

ll closestPair(vector<Point> &points, int left, int right) {
    if (right - left <= 3) {
        ll minDist = LLONG_MAX;
        for (int i = left; i < right; ++i) {
            for (int j = i + 1; j < right; ++j) {
                minDist = min(minDist, distSquared(points[i], points[j]));
            }
        }
        sort(points.begin() + left, points.begin() + right, compareY);
        return minDist;
    }

    int mid = (left + right) / 2;
    int midX = points[mid].first;
    ll d = min(closestPair(points, left, mid), closestPair(points, mid, right));

    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if ((ll)(points[i].first - midX) * (points[i].first - midX) < d) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (ll)(strip[j].second - strip[i].second) * (strip[j].second - strip[i].second) < d; ++j) {
            d = min(d, distSquared(strip[i], strip[j]));
        }
    }

    return d;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    cout << closestPair(points, 0, n) << endl;
    return 0;
}