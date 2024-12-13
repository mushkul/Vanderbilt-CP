#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
int dp[MAXN];
int prev_city[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    fill(dp, dp + n + 1, INT_MIN);
    fill(prev_city, prev_city + n + 1, 0);
    
    dp[1] = 0;
    
    for (int i = 1; i <= n; i++) {
        if (dp[i] == INT_MIN) continue;
        
        for (int next : graph[i]) {
            if (dp[next] < dp[i] + 1) {
                dp[next] = dp[i] + 1;
                prev_city[next] = i;
            }
        }
    }
    
    if (dp[n] == INT_MIN) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    vector<int> route;
    int curr = n;
    while (curr != 0) {
        route.push_back(curr);
        curr = prev_city[curr];
    }
    
    reverse(route.begin(), route.end());
    
    cout << route.size() << "\n";
    for (int city : route) {
        cout << city << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}