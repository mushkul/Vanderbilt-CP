#include <bits/stdc++.h>
using namespace std;

vector<int> edge[200005];
int dp[200005][2];

void dfs(int pos, int pre) {
    int sum = 0, mx = 0;
    for(auto to: edge[pos]) {
        if(to == pre) continue;
        dfs(to, pos);
        sum += max(dp[to][0], dp[to][1]);
        mx = max(mx, dp[to][0] - max(dp[to][0], dp[to][1]));
    }
    dp[pos][0] = sum;
    dp[pos][1] = sum + mx + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    dfs(1, 0);
    
    cout << max(dp[1][0], dp[1][1]) << "\n";
    
    return 0;
}