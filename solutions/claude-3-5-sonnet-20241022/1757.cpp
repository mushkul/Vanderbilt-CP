#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
vector<int> indeg(MAXN);
bool vis[MAXN];
int n, m;

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            pq.push(i);
        }
    }
    
    vector<int> order;
    
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        order.push_back(curr);
        
        for(int next : adj[curr]) {
            indeg[next]--;
            if(indeg[next] == 0) {
                pq.push(next);
            }
        }
    }
    
    for(int x : order) {
        cout << x << " ";
    }
    
    return 0;
}