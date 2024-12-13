#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) {
            parent[px] = py;
        }
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<pair<int,int>> roads(m);
    for(int i = 0; i < m; i++) {
        cin >> roads[i].first >> roads[i].second;
    }
    
    vector<pair<pair<int,int>,int>> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].second = i;
    }
    
    vector<int> ans(q, -1);
    vector<DSU> dsu_states;
    dsu_states.push_back(DSU(n));
    
    for(int i = 0; i < m; i++) {
        DSU curr = dsu_states.back();
        curr.unite(roads[i].first, roads[i].second);
        dsu_states.push_back(curr);
    }
    
    int l, r, mid;
    for(auto &query : queries) {
        int start = query.first.first;
        int end = query.first.second;
        int idx = query.second;
        
        l = 0;
        r = m;
        
        if(!dsu_states[m].connected(start, end)) {
            continue;
        }
        
        while(l < r) {
            mid = (l + r) / 2;
            if(dsu_states[mid].connected(start, end)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans[idx] = l;
    }
    
    for(int x : ans) {
        cout << x << "\n";
    }
    
    return 0;
}