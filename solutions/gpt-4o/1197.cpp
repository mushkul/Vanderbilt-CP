#include <iostream>
#include <vector>
#include <limits>

const long long INF = std::numeric_limits<long long>::max();

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, long long>> edges;
    std::vector<long long> dist(n + 1, INF);
    std::vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    int x = -1;
    dist[1] = 0;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto &[a, b, c] : edges) {
            if (dist[a] != INF && dist[b] > dist[a] + c) {
                dist[b] = dist[a] + c;
                parent[b] = a;
                x = b;
            }
        }
    }

    if (x == -1) {
        std::cout << "NO\n";
    } else {
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }
        std::vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        std::reverse(cycle.begin(), cycle.end());

        std::cout << "YES\n";
        for (int v : cycle) {
            std::cout << v << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}