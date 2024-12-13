#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int values[MAXN];
int parent[MAXN];
int depth[MAXN];

void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    for (int child : graph[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int path_sum(int node) {
    int sum = 0;
    while (node != 0) {
        sum += values[node];
        node = parent[node];
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0, 1);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int s, x;
            cin >> s >> x;
            values[s] = x;
        } else {
            int s;
            cin >> s;
            cout << path_sum(s) << "\n";
        }
    }

    return 0;
}