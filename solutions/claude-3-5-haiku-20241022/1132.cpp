#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int max_dist1[MAXN], max_dist2[MAXN];

void dfs1(int node, int parent) {
    max_dist1[node] = 0;
    max_dist2[node] = 0;
    
    for (int child : graph[node]) {
        if (child == parent) continue;
        
        dfs1(child, node);
        
        int dist = max_dist1[child] + 1;
        if (dist > max_dist1[node]) {
            max_dist2[node] = max_dist1[node];
            max_dist1[node] = dist;
        } else if (dist > max_dist2[node]) {
            max_dist2[node] = dist;
        }
    }
}

void dfs2(int node, int parent, int parent_dist) {
    int max_child_dist = max_dist1[node];
    int max_child2_dist = max_dist2[node];
    
    for (int child : graph[node]) {
        if (child == parent) continue;
        
        int current_max_dist = max_child_dist;
        if (max_dist1[child] + 1 == current_max_dist) {
            current_max_dist = max(parent_dist + 1, max_child2_dist + 1);
        } else {
            current_max_dist = max(parent_dist + 1, max_child_dist + 1);
        }
        
        dfs2(child, node, current_max_dist);
    }
    
    max_dist1[node] = max(max_child_dist, parent_dist);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs1(1, 0);
    dfs2(1, 0, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << max_dist1[i] << " ";
    }
    
    return 0;
}