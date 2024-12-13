#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int dist[MAXN];

void dfs(int node, int parent, int depth) {
    dist[node] = depth;
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node, depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 0);
    
    int farthest_node = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > dist[farthest_node]) {
            farthest_node = i;
        }
    }

    dfs(farthest_node, 0, 0);

    int diameter = 0;
    for (int i = 1; i <= n; i++) {
        diameter = max(diameter, dist[i]);
    }

    cout << diameter << endl;

    return 0;
}