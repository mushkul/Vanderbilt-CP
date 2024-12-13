#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, pair<int, int>>> ranges(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second.first;
        ranges[i].second.second = i;
    }
    
    sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
        return a.first < b.first || 
               (a.first == b.first && a.second.first > b.second.first);
    });
    
    vector<int> contains(n, 0);
    vector<int> contained(n, 0);
    
    int maxRight = ranges[0].second.first;
    
    for (int i = 1; i < n; i++) {
        if (ranges[i].second.first <= maxRight) {
            contained[ranges[i].second.second] = 1;
            contains[ranges[0].second.second] = 1;
        }
        maxRight = max(maxRight, ranges[i].second.first);
    }
    
    sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
        return a.first > b.first || 
               (a.first == b.first && a.second.first < b.second.first);
    });
    
    maxRight = ranges[0].second.first;
    
    for (int i = 1; i < n; i++) {
        if (maxRight <= ranges[i].second.first) {
            contains[ranges[i].second.second] = 1;
            contained[ranges[0].second.second] = 1;
        }
        maxRight = min(maxRight, ranges[i].second.first);
    }
    
    for (int x : contains) cout << x << " ";
    cout << endl;
    for (int x : contained) cout << x << " ";
    
    return 0;
}