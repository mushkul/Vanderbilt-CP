#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;

struct UnionFind {
    vector<int> p, rank, setSize;
    int numSets;
    
    UnionFind(int N) {
        p.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }
    
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    
    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) swap(x,y);
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
            setSize[y] += setSize[x];
            numSets--;
        }
    }
    
    void undoUnion(int i, int j) {
        if(isSameSet(i,j)) {
            int x = findSet(i);
            p[i] = i;
            setSize[x] -= setSize[i];
            setSize[i] = 1;
            numSets++;
        }
    }
};

struct Query {
    int t,a,b;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,k;
    cin >> n >> m >> k;
    
    set<pair<int,int>> edges;
    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        edges.insert({a,b});
    }
    
    vector<Query> queries(k);
    vector<bool> valid(k);
    for(int i=0; i<k; i++) {
        int t,a,b;
        cin >> t >> a >> b;
        if(a > b) swap(a,b);
        queries[i] = {t,a,b};
        
        if(t == 1) {
            valid[i] = edges.count({a,b}) == 0;
            edges.insert({a,b});
        } else {
            valid[i] = edges.count({a,b}) == 1;
            edges.erase({a,b});
        }
    }
    
    UnionFind uf(n+1);
    for(auto e : edges) {
        uf.unionSet(e.first, e.second);
    }
    
    cout << uf.numSets-1 << " ";
    
    for(int i=0; i<k; i++) {
        if(!valid[i]) {
            cout << uf.numSets-1 << " ";
            continue;
        }
        
        if(queries[i].t == 1) {
            uf.unionSet(queries[i].a, queries[i].b);
        } else {
            uf.undoUnion(queries[i].a, queries[i].b); 
        }
        cout << uf.numSets-1 << " ";
    }
    
    return 0;
}