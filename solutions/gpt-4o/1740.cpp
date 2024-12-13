#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Segment {
    int x1, y1, x2, y2;
};

int main() {
    int n;
    cin >> n;
    vector<Segment> h_segments, v_segments;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) h_segments.push_back(Segment{x1, y1, x2, y2});
        else v_segments.push_back(Segment{x1, y1, x2, y2});
    }

    map<int, vector<pair<int, int>>> y_to_hseg;
    for (auto &seg : h_segments) {
        y_to_hseg[seg.y1].emplace_back(seg.x1, seg.x2);
    }

    int intersections = 0;
    for (auto &seg : v_segments) {
        if (y_to_hseg.count(seg.y1)) {
            for (auto &hseg : y_to_hseg[seg.y1]) {
                if (hseg.first <= seg.x1 && seg.x1 <= hseg.second) {
                    intersections++;
                }
            }
        }
    }

    cout << intersections << endl;
    return 0;
}