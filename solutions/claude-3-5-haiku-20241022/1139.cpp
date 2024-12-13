#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int color[MAXN];
set<int> distinctColors[MAXN];
int result[MAXN];

void dfs(int node, int parent) {
    distinctColors[node].insert(color[node]);
    
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node);
            
            if (distinctColors[node].size() < distinctColors[child].size()) {
                swap(distinctColors[node], distinctColors[child]);
            }
            
            for (int col : distinctColors[child]) {
                distinctColors[node].insert(col);
            }
        }
    }
    
    result[node] = distinctColors[node].size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}