#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
bool visited[100001];
stack<int> s;

void dfs(int node) {
    visited[node] = true;
    for(int i: adj[node]) {
        if(!visited[i])
            dfs(i);
    }
    s.push(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1;i<=n;i++) {
        if(!visited[i])
            dfs(i);
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}