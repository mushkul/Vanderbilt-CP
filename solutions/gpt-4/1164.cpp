#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i].first >> arr[i].second;
        arr[i].second = -arr[i].second;
        arr[i].first = -arr[i].first;
    }
    sort(arr.begin(), arr.end());

    multiset<int> departures;
    vector<int> room(n);

    for(int i = 0; i < n; ++i){
        auto it = departures.upper_bound(-arr[i].second);
        if(it == departures.begin()){
            room[i] = departures.size() + 1;
        } else {
            --it;
            room[i] = *it;
            departures.erase(it);
        }
        departures.insert(room[i]);
    }

    cout << departures.size() << "\n";
    for(int x : room)
        cout << x << " ";
}