#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Event {
    int x, y1, y2, type;
    bool operator < (const Event& other) const {
        if (x == other.x) return type < other.type;
        return x < other.x;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Event> events;
    set<int> y_points;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
        y_points.insert(y1);
        y_points.insert(y2);
    }

    sort(events.begin(), events.end());
    vector<int> y_sorted(y_points.begin(), y_points.end());
    int m = y_sorted.size();
    vector<int> cnt(m, 0);
    
    auto get_y_index = [&](int y) {
        return lower_bound(y_sorted.begin(), y_sorted.end(), y) - y_sorted.begin();
    };

    long long area = 0;
    for (int i = 0; i < events.size(); ++i) {
        if (i > 0) {
            long long dx = events[i].x - events[i - 1].x;
            long long total_y_covered = 0;
            for (int j = 0; j < m - 1; ++j) {
                if (cnt[j] > 0) {
                    total_y_covered += (long long)(y_sorted[j + 1] - y_sorted[j]);
                }
            }
            area += dx * total_y_covered;
        }
        int y1_index = get_y_index(events[i].y1);
        int y2_index = get_y_index(events[i].y2);
        for (int j = y1_index; j < y2_index; ++j) {
            cnt[j] += events[i].type;
        }
    }

    cout << area << endl;
    return 0;
}