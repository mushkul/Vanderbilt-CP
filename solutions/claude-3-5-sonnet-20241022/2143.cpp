#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 50001;
vector<int> adj[MAXN];
bitset<MAXN> reach[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for(int i = 1; i <= n; i++) {
        queue<int> que;
        que.push(i);
        reach[i].set(i);
        
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            
            for(int next : adj[cur]) {
                if(!reach[i].test(next)) {
                    reach[i].set(next);
                    que.push(next);
                }
            }
        }
    }
    
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << (reach[a].test(b) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}