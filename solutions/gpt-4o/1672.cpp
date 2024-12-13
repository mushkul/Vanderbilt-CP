#include <iostream>
#include <vector>
#include <algorithm>

const long long INF = 1e18;

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector<std::vector<long long>> dist(n+1, std::vector<long long>(n+1, INF));

    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        dist[a][b] = std::min(dist[a][b], (long long)c);
        dist[b][a] = std::min(dist[b][a], (long long)c);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

    while (q--) {
        int a, b;
        std::cin >> a >> b;
        if (dist[a][b] < INF)
            std::cout << dist[a][b] << "\n";
        else
            std::cout << -1 << "\n";
    }

    return 0;
}