#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 100000;

vector<int> adj[MAXN+1];
int in_degree[MAXN+1];
long long ways[MAXN+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    memset(in_degree, 0, sizeof(in_degree));
    memset(ways, 0, sizeof(ways));

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> q;
    q.push(1);
    ways[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            ways[v] = (ways[v] + ways[u]) % MOD;
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << ways[n] << "\n";

    return 0;
}