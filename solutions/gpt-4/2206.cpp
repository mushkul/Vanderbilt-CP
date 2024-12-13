C++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n,m;
ll p[maxn],mm[maxn << 2],add[maxn << 2];

void pushup(int rt) {
    mm[rt] = min(mm[rt<<1] , mm[rt<<1|1]);
}

void build(int l,int r,int rt) {
    if(l == r) {
        mm[rt] = p[l] - l;
        return;
    }
    int mid = l + r >> 1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}

void update(int L,int C,int l,int r,int rt) {
    if(l == r) {
        mm[rt] = C - l;
        return;
    }
    int mid = l + r >> 1;
    if(L <= mid) 
        update(L,C,l,mid,rt<<1);
    else 
        update(L,C,mid + 1,r,rt<<1|1);
    pushup(rt);
}

ll findmin(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) {
        return mm[rt] + l;
    }
    int mid = l + r >> 1;
    ll ret = INT_MAX;
    if(L <= mid)
        ret = min(ret,findmin(L,R,l,mid,rt<<1));
    if(R > mid)
        ret = min(ret,findmin(L,R,mid+1,r,rt<<1|1));
    return ret + l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> p[i];
    build(1,n,1);
    while(m--) {
        int opt,x,y;
        cin >> opt >> x;
        if(opt == 1) {
            cin >> y;
            update(x,y,1,n,1);
        } else
            cout << min(findmin(1,x,1,n,1),findmin(x,n,1,n,1)) << "\n";
    }
    return 0;
}