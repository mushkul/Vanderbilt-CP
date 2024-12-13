#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;

        if (rank[px] < rank[py]) {
            swap(px, py);
        }
        parent[py] = px;
        if (rank[px] == rank[py]) {
            rank[px]++;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int,int>> edges(m);
    set<pair<int,int>> current_edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        edges[i] = {a, b};
        current_edges.insert({a, b});
    }

    vector<tuple<int,int,int>> events(k);
    for (int i = 0; i < k; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a > b) swap(a, b);
        events[i] = {t, a, b};
    }

    vector<int> ans;
    DSU dsu(n);
    
    for (auto& [a, b] : edges) {
        dsu.unite(a, b);
    }

    unordered_set<int> components;
    for (int i = 1; i <= n; i++) {
        components.insert(dsu.find(i));
    }
    ans.push_back(components.size());

    for (auto& [type, a, b] : events) {
        if (type == 1) {
            if (current_edges.count({a, b}) == 0) {
                dsu.unite(a, b);
            }
            current_edges.insert({a, b});
        } else {
            current_edges.erase({a, b});
        }

        components.clear();
        dsu = DSU(n);
        for (auto& edge : current_edges) {
            dsu.unite(edge.first, edge.second);
        }

        for (int i = 1; i <= n; i++) {
            components.insert(dsu.find(i));
        }
        ans.push_back(components.size());
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}