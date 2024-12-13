#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MX = 2e5+10;
int seg[4*MX];

void build(vector<int>&a, int v, int tl, int tr){
    if(tl==tr) seg[v]=a[tl-1];
    else{
        int tm=(tl+tr)/2;
        build(a,2*v, tl, tm);
        build(a,2*v+1, tm+1, tr);
        seg[v]= min(seg[2*v], seg[2*v+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val){
    if(tl==tr) seg[v]=new_val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm) update(2*v, tl, tm, pos, new_val);
        else update(2*v+1, tm+1, tr, pos, new_val);
        seg[v]= min(seg[2*v], seg[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r){
    if(l>r) return 1e9+7;
    if(l==tl and r==tr) return seg[v];
    int tm=(tl+tr)/2;
    return min(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin>>n>>q;
    vector<int>a(n); for(auto &i:a) cin>>i;
    build(a, 1, 1, n);
    while(q--){
        int type; cin>>type;
        if(type==1){
            int k, u; cin>>k>>u;
            update(1, 1, n, k, u);
        }
        else{
            int a, b; cin>>a>>b;
            cout<<query(1, 1, n, a, b)<<'\n';
        }
    }
    return 0;
}