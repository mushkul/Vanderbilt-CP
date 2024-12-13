#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Range {
    int start, end, index;
};

bool contains(const Range &a, const Range &b) {
    return a.start <= b.start && a.end >= b.end;
}

bool operator<(const Range &a, const Range &b) {
    if (a.start != b.start) return a.start < b.start;
    return a.end > b.end;
}

int main() {
    int n;
    cin >> n;
    
    vector<Range> ranges(n);
    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].index = i;
    }
    
    sort(ranges.begin(), ranges.end());
    
    vector<int> contains_other(n, 0), contained_by_another(n, 0);
    
    int current_max = -1;
    for (int i = 0; i < n; ++i) {
        if (ranges[i].end <= current_max) {
            contained_by_another[ranges[i].index] = 1;
        } else {
            current_max = ranges[i].end;
        }
    }
    
    current_max = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (ranges[i].end >= current_max) {
            if (i < n - 1 && ranges[i].start == ranges[i + 1].start) {
                contains_other[ranges[i].index] = contains_other[ranges[i + 1].index];
            }
            current_max = ranges[i].end;
        } else {
            contains_other[ranges[i].index] = 1;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << contains_other[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << contained_by_another[i] << " ";
    }
    cout << "\n";
    
    return 0;
}