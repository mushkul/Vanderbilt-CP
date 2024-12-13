#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> deg_in, deg_out;
vector<int> path;
vector<bool> used;
stack<int> st;
int m;

void findEulerPath(int n) {
    st.push(1);
    while (!st.empty()) {
        int u = st.top();
        while (deg_out[u] > 0) {
            auto& e = adj[u][--deg_out[u]];
            if (!used[e.second]) {
                used[e.second] = true;
                st.push(e.first);
            }
        }
        if (st.top() == u) {
            path.push_back(u);
            st.pop();
        }
    }
}

int main() {
    int n;
    cin >> n >> m;
    adj.assign(n + 1, vector<pair<int, int>>());
    deg_in.assign(n + 1, 0);
    deg_out.assign(n + 1, 0);
    used.assign(m, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b, i);
        deg_out[a]++;
        deg_in[b]++;
    }

    if (deg_in[1] + 1 != deg_out[1] || deg_out[n] + 1 != deg_in[n]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 2; i < n; ++i) {
        if (deg_in[i] != deg_out[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    findEulerPath(n);

    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        reverse(path.begin(), path.end());
        for (int i = 0; i <= m; ++i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}