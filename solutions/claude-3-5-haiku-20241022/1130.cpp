#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int dp[MAXN][2];

void dfs(int node, int parent) {
    int take = 0, notTake = 0;
    
    for (int child : graph[node]) {
        if (child == parent) continue;
        
        dfs(child, node);
        
        take += dp[child][1];
        notTake += max(dp[child][0], dp[child][1]);
    }
    
    dp[node][0] = notTake;
    dp[node][1] = take + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    
    cout << max(dp[1][0], dp[1][1]) << endl;
    
    return 0;
}