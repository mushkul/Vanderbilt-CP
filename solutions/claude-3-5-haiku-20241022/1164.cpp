#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, pair<int, int>>> events;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, {0, i}});
        events.push_back({b, {1, i}});
    }
    
    sort(events.begin(), events.end());
    
    int rooms = 0, max_rooms = 0;
    set<int> available_rooms;
    vector<int> customer_rooms(n);
    
    for (auto& event : events) {
        int day = event.first;
        int type = event.second.first;
        int customer = event.second.second;
        
        if (type == 0) {
            if (!available_rooms.empty()) {
                customer_rooms[customer] = *available_rooms.begin();
                available_rooms.erase(available_rooms.begin());
            } else {
                rooms++;
                customer_rooms[customer] = rooms;
            }
            max_rooms = max(max_rooms, rooms);
        } else {
            available_rooms.insert(customer_rooms[customer]);
        }
    }
    
    cout << max_rooms << endl;
    for (int room : customer_rooms) {
        cout << room << " ";
    }
    
    return 0;
}