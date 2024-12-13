#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int maxN = 2e5;
vector<int> adj[maxN];
vector<ll> val(maxN), BIT(maxN), in(maxN), out(maxN);
int timer = 1;
void dfs(int u, int p) {
    in[u] = timer++;
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    out[u] = timer - 1;
}
void update(int i, ll v) {
    for (; i < maxN; i += i & -i)
        BIT[i] += v;
}
ll sum(int i) {
    ll s = 0;
    for (; i > 0; i -= i & -i)
        s += BIT[i];
    return s;
}
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i=1; i<=n; ++i) {
        update(in[i], val[i]);
        update(out[i]+1, -val[i]);
    }
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            ll x;
            int s;
            cin >> s >> x;
            update(in[s], x - val[s]);
            update(out[s] + 1, -x + val[s]);
            val[s] = x;
        } else {
            int s;
            cin >> s;
            cout << sum(in[s]) << "\n";
        }
    }
    return 0;
}