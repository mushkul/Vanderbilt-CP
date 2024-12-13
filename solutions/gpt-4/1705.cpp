#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n, u[N], v[N], par[N], b[N], a[N];
vector<int> g[N];

int get_par(int v){
    return par[v] = (par[v] == v) ? v : get_par(par[v]);
}

void merge(int x, int y){
    par[get_par(x)] = get_par(y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, q;
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++){
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    for(int i=1; i<=n; i++){
        par[i] = i;
    }
    while(q--){
        int b, a, c, u;
        cin >> a >> b >> c;
        u = get_par(b);
        for(int n : g[b]){
            if(n != u && n != c) merge(n, b);
        }
        cout << (get_par(a) != get_par(c) && get_par(b) != get_par(c) ? "YES" : "NO") << "\n";
        for(int i=1; i<=n; i++){
            par[i] = i;
        }
    }
    return 0;
}