#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> x_coords, y_coords;
    
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x_coords.push_back({x1, 1});
        x_coords.push_back({x2, -1});
        y_coords.push_back({y1, 1});
        y_coords.push_back({y2, -1});
    }
    
    sort(x_coords.begin(), x_coords.end());
    sort(y_coords.begin(), y_coords.end());
    
    long long total_area = 0;
    for(int i = 1; i < x_coords.size(); i++) {
        for(int j = 1; j < y_coords.size(); j++) {
            int x_left = x_coords[i-1].first, x_right = x_coords[i].first;
            int y_bottom = y_coords[j-1].first, y_top = y_coords[j].first;
            
            int x_count = 0, y_count = 0;
            for(auto& p : x_coords) {
                if(p.first >= x_left && p.first <= x_right)
                    x_count += p.second;
            }
            for(auto& p : y_coords) {
                if(p.first >= y_bottom && p.first <= y_top)
                    y_count += p.second;
            }
            
            if(x_count > 0 && y_count > 0) {
                total_area += 1LL * (x_right - x_left) * (y_top - y_bottom);
            }
        }
    }
    
    cout << total_area << endl;
    return 0;
}