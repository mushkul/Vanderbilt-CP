#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;

struct State {
    ll time;
    int level;
    int skill_factor;
    bool operator>(const State &other) const {
        return time > other.time;
    }
};

int main() {
    int n, initial_x;
    cin >> n >> initial_x;
    vector<int> s(n), f(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> f[i];

    vector<ll> min_time(n, LLONG_MAX);
    priority_queue<State, vector<State>, greater<State>> pq;

    pq.push({0, 0, initial_x});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.level == n - 1) {
            min_time[n - 1] = min(min_time[n - 1], current.time + 1LL * s[n - 1] * current.skill_factor);
            continue;
        }

        if (current.time >= min_time[current.level]) continue;
        min_time[current.level] = current.time;

        // Option 1: Kill the monster on this level
        ll new_time = current.time + 1LL * s[current.level] * current.skill_factor;
        if (new_time < min_time[current.level + 1]) {
            pq.push({new_time, current.level + 1, f[current.level]});
        }

        // Option 2: Escape the monster on this level
        if (current.level + 1 < n) {
            if (current.time < min_time[current.level + 1]) {
                pq.push({current.time, current.level + 1, current.skill_factor});
            }
        }
    }

    cout << min_time[n - 1] << endl;
    return 0;
}