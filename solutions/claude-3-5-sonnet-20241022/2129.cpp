#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
ll n, cost[205][205], dp[1<<20][205];
int path[1<<20][205];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    
    for(int mask = 0; mask < (1<<n); mask++) {
        for(int last = 0; last < n; last++) {
            dp[mask][last] = INF;
        }
    }
    
    dp[1][0] = 0;
    
    for(int mask = 0; mask < (1<<n); mask++) {
        int setbits = __builtin_popcount(mask);
        if(setbits == 0) continue;
        
        for(int last = 0; last < n; last++) {
            if(!(mask & (1<<last))) continue;
            
            if(dp[mask][last] == INF) continue;
            
            for(int next = 0; next < n; next++) {
                if(mask & (1<<next)) continue;
                
                int new_mask = mask | (1<<next);
                ll new_cost = dp[mask][last] + cost[setbits][next];
                
                if(new_cost < dp[new_mask][next]) {
                    dp[new_mask][next] = new_cost;
                    path[new_mask][next] = last;
                }
            }
        }
    }
    
    ll ans = INF;
    int final_task;
    
    for(int last = 0; last < n; last++) {
        if(dp[(1<<n)-1][last] < ans) {
            ans = dp[(1<<n)-1][last];
            final_task = last;
        }
    }
    
    cout << ans << "\n";
    
    vector<pair<int,int>> assignments;
    int curr_mask = (1<<n)-1;
    int curr_task = final_task;
    
    while(curr_mask > 0) {
        int employee = __builtin_popcount(curr_mask);
        assignments.push_back({employee, curr_task+1});
        
        int prev_task = path[curr_mask][curr_task];
        curr_mask ^= (1<<curr_task);
        curr_task = prev_task;
    }
    
    reverse(assignments.begin(), assignments.end());
    for(auto p : assignments) {
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}