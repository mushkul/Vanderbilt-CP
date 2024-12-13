#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Line {
    ll x1, y1, x2, y2;
    bool isHorizontal;
};

int main() {
    int n;
    cin >> n;
    
    vector<Line> lines(n);
    for(int i = 0; i < n; i++) {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
        lines[i].isHorizontal = (lines[i].y1 == lines[i].y2);
        if(lines[i].x1 > lines[i].x2) {
            swap(lines[i].x1, lines[i].x2);
        }
        if(lines[i].y1 > lines[i].y2) {
            swap(lines[i].y1, lines[i].y2);
        }
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(lines[i].isHorizontal != lines[j].isHorizontal) {
                Line h = lines[i].isHorizontal ? lines[i] : lines[j];
                Line v = lines[i].isHorizontal ? lines[j] : lines[i];
                
                if(v.x1 >= h.x1 && v.x1 <= h.x2 && 
                   h.y1 >= v.y1 && h.y1 <= v.y2) {
                    ans++;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}