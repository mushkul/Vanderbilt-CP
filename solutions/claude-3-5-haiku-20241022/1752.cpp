#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int dist[MAXN], parent[MAXN];
bool visited[MAXN];

void dfs(int node, int par, int depth) {
    visited[node] = true;
    dist[node] = depth;
    parent[node] = par;
    
    for (int child : graph[node]) {
        if (!visited[child]) {
            dfs(child, node, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, d;
    cin >> n >> d;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    
    int max_dist_node = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[max_dist_node]) {
            max_dist_node = i;
        }
    }
    
    memset(visited, 0, sizeof(visited));
    dfs(max_dist_node, 0, 0);
    
    max_dist_node = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[max_dist_node]) {
            max_dist_node = i;
        }
    }
    
    vector<int> diameter_path;
    int curr = max_dist_node;
    while (curr != 0) {
        diameter_path.push_back(curr);
        curr = parent[curr];
    }
    
    vector<int> offices;
    int last_office = diameter_path[0];
    offices.push_back(last_office);
    
    for (int node : diameter_path) {
        if (dist[node] - dist[last_office] >= d) {
            last_office = node;
            offices.push_back(node);
        }
    }
    
    cout << offices.size() << "\n";
    for (int office : offices) {
        cout << office << " ";
    }
    cout << "\n";
    
    return 0;
}