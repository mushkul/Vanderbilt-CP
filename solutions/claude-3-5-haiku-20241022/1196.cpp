#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

void dijkstra(int n, vector<vector<pair<int, int>>>& graph, vector<vector<long long>>& distances, int k) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if (dist > distances[node][k-1]) continue;

        for (auto [next, edge_cost] : graph[node]) {
            long long new_dist = dist + edge_cost;

            if (new_dist < distances[next][k-1]) {
                distances[next][k-1] = new_dist;
                sort(distances[next].begin(), distances[next].end());
                pq.push({new_dist, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    vector<vector<long long>> distances(n + 1, vector<long long>(k, INF));
    distances[1][0] = 0;

    dijkstra(n, graph, distances, k);

    for (int i = 0; i < k; i++) {
        cout << distances[n][i] << " ";
    }
    cout << "\n";

    return 0;
}