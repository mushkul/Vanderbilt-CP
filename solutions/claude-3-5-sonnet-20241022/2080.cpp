#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;
vector<int> adj[maxN];
long long ans = 0;
int K;

int cntp(int u, int p, int d) {
    if(d == K) return 1;
    int sum = 0;
    for(int v : adj[u]) {
        if(v != p) {
            sum += cntp(v, u, d+1);
        }
    }
    return sum;
}

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            int l = cntp(v, u, 1);
            for(int w : adj[u]) {
                if(w != p && w != v) {
                    ans += l * cntp(w, u, 1);
                }
            }
            dfs(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n >> K;
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    if(K == 1) {
        cout << n-1 << '\n';
        return 0;
    }
    
    dfs(1, 0);
    ans /= 2;
    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int v : adj[i]) {
            cnt += cntp(v, i, 1);
        }
        ans += (cnt * (cnt-1))/2;
    }
    
    cout << ans << '\n';
    return 0;
}