#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Project {
    int start, end, reward;
};

int main() {
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    
    sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
        return a.end < b.end;
    });
    
    map<int, long long> dp;
    dp[0] = 0;
    
    for (const auto &project : projects) {
        auto it = dp.upper_bound(project.start);
        --it;
        long long current_reward = it->second + project.reward;
        if (current_reward > dp.rbegin()->second) {
            dp[project.end] = current_reward;
        }
    }
    
    cout << dp.rbegin()->second << endl;
    
    return 0;
}