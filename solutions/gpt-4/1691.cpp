#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> g[MAX_N];
int deg[MAX_N], st[MAX_N], ed[MAX_N], res[MAX_N], t;
bool rem[MAX_N];

void dfs(int u) {
    while (!g[u].empty()) {
        int v = g[u].back();
        g[u].pop_back();
        if (rem[v]) {
            rem[v] = false;
            dfs(st[v] + ed[v] - u);
        }
    }
    res[t++] = u;
}

void solve() {
    int n, m; 
    cin >> n >> m;
    memset(st, -1, sizeof st);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 
        a--, b--, deg[a]++, deg[b]++;
        g[a].push_back(i), g[b].push_back(i);
        st[i] = a, ed[i] = b, rem[i] = true;
    }
    
    vector<int> odd;
    for (int i = 0; i < n; i++)
        if (deg[i] & 1)
            odd.push_back(i);
    
    if (odd.size() != 0 && odd.size() != 2 && !(odd.size() == 2 && (odd[0] == 0 || odd[1] == 0))) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    if (odd.size() == 2)
        swap(st[m], st[m - deg[odd[1]]]);
    else
        m++;
    
    for (int i = 0; i < n; i++)
        sort(g[i].begin(), g[i].end(), [&](int a, int b) {return st[a] + ed[a] > st[b] + ed[b];});
    
    dfs(0);
    
    if (t != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    for (int i = 0; i < t; i++)
        cout << res[i] + 1 << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}