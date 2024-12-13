#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
vector<pair<int,int>> edges;
vector<int> graph[MAXN];
int parent[MAXN], match[MAXN];

int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) parent[x] = y;
}

bool bfs(int source, int sink) {
    vector<int> dist(MAXN, -1);
    queue<int> q;
    q.push(source);
    dist[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                match[v] = u;
            }
        }
    }

    return dist[sink] != -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) 
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int block_count = 0;
    vector<pair<int,int>> block_edges;

    while (bfs(1, n)) {
        int cur = n;
        while (cur != 1) {
            int prev = match[cur];
            graph[prev].erase(remove(graph[prev].begin(), graph[prev].end(), cur), graph[prev].end());
            graph[cur].erase(remove(graph[cur].begin(), graph[cur].end(), prev), graph[cur].end());
            block_edges.push_back({prev, cur});
            block_count++;
            cur = prev;
        }
    }

    cout << block_count << endl;
    for (auto e : block_edges) 
        cout << e.first << " " << e.second << endl;

    return 0;
}