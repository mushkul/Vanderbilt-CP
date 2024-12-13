#include<bits/stdc++.h>
using namespace std;

#define mx 50005
vector<int> v[mx];
bool dp[mx][mx], vis[mx];
int n, m, q;

void dfs(int src) {
    dp[src][src] = true;
    vis[src] = true;

    for(auto x: v[src]) {
        if(!vis[x]) {
            dfs(x);
        }
        for(int i=1; i<=n; ++i) {
            if(dp[x][i]) {
                dp[src][i] = true;
            }
        }
    }
}

int main() {
    cin>>n>>m>>q;

    while(m--) {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    for(int i=1; i<=n; ++i) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    while(q--) {
        int a, b;
        cin>>a>>b;
        if(dp[a][b]) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }

    return 0;
}