#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> graph[MAX_N];
int visited[MAX_N];
stack<int> order;
bool impossible = false;

void dfs(int node) {
    visited[node] = 1;
    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            dfs(neighbor);
        } else if (visited[neighbor] == 1) {
            impossible = true;
        }
    }
    visited[node] = 2;
    order.push(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }

    if (impossible) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        while (!order.empty()) {
            cout << order.top() << " ";
            order.pop();
        }
        cout << endl;
    }

    return 0;
}