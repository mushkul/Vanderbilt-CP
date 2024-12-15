#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to;
    long long weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<long long> dist(n + 1, numeric_limits<long long>::min());

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    dist[1] = 0;
    for (int i = 1; i < n; ++i) {
        for (const auto& e : edges) {
            if (dist[e.from] != numeric_limits<long long>::min() && 
                dist[e.from] + e.weight > dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }

    vector<bool> reachable(n + 1, false);
    reachable[n] = true;
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& e : edges) {
            if (reachable[e.to]) {
                reachable[e.from] = true;
            }
        }
    }

    for (const auto& e : edges) {
        if (dist[e.from] != numeric_limits<long long>::min() &&
            dist[e.from] + e.weight > dist[e.to]) {
            if (reachable[e.to]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << dist[n] << endl;

    return 0;
}