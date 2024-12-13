#include <bits/stdc++.h>
using namespace std;

vector<string> edges;
string ans;
map<string, int> vis;

void dfs(string node) {
    while (vis[node] < 2) {
        string next = node;
        next += char('0' + vis[node]);
        vis[node]++;
        dfs(next.substr(1));
    }
    edges.push_back(node);
}

string solve(int n) {
    string start(n-1, '0');
    dfs(start);
    reverse(edges.begin(), edges.end());
    
    ans = edges[0];
    for(int i = 1; i < edges.size(); i++) {
        ans += edges[i].back();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    if(n == 1) {
        cout << "01\n";
        return 0;
    }
    cout << solve(n) << "\n";
    return 0;
}