#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int,int>> edges;
set<pair<int,int>> removed;
int parent[MAXN];
int components;

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]); 
}

bool merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) {
        parent[pa] = pb;
        return true;
    }
    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        edges.push_back({a,b});
    }
    
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        removed.insert({a,b});
    }
    
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    components = n;
    
    for(auto edge : edges) {
        if(!removed.count(edge) && merge(edge.first, edge.second)) {
            components--;
        }
    }
    
    vector<int> ans;
    for(auto it = removed.rbegin(); it != removed.rend(); it++) {
        ans.push_back(components);
        if(merge(it->first, it->second)) {
            components--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    for(int x : ans) {
        cout << x << " ";
    }
}