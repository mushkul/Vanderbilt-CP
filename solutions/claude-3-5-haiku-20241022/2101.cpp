#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;

        if (rank[px] < rank[py])
            swap(px, py);
        parent[py] = px;
        if (rank[px] == rank[py])
            rank[px]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> roads(m);
    for (int i = 0; i < m; i++) 
        cin >> roads[i].first >> roads[i].second;

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) 
        cin >> queries[i].first >> queries[i].second;

    vector<int> result(q, -1);
    DSU dsu(n);

    for (int day = 1; day <= m; day++) {
        int a = roads[day - 1].first;
        int b = roads[day - 1].second;
        dsu.unite(a, b);

        for (int i = 0; i < q; i++) {
            if (result[i] == -1 && dsu.find(queries[i].first) == dsu.find(queries[i].second)) {
                result[i] = day;
            }
        }
    }

    for (int i = 0; i < q; i++)
        cout << result[i] << "\n";

    return 0;
}