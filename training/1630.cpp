#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());

    long long currentTime = 0, totalReward = 0;
    for (const auto &task : tasks) {
        int duration = task.first, deadline = task.second;
        currentTime += duration;
        totalReward += deadline - currentTime;
    }
    
    cout << totalReward << '\n';
    return 0;
}