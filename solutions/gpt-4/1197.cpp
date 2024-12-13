#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int source, destination, weight;
};

constexpr int INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& e : edges)
        cin >> e.source >> e.destination >> e.weight, --e.source, --e.destination;

    vector<int64_t> distance(n, INF);
    vector<int> parent(n, -1);
    int cycle_end = -1;
    for (int iteration = 0; iteration < n; ++iteration) {
        cycle_end = -1;
        for (auto& e : edges) {
            if (distance[e.source] + e.weight < distance[e.destination]) {
                distance[e.destination] = distance[e.source] + e.weight;
                parent[e.destination] = e.source;
                cycle_end = e.destination;
            }
        }
    }

    if (cycle_end == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cycle_end = parent[cycle_end];

        vector<int> cycle;
        for (int current = cycle_end;; current = parent[current]) {
            cycle.push_back(current);
            if (current == cycle_end and cycle.size() > 1)
                break;
        }
        reverse(begin(cycle), end(cycle));

        for (auto v : cycle)
            cout << v+1 << ' ';
        cout << '\n';
    }

    return 0;
}