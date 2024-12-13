#include<bits/stdc++.h>
using namespace std;
#define MAX 500 + 5

vector<int> e[MAX], v[MAX];
priority_queue<int> q[MAX];
int res[MAX], vis[MAX];
int n, m, k;

int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        q[b].push_back(a);
    }

    for(int i = 1; i <= n + m; i++) {
        int x;
        if(i <= n) {
            x = i;
        } else {
            x = q[i - n].top();
            q[i - n].pop();
        }

        while(!v[x].empty() && (vis[v[x].back()] > n || (vis[v[x].back()] && q[vis[v[x].back()]].top() > x))) {
            if(vis[v[x].back()] > n) q[vis[v[x].back()]].push(x);
            v[x].pop_back();
        }
        if(!v[x].empty()) {
            if(vis[x] <= n && vis[x]) q[vis[x]].push(x);
            vis[x] = v[x].back();
            v[x].pop_back();
        }
    }

    for(int i = n; i; i--) {
        if(vis[i] && (vis[i] <= n || q[vis[i] - n].top() <= i)) continue;
        while(!q[i].empty() && vis[q[i].top()]) q[i].pop();
        if(!q[i].empty()) vis[q[i].top()] = i + n;
    }

    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++) {
        if(vis[i] > n) ans.push_back({i, vis[i] - n});
    }
    cout << ans.size() << "\n";
    for(auto &i: ans) cout << i.first << " " << i.second << "\n";

    return 0;
}