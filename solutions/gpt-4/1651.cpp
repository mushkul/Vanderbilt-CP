#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxN = 2e5;
ll arr[maxN+1],seg[4*maxN+4],lazy[4*maxN+4];

void build(int si, int ss, int se){
    if(ss == se){
        seg[si] = arr[ss];
        return ;
    }
    int mid = (ss + se) / 2;
    build(2*si, ss, mid);
    build(2*si+1, mid+1, se);
    seg[si] = 0;
}
void lazyUpdate(int si, int ss, int se){
    if(lazy[si] != 0){
        seg[si] += (se-ss+1)*lazy[si];
        if(ss != se){
            lazy[2*si] += lazy[si];
            lazy[2*si+1] += lazy[si];
        }
        lazy[si] = 0;
    }
}
void rangeUpdate(int si, int ss, int se, int qs, int qe, int val){
    lazyUpdate(si, ss, se);
    if(qs > se || qe < ss) return ;
    if(qs <= ss && qe >= se){
        seg[si] += (se-ss+1)*val;
        if(ss != se){
            lazy[2*si] += val;
            lazy[2*si+1] += val;
        }
        return ;
    }
    int mid = (ss+se) / 2;
    rangeUpdate(2*si, ss, mid, qs, qe, val);
    rangeUpdate(2*si+1, mid+1, se, qs, qe, val);
    seg[si] = seg[2*si] + seg[2*si+1];
}
ll query(int si, int ss, int se, int qs, int qe){
    lazyUpdate(si, ss, se);
    if(qs > se || qe < ss) return 0;
    if(qs <= ss && qe >= se) return seg[si];
    int mid = (ss+se) / 2;
    return query(2*si, ss, mid, qs, qe) + query(2*si+1, mid+1, se, qs, qe);
}

int main(){ 
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while(q--){
        int queryType;
        cin >> queryType;
        if(queryType == 1){
            int a, b, u;
            cin >> a >> b >> u; 
            rangeUpdate(1, 1, n, a, b, u); 
        }
        else{
            int k;
            cin >> k;
            cout << query(1, 1, n, k, k) << "\n";
        }
    }
}