#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Query {
    char type;
    int k, a, b;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    vector<Query> queries(q);
    set<int> coords;
    
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        coords.insert(p[i]);
    }
    
    for(int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if(type == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            queries[i] = {type, k, x, 0};
            coords.insert(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries[i] = {type, 0, a, b};
            coords.insert(a);
            coords.insert(b);
        }
    }
    
    map<int,int> compress;
    int coord_id = 0;
    for(int x : coords) {
        compress[x] = coord_id++;
    }
    
    vector<int> freq(coord_id);
    for(int i = 0; i < n; i++) {
        freq[compress[p[i]]]++;
    }
    
    for(Query q : queries) {
        if(q.type == '!') {
            freq[compress[p[q.k]]]--;
            p[q.k] = q.a;
            freq[compress[q.a]]++;
        } else {
            int ans = 0;
            int left = compress[q.a];
            int right = compress[q.b];
            for(int i = left; i <= right; i++) {
                ans += freq[i];
            }
            cout << ans << "\n";
        }
    }
    
    return 0;
}