#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> adj2;
map<vector<string>, string> hash_map;
int node_count;
string compute_hash(int node, int parent, vector<vector<int>>& adjacency_list) {
    vector<string> hashes;
    for (int neighbor : adjacency_list[node]) {
        if (neighbor == parent) continue;
        hashes.push_back(compute_hash(neighbor, node, adjacency_list));
    }
    sort(hashes.begin(), hashes.end());
    if (hash_map.find(hashes) == hash_map.end()) {
        hash_map[hashes] = to_string(node_count++);
    }
    return hash_map[hashes];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        adj.assign(n + 1, vector<int>());
        adj2.assign(n + 1, vector<int>());
        
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        
        hash_map.clear();
        node_count = 0;
        string hash1 = compute_hash(1, -1, adj);
        
        hash_map.clear();
        node_count = 0;
        string hash2 = compute_hash(1, -1, adj2);

        cout << (hash1 == hash2 ? "YES" : "NO") << '\n';
    }
    
    return 0;
}