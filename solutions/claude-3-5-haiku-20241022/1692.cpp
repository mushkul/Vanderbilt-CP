#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void deBruijnSequence(int n) {
    int k = 2;
    int nodes = pow(k, n - 1);
    vector<vector<int>> adj(nodes);
    vector<int> deg(nodes, 0);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < k; j++) {
            int to = (i * k + j) % nodes;
            adj[i].push_back(to);
            deg[to]++;
        }
    }

    vector<int> path;
    vector<bool> used(nodes * k, false);

    function<void(int)> hierholzer = [&](int u) {
        for (int& v : adj[u]) {
            if (!used[u * k + v]) {
                used[u * k + v] = true;
                hierholzer(v);
            }
        }
        path.push_back(u);
    };

    for (int i = 0; i < nodes; i++) {
        if (deg[i] == 0) {
            hierholzer(i);
            break;
        }
    }

    reverse(path.begin(), path.end());

    string result;
    for (int i = 0; i < n - 1; i++) {
        result += to_string(path[0] / (int)pow(k, n - 2 - i) % k);
    }

    for (int node : path) {
        result += to_string(node % k);
    }

    cout << result << endl;
}

int main() {
    int n;
    cin >> n;
    deBruijnSequence(n);
    return 0;
}