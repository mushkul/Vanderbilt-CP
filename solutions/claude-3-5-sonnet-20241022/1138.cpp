#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 200005;
vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer;
ll bit[MAXN], val[MAXN];
 
void update(int idx, ll delta, int n) {
    for(; idx <= n; idx += idx & (-idx))
        bit[idx] += delta;
}
 
ll get(int idx) {
    ll sum = 0;
    for(; idx > 0; idx -= idx & (-idx))
        sum += bit[idx];
    return sum;
}
 
void dfs(int u, int p) {
    tin[u] = ++timer;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
        }
    }
    tout[u] = timer;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    timer = 0;
    dfs(1, 0);
    
    for(int i = 1; i <= n; i++) {
        update(tin[i], val[i], n);
    }
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int s, x;
            cin >> s >> x;
            update(tin[s], x - val[s], n);
            val[s] = x;
        } else {
            int s;
            cin >> s;
            ll sum = get(tin[s]);
            cout << sum << "\n";
        }
    }
    
    return 0;
}