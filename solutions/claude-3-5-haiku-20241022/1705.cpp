#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
bool visited[MAXN];

bool dfs(int start, int end, int forbidden) {
    if (start == end) return true;
    visited[start] = true;
    
    for (int neighbor : graph[start]) {
        if (neighbor == forbidden) continue;
        if (!visited[neighbor]) {
            if (dfs(neighbor, end, forbidden)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        memset(visited, 0, sizeof(visited));
        
        if (dfs(a, b, c)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}