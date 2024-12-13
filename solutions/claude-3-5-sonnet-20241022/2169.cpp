#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Range {
    int x, y, idx;
    bool operator<(const Range& r) const {
        if (x != r.x) return x < r.x;
        return y > r.y;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].idx = i;
    }

    vector<int> contains(n), contained(n);
    
    sort(ranges.begin(), ranges.end());
    
    vector<pair<int,int>> ends;
    for (int i = 0; i < n; i++) {
        ends.push_back({ranges[i].y, ranges[i].idx});
    }
    
    // Count ranges contained by each range
    set<pair<int,int>> active;
    for (int i = 0; i < n; i++) {
        while (!active.empty() && active.begin()->first < ranges[i].y) {
            contains[ranges[i].idx]++;
            active.erase(active.begin());
        }
        active.insert({ranges[i].y, ranges[i].idx});
    }
    
    // Count ranges that contain each range
    sort(ranges.begin(), ranges.end(), [](Range a, Range b) {
        if (a.x != b.x) return a.x > b.x;
        return a.y < b.y;
    });
    
    active.clear();
    for (int i = 0; i < n; i++) {
        while (!active.empty() && active.begin()->first > ranges[i].y) {
            contained[ranges[i].idx]++;
            active.erase(active.begin());
        }
        active.insert({ranges[i].y, ranges[i].idx});
    }
    
    for (int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << contained[i] << " ";
    }
    
    return 0;
}