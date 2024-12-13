#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> dist1, dist2, maxDist;

void bfs(int start, vector<int> &dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    dist1.assign(n + 1, -1);
    dist2.assign(n + 1, -1);
    maxDist.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // First BFS from an arbitrary node (let's choose node 1)
    bfs(1, dist1);
    
    // Find the farthest node from node 1, call it u
    int farthest = 1;
    for (int i = 2; i <= n; ++i) {
        if (dist1[i] > dist1[farthest]) {
            farthest = i;
        }
    }
    
    // BFS from u
    bfs(farthest, dist2);
    
    // Find the farthest node from u, call it v
    int endPoint = 1;
    for (int i = 2; i <= n; ++i) {
        if (dist2[i] > dist2[endPoint]) {
            endPoint = i;
        }
    }
    
    // BFS from v to find distances again
    bfs(endPoint, dist1);
    
    // The result for each node is max(dist1[i], dist2[i])
    for (int i = 1; i <= n; ++i) {
        maxDist[i] = max(dist1[i], dist2[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << maxDist[i] << " ";
    }
    cout << endl;

    return 0;
}