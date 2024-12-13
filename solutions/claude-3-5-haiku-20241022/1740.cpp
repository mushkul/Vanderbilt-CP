#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    bool horizontal;
    int coord1, coord2, fixed;
    Line(int x1, int y1, int x2, int y2) {
        horizontal = (y1 == y2);
        if (horizontal) {
            fixed = y1;
            coord1 = min(x1, x2);
            coord2 = max(x1, x2);
        } else {
            fixed = x1;
            coord1 = min(y1, y2);
            coord2 = max(y1, y2);
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<Line> lines;
    
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.emplace_back(x1, y1, x2, y2);
    }
    
    int intersections = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lines[i].horizontal != lines[j].horizontal) {
                Line& h = lines[i].horizontal ? lines[i] : lines[j];
                Line& v = lines[i].horizontal ? lines[j] : lines[i];
                
                if (h.coord1 <= v.fixed && v.fixed <= h.coord2 &&
                    v.coord1 <= h.fixed && h.fixed <= v.coord2) {
                    intersections++;
                }
            }
        }
    }
    
    cout << intersections << endl;
    return 0;
}