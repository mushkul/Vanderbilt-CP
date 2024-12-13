#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> visited;
vector<int> assignment;
vector<vector<int>> adj;

bool dfs(int node) {
    if (visited[node])
        return true;
    visited[node] = true;
    if (visited[node ^ 1])
        return false;
    for (int neighbor : adj[node])
        if (!dfs(neighbor))
            return false;
    assignment.push_back(node);
    return true;
}

bool solve_2SAT(int n) {
    visited.assign(2 * n, false);
    assignment.clear();
    for (int i = 0; i < 2 * n; i += 2)
        if (!visited[i] && !visited[i + 1]) {
            vector<int> temp1, temp2;
            temp1 = assignment;
            if (!dfs(i)) {
                assignment = temp2;
                visited.assign(2 * n, false);
                if (!dfs(i + 1))
                    return false;
            }
            assignment = temp1;
            visited.assign(2 * n, false);
            if (!dfs(i) || !dfs(i + 1)) {
                assignment = temp2;
                return false;
            }
        }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.assign(2 * m, vector<int>());
    for (int i = 0; i < n; ++i) {
        string wish1, wish2;
        int topping1, topping2;
        cin >> wish1 >> topping1 >> wish2 >> topping2;
        --topping1, --topping2;
        int a = (wish1 == "+" ? 2 * topping1 : 2 * topping1 + 1);
        int b = (wish2 == "+" ? 2 * topping2 : 2 * topping2 + 1);
        adj[a ^ 1].push_back(b);
        adj[b ^ 1].push_back(a);
    }

    if (solve_2SAT(m)) {
        string output(m, '-');
        for (int var : assignment) {
            if (var % 2 == 0)
                output[var / 2] = '+';
        }
        cout << output << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}