#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    vector<int> prev(n+1, -1);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    bool found = false;
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if(curr == n) {
            found = true;
            break;
        }
        
        for(int next : adj[curr]) {
            if(!visited[next]) {
                visited[next] = true;
                prev[next] = curr;
                q.push(next);
            }
        }
    }
    
    if(!found) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    vector<int> path;
    for(int curr = n; curr != -1; curr = prev[curr]) {
        path.push_back(curr);
    }
    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";
    for(int x : path) {
        cout << x << " ";
    }
    
    return 0;
}