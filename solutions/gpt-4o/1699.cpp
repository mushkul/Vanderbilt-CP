#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public:
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false;
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            ++rank[rootA];
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> requests(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        requests[i] = make_pair(a - 1, b - 1);
    }

    DSU dsu(n);
    int connections = 0;

    for (auto& [a, b] : requests) {
        if (dsu.unite(a, b)) {
            ++connections;
        }
    }

    cout << connections << endl;
    return 0;
}