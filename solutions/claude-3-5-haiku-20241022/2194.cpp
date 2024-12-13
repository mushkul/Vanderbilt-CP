#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    int min_dist_squared = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            int dist_squared = dx * dx + dy * dy;
            min_dist_squared = min(min_dist_squared, dist_squared);
        }
    }
    
    cout << min_dist_squared << endl;
    
    return 0;
}