#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Event {
    int time;
    int index;
    bool isArrival;
    bool operator<(const Event& other) const {
        // First, sort by time, then by type (departure before arrival)
        return time < other.time || (time == other.time && !isArrival && other.isArrival);
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, i, true});
        events.push_back({b, i, false});
    }

    sort(events.begin(), events.end());

    vector<int> roomNumber(n);
    priority_queue<int, vector<int>, greater<int>> availableRooms;
    int currentRoom = 0, maxRooms = 0;

    for (auto& event : events) {
        if (event.isArrival) {
            int room;
            if (availableRooms.empty()) {
                room = ++currentRoom;
            } else {
                room = availableRooms.top();
                availableRooms.pop();
            }
            roomNumber[event.index] = room;
            maxRooms = max(maxRooms, room);
        } else {
            availableRooms.push(roomNumber[event.index]);
        }
    }

    cout << maxRooms << '\n';
    for (int i = 0; i < n; ++i) {
        cout << roomNumber[i] << ' ';
    }
    cout << '\n';

    return 0;
}