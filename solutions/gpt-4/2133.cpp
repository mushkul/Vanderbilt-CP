#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5+5;
int n, m, k, p[MAX_N], sz[MAX_N];
pair<int, pair<int, int>> query[MAX_N];
vector<pair<int, int>> edges;
map<pair<int, int>, int> test;
vector<int> result;
 
int getPar(int u){
    if(p[u] == u) return u;
    return p[u] = getPar(p[u]);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        p[i] = i;
        sz[i] = 1;
    }
    
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        edges.push_back({a, b});
    }
    for(int i = 1; i <= k; ++i){
        int t, a, b;
        cin >> t >> a >> b;
        if(a > b) swap(a, b);
        query[i] = {t, {a, b}};
        if(t == 2) test[{a, b}] = i;
    }
    
    for(auto x : edges){
        if(!test.count(x)){
            int u = getPar(x.first), v = getPar(x.second);
            if(u != v){
                if(sz[u] < sz[v]){
                    p[u] = v;
                    sz[v] += sz[u];
                }
                else{
                    p[v] = u;
                    sz[u] += sz[v];
                }
                --n;
            }
        }
    }
    for(int i = k; i >= 1; --i){
        result.push_back(n);
        if(query[i].first == 1){
            pair<int, int> x = query[i].second;
            if(test[x] == i){
                int u = getPar(x.first), v = getPar(x.second);
                if(u != v){
                    if(sz[u] < sz[v]){
                        p[u] = v;
                        sz[v] += sz[u];
                    }
                    else{
                        p[v] = u;
                        sz[u] += sz[v];
                    }
                    --n;
                }
            }
        }
    }
    result.push_back(n);
    reverse(result.begin(), result.end());
    for(auto x : result) cout << x << ' ';
    
    return 0;
}