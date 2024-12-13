#include<bits/stdc++.h>
using namespace std;

struct event {
    int x, y1, y2, t;
    bool operator < (const event &rhs) const {
        return x<rhs.x;
    }
};

int tree[800008], cnt[800008];
vector<int> ys;
vector<event> es;
int get(int i) {return lower_bound(ys.begin(), ys.end(), i) - ys.begin() + 1;};

void upd(int i, int l, int r, int L, int R, int add) {
    if(r<L || R<l) return;
    if(L<=l && r<=R) {
        cnt[i] += add;
    } else {
        int m = (l+r) >> 1;
        upd(i<<1, l, m, L, R, add);
        upd(i<<1|1, m+1, r, L, R, add);
    }
    if(cnt[i]) tree[i] = ys[r] - ys[l-1];
    else tree[i] = tree[i<<1] + tree[i<<1|1];
}

void solve() {
    int n;
    cin >> n;

    es.clear();
    ys.clear();

    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        es.push_back({x1, y1, y2, 1});
        es.push_back({x2, y1, y2, -1});
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()),ys.end());
    sort(es.begin(), es.end());

    int ret = 0, last_x = 0;

    for(auto &e : es){
        ret += tree[1] * (e.x - last_x);
        upd(1, 0, ys.size(), get(e.y1), get(e.y2) - 1, e.t);
        last_x = e.x;
    }
    
    cout<<ret<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}