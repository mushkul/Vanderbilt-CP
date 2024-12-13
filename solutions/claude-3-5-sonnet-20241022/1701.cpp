#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<int> adj1[MAX_N], adj2[MAX_N];
vector<int> centers1, centers2;
vector<int> parent1, parent2;

string getEncoding(int node, int parent, vector<int> adj[]) {
    vector<string> childEncodings;
    for(int child : adj[node]) {
        if(child != parent) {
            childEncodings.push_back(getEncoding(child, node, adj));
        }
    }
    sort(childEncodings.begin(), childEncodings.end());
    string res = "1";
    for(string& s : childEncodings) res += s;
    res += "0";
    return res;
}

vector<int> findCenters(vector<int> adj[], int n) {
    vector<int> degree(n+1);
    queue<int> leafs;
    int remaining = n;
    
    for(int i = 1; i <= n; i++) {
        degree[i] = adj[i].size();
        if(degree[i] == 1) leafs.push(i);
    }
    
    while(remaining > 2) {
        int sz = leafs.size();
        remaining -= sz;
        while(sz--) {
            int curr = leafs.front();
            leafs.pop();
            degree[curr] = 0;
            for(int next : adj[curr]) {
                if(degree[next] > 0) {
                    degree[next]--;
                    if(degree[next] == 1) leafs.push(next);
                }
            }
        }
    }
    
    vector<int> centers;
    for(int i = 1; i <= n; i++) {
        if(degree[i] > 0) centers.push_back(i);
    }
    return centers;
}

void solve() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        adj1[i].clear();
        adj2[i].clear();
    }
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    
    centers1 = findCenters(adj1, n);
    centers2 = findCenters(adj2, n);
    
    if(centers1.size() != centers2.size()) {
        cout << "NO\n";
        return;
    }
    
    vector<string> tree1Encodings, tree2Encodings;
    for(int center : centers1) {
        tree1Encodings.push_back(getEncoding(center, 0, adj1));
    }
    for(int center : centers2) {
        tree2Encodings.push_back(getEncoding(center, 0, adj2));
    }
    
    sort(tree1Encodings.begin(), tree1Encodings.end());
    sort(tree2Encodings.begin(), tree2Encodings.end());
    
    if(tree1Encodings == tree2Encodings) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}