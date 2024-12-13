#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
const int maxn = 200005;
vector < pair < int , int > > g[maxn];
int res[maxn], used[maxn], cont = 1;

void dfs(int v){
    used[v] = 1;
    while(g[v].size()){
        pair < int , int > t = g[v].back();
        g[v].pop_back();
        if(res[t.second])continue;
        res[t.second] = (v ==  t.first ? 1 : -1);
        dfs(t.first + t.second - v);
    }
    if(cont % 2 != g[v].size() % 2)cont++; 
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> a >> b;
        g[a].PB({b, i});
        g[b].PB({a, i});
    }
    for(int i = 1;i <= n;i++)
        if(!used[i])
            dfs(i);
    if(cont % 2 == 0){
        for(int i = 1;i <= m;i++)
            cout << (res[i] == 1 ? a : b) << "\n";
    }
    else
        puts("IMPOSSIBLE");
    return 0;
}