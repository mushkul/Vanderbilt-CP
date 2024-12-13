#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> games;

    for (int i = 0; i < n; ++i) {
        if (x[i] > 0) {
            pq.push({x[i], i + 1});
        }
    }

    while (pq.size() >= 2) {
        auto p1 = pq.top(); pq.pop();
        auto p2 = pq.top(); pq.pop();
        games.push_back({p1.second, p2.second});
        p1.first--;
        p2.first--;
        if (p1.first > 0) {
            pq.push(p1);
        }
        if (p2.first > 0) {
            pq.push(p2);
        }
    }

    if (games.size() != accumulate(x.begin(), x.end(), 0) / 2) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << games.size() << endl;
        for (auto &game : games) {
            cout << game.first << " " << game.second << endl;
        }
    }

    return 0;
}