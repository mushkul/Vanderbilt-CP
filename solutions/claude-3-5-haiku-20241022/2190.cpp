#include <bits/stdc++.h>
using namespace std;

int sign(long long val) {
    return (val > 0) - (val < 0);
}

int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    long long val = (long long)(y2 - y1) * (x3 - x2) - (long long)(x2 - x1) * (y3 - y2);
    return sign(val);
}

bool on_segment(int x1, int y1, int x2, int y2, int x3, int y3) {
    return min(x1, x2) <= x3 && x3 <= max(x1, x2) &&
           min(y1, y2) <= y3 && y3 <= max(y1, y2);
}

bool segments_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int o1 = orientation(x1, y1, x2, y2, x3, y3);
    int o2 = orientation(x1, y1, x2, y2, x4, y4);
    int o3 = orientation(x3, y3, x4, y4, x1, y1);
    int o4 = orientation(x3, y3, x4, y4, x2, y2);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && on_segment(x1, y1, x2, y2, x3, y3)) return true;
    if (o2 == 0 && on_segment(x1, y1, x2, y2, x4, y4)) return true;
    if (o3 == 0 && on_segment(x3, y3, x4, y4, x1, y1)) return true;
    if (o4 == 0 && on_segment(x3, y3, x4, y4, x2, y2)) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        cout << (segments_intersect(x1, y1, x2, y2, x3, y3, x4, y4) ? "YES" : "NO") << "\n";
    }

    return 0;
}