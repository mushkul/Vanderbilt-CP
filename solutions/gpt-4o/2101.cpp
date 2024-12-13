#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                ++rank[rootX];
            }
        }
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; ++i) {
        cin >> roads[i].first >> roads[i].second;
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> answer(q, -1);
    vector<vector<pair<int, int>>> queryDays(n + 1);
    for (int i = 0; i < q; ++i) {
        queryDays[queries[i].first].emplace_back(queries[i].second, i);
    }

    DSU dsu(n);
    for (int day = 0; day < m; ++day) {
        dsu.unite(roads[day].first, roads[day].second);
        for (const auto &qr : queryDays[roads[day].first]) {
            if (dsu.find(qr.first) == dsu.find(roads[day].first)) {
                answer[qr.second] = day + 1;
            }
        }
        for (const auto &qr : queryDays[roads[day].second]) {
            if (dsu.find(qr.first) == dsu.find(roads[day].second)) {
                answer[qr.second] = day + 1;
            }
        }
    }

    for (int ans : answer) {
        cout << ans << endl;
    }

    return 0;
}