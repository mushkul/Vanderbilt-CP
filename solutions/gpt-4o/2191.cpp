#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll polygon_area_2x(const vector<pll>& vertices) {
    int n = vertices.size();
    ll area = 0;
    for (int i = 0; i < n; i++) {
        ll x1 = vertices[i].first, y1 = vertices[i].second;
        ll x2 = vertices[(i + 1) % n].first, y2 = vertices[(i + 1) % n].second;
        area += x1 * y2 - x2 * y1;
    }
    return abs(area);
}

int main() {
    int n;
    cin >> n;
    vector<pll> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }
    cout << polygon_area_2x(vertices) << endl;
    return 0;
}