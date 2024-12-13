#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> tasks;
    
    for(int i=0; i<n; i++) {
        int dur, dead;
        cin >> dur >> dead;
        tasks.push_back({dur,dead});
    }
    
    sort(tasks.begin(), tasks.end());
    
    ll time = 0;
    ll reward = 0;
    
    for(int i=0; i<n; i++) {
        time += tasks[i].first;
        reward += tasks[i].second - time;
    }
    
    cout << reward << endl;
    return 0;
}