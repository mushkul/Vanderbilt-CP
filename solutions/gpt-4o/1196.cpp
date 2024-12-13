#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<ll> shortestPaths;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, 1);
    vector<int> pathCount(n + 1, 0);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (u == n) {
            shortestPaths.push_back(cost);
            if (shortestPaths.size() == k) break;
        }

        if (++pathCount[u] > k) continue;

        for (auto &[v, w] : adj[u]) {
            pq.emplace(cost + w, v);
        }
    }

    for (auto price : shortestPaths) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}