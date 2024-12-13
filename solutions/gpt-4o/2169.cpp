#include <bits/stdc++.h>
using namespace std;

struct Range {
    int start, end, index;
    bool operator<(const Range &other) const {
        if (start != other.start) return start < other.start;
        return end > other.end;
    }
};

int main() {
    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }
    
    sort(ranges.begin(), ranges.end());
    
    vector<int> contains(n), contained(n);
    set<pair<int, int>> endPoints; // {end, index}
    
    for (int i = 0; i < n; ++i) {
        auto it = endPoints.lower_bound({ranges[i].end + 1, 0});
        contains[ranges[i].index] = distance(it, endPoints.end());
        endPoints.insert({ranges[i].end, ranges[i].index});
    }
    
    endPoints.clear();
    
    for (int i = n - 1; i >= 0; --i) {
        auto it = endPoints.lower_bound({ranges[i].end, 0});
        contained[ranges[i].index] = distance(endPoints.begin(), it);
        endPoints.insert({ranges[i].end, ranges[i].index});
    }
    
    for (int i = 0; i < n; ++i) {
        cout << contains[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; ++i) {
        cout << contained[i] << " ";
    }
    cout << endl;
    
    return 0;
}