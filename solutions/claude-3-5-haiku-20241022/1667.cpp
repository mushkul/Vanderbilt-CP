#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, 0);
    queue<int> q;
    q.push(1);
    dist[1] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == n) break;

        for (int next : graph[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                parent[next] = curr;
                q.push(next);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << dist[n] << endl;
    
    vector<int> path;
    int current = n;
    while (current != 0) {
        path.push_back(current);
        current = parent[current];
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}