#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN], rev_adj[MAXN];
bool visited[MAXN];
int n, m;
set<int> critical;

void bfs_forward(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void bfs_backward(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : rev_adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    bfs_forward(1);
    vector<int> path_forward;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            path_forward.push_back(i);
        }
    }

    memset(visited, false, sizeof(visited));
    bfs_backward(n);
    vector<int> path_backward;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            path_backward.push_back(i);
        }
    }

    for (int city : path_forward) {
        if (visited[city]) {
            critical.insert(city);
        }
    }

    cout << critical.size() << "\n";
    for (int city : critical) {
        cout << city << " ";
    }
    cout << "\n";

    return 0;
}