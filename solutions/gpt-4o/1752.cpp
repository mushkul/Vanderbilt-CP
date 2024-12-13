#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist1(n + 1, -1), dist2(n + 1, -1);

    auto bfs = [&](int start, vector<int>& dist) {
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthest = start;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > dist[farthest]) {
                        farthest = neighbor;
                    }
                }
            }
        }
        return farthest;
    };

    int farthest1 = bfs(1, dist1);
    int farthest2 = bfs(farthest1, dist1);
    bfs(farthest2, dist2);

    set<int> offices;
    for (int i = 1; i <= n; ++i) {
        if (max(dist1[i], dist2[i]) >= d / 2) {
            offices.insert(i);
        }
    }

    cout << offices.size() << endl;
    for (int office : offices) {
        cout << office << " ";
    }
    cout << endl;

    return 0;
}