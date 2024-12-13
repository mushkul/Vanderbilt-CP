#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

struct Query {
    int l, r, idx;
    Query(int _l, int _r, int _idx) : l(_l), r(_r), idx(_idx) {}
};

int n, q, arr[MAX_N], ans[MAX_N];
int freq[MAX_N];
vector<Query> queries;
int distinct = 0;

bool compare(Query &a, Query &b) {
    int block = sqrt(n);
    if (a.l/block != b.l/block) return a.l/block < b.l/block;
    return (a.l/block & 1) ? (a.r < b.r) : (a.r > b.r);
}

void add(int pos) {
    freq[arr[pos]]++;
    if(freq[arr[pos]] == 1) distinct++;
}

void remove(int pos) {
    freq[arr[pos]]--;
    if(freq[arr[pos]] == 0) distinct--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    
    map<int,int> compress;
    vector<int> values;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        values.push_back(arr[i]);
    }
    
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    
    for(int i = 0; i < values.size(); i++) {
        compress[values[i]] = i;
    }
    
    for(int i = 0; i < n; i++) {
        arr[i] = compress[arr[i]];
    }
    
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries.push_back(Query(l, r, i));
    }
    
    sort(queries.begin(), queries.end(), compare);
    
    int curr_l = 0, curr_r = -1;
    
    for(Query q : queries) {
        while(curr_l > q.l) {
            curr_l--;
            add(curr_l);
        }
        while(curr_r < q.r) {
            curr_r++;
            add(curr_r);
        }
        while(curr_l < q.l) {
            remove(curr_l);
            curr_l++;
        }
        while(curr_r > q.r) {
            remove(curr_r);
            curr_r--;
        }
        ans[q.idx] = distinct;
    }
    
    for(int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}