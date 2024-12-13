#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> graph1[MAX_N];
vector<int> graph2[MAX_N];

vector<int> get_canonical_form(int n, vector<int>* graph) {
    vector<int> degree(n + 1);
    for (int i = 1; i <= n; i++) {
        degree[i] = graph[i].size();
    }
    
    queue<int> leaves;
    vector<bool> removed(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }
    
    int remaining = n;
    vector<int> canonicalForm;
    
    while (remaining > 2) {
        int size = leaves.size();
        for (int i = 0; i < size; i++) {
            int leaf = leaves.front();
            leaves.pop();
            
            removed[leaf] = true;
            remaining--;
            
            for (int neighbor : graph[leaf]) {
                if (!removed[neighbor]) {
                    degree[neighbor]--;
                    
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
    }
    
    vector<int> centers;
    for (int i = 1; i <= n; i++) {
        if (!removed[i]) {
            centers.push_back(i);
        }
    }
    
    for (int center : centers) {
        vector<int> subtreeSizes;
        for (int neighbor : graph[center]) {
            if (!removed[neighbor]) {
                queue<int> q;
                vector<bool> vis(n + 1, false);
                q.push(neighbor);
                vis[neighbor] = true;
                vis[center] = true;
                
                int size = 1;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    
                    for (int next : graph[curr]) {
                        if (!vis[next]) {
                            q.push(next);
                            vis[next] = true;
                            size++;
                        }
                    }
                }
                subtreeSizes.push_back(size);
            }
        }
        
        sort(subtreeSizes.begin(), subtreeSizes.end());
        canonicalForm.insert(canonicalForm.end(), subtreeSizes.begin(), subtreeSizes.end());
    }
    
    return canonicalForm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            graph1[i].clear();
            graph2[i].clear();
        }
        
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            graph1[u].push_back(v);
            graph1[v].push_back(u);
        }
        
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            graph2[u].push_back(v);
            graph2[v].push_back(u);
        }
        
        vector<int> form1 = get_canonical_form(n, graph1);
        vector<int> form2 = get_canonical_form(n, graph2);
        
        cout << (form1 == form2 ? "YES" : "NO") << "\n";
    }
    
    return 0;
}