#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Event {
    ll x, y1, y2, type;
    bool operator<(const Event& e) const {
        return x < e.x;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<Event> events;
    for(int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1, y1, y2, 1});
        events.push_back({x2, y1, y2, -1});
    }
    
    sort(events.begin(), events.end());
    
    map<ll, ll> active;
    ll prev_x = events[0].x;
    ll area = 0;
    
    for(const Event& e : events) {
        ll curr_x = e.x;
        
        ll covered = 0;
        ll prev_y = -1e9;
        for(auto it = active.begin(); it != active.end(); it++) {
            if(it->second > 0) {
                covered += max(0LL, it->first - prev_y);
            }
            prev_y = it->first;
        }
        
        area += covered * (curr_x - prev_x);
        
        active[e.y1] += e.type;
        if(active[e.y1] == 0) active.erase(e.y1);
        active[e.y2] += e.type;
        if(active[e.y2] == 0) active.erase(e.y2);
        
        prev_x = curr_x;
    }
    
    cout << area << "\n";
    return 0;
}