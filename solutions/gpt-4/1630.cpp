#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, time = 0, reward = 0;
    cin >> n;
    vector<pair<long long, long long>> tasks(n);
    for(long long i=0; i<n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());
    for(long long i=0; i<n; i++) {
        time += tasks[i].first;
        reward += tasks[i].second - time;
    }
    cout << reward;
}