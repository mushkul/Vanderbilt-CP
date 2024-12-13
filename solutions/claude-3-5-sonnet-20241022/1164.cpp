#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    
    sort(v.begin(), v.end());
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> rooms(n);
    int room = 0;
    
    for(int i=0; i<n; i++) {
        if(pq.empty()) {
            room++;
            pq.push({v[i].first.second, room});
            rooms[v[i].second] = room;
        }
        else {
            pair<int,int> curr = pq.top();
            if(curr.first < v[i].first.first) {
                pq.pop();
                pq.push({v[i].first.second, curr.second});
                rooms[v[i].second] = curr.second;
            }
            else {
                room++;
                pq.push({v[i].first.second, room});
                rooms[v[i].second] = room;
            }
        }
    }
    
    cout << room << "\n";
    for(int i=0; i<n; i++) {
        cout << rooms[i] << " ";
    }
    
    return 0;
}