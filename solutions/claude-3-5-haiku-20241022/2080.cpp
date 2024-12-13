#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int n, k;
long long paths = 0;

void dfs(int node, int parent, vector<int>& depths) {
    depths.push_back(0);
    
    for (int child : graph[node]) {
        if (child == parent) continue;
        
        vector<int> child_depths;
        dfs(child, node, child_depths);
        
        for (int d1 : depths) {
            for (int d2 : child_depths) {
                if (d1 + d2 + 1 == k) {
                    paths++;
                }
            }
        }
        
        for (int d : child_depths) {
            depths.push_back(d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int root = 1; root <= n; root++) {
        vector<int> depths;
        dfs(root, 0, depths);
    }
    
    cout << paths << '\n';
    
    return 0;
}