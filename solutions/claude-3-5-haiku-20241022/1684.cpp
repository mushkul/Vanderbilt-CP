#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TwoSatisfiability {
private:
    int n;
    vector<vector<int>> graph, reverseGraph;
    vector<bool> visited;
    vector<int> order, component;
    vector<int> assignment;

    void dfs1(int v) {
        visited[v] = true;
        for (int u : graph[v]) {
            if (!visited[u]) dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int componentId) {
        visited[v] = true;
        component[v] = componentId;
        for (int u : reverseGraph[v]) {
            if (!visited[u]) dfs2(u, componentId);
        }
    }

public:
    TwoSatisfiability(int variables) : n(variables) {
        graph.resize(2 * n);
        reverseGraph.resize(2 * n);
        visited.resize(2 * n, false);
        component.resize(2 * n);
        assignment.resize(n);
    }

    void addClause(int a, bool aValue, int b, bool bValue) {
        graph[2 * (a - 1) + !aValue].push_back(2 * (b - 1) + bValue);
        graph[2 * (b - 1) + !bValue].push_back(2 * (a - 1) + aValue);
    }

    bool solve() {
        for (int i = 0; i < 2 * n; i++) {
            if (!visited[i]) dfs1(i);
        }

        fill(visited.begin(), visited.end(), false);
        reverse(order.begin(), order.end());
        int componentCount = 0;

        for (int v : order) {
            if (!visited[v]) {
                dfs2(v, componentCount);
                componentCount++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (component[2 * i] == component[2 * i + 1]) return false;
            assignment[i] = component[2 * i] > component[2 * i + 1];
        }
        return true;
    }

    vector<bool> getAssignment() {
        return assignment;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    TwoSatisfiability sat(m);

    for (int i = 0; i < n; i++) {
        char sign1, sign2;
        int x, y;
        cin >> sign1 >> x >> sign2 >> y;

        bool xValue = (sign1 == '+');
        bool yValue = (sign2 == '+');

        sat.addClause(x, xValue, y, yValue);
    }

    if (sat.solve()) {
        vector<bool> result = sat.getAssignment();
        for (bool topping : result) {
            cout << (topping ? '+' : '-') << ' ';
        }
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}