#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <climits>

using namespace std;

int main() {
    int n, initial_x;
    cin >> n >> initial_x;
    vector<int> s(n), f(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> f[i];
    
    using pi = pair<long long, int>;
    multiset<pi> currentLevel;
    currentLevel.insert({0, initial_x});  // Initial state, no time spent yet
    
    for (int i = 0; i < n; ++i) {
        long long strength = s[i];
        multiset<pi> nextLevel;
        
        for (auto [currentTime, currentSkill] : currentLevel) {
            // Option 1: Kill the monster
            long long timeToKill = currentTime + strength * currentSkill;
            nextLevel.insert({timeToKill, f[i]});
            
            // Option 2: Do not kill the monster (only if not the last level)
            if (i != n - 1) {
                nextLevel.insert({currentTime, currentSkill});
            }
        }
        
        // prune the levels to keep minimum time for each skill factor
        currentLevel.clear();
        vector<pi> sortedNextLevel(nextLevel.begin(), nextLevel.end());
        long long minTimeSoFar = LLONG_MAX;
        
        for (auto [time, skill] : sortedNextLevel) {
            if (time < minTimeSoFar) {
                minTimeSoFar = time;
                currentLevel.insert({time, skill});
            }
        }
    }

    long long result = LLONG_MAX;
    for (auto [time, _] : currentLevel) {
        result = min(result, time);
    }
    cout << result << endl;
    
    return 0;
}