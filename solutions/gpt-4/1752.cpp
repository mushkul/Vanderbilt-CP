#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int parent[MAXN], depth[MAXN], office[MAXN];
int n, d, k;

void dfs(int u, int p) {
    parent[u] = p;
    depth[u] = depth[p] + 1;
    if(depth[u] >= d && depth[u] - depth[office[parent[parent[u]]]]+1 >= d)
        office[u] = u, k++;
    else
        office[u] = office[p];
    for(int v : graph[u])
        if(v != p) dfs(v, u);
}

int main() {
    scanf("%d%d", &n, &d);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    depth[0] = -1;
    dfs(1, 0);
    printf("%d\n", k);
    for(int i = 1; i <= n; i++)
        if(office[i] == i) printf("%d ", i);
    return 0;
}