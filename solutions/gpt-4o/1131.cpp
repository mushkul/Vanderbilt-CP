#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int start, const vector<vector<int>>& adj, int& farthest) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int maxDist = 0;
    farthest = start;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > maxDist) {
                    maxDist = dist[neighbor];
                    farthest = neighbor;
                }
            }
        }
    }
    return maxDist;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int farthest;
    bfs(1, adj, farthest);
    int diameter = bfs(farthest, adj, farthest);

    cout << diameter << endl;

    return 0;
}