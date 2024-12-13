#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define f first
#define s second
const int maxN = 2e5+100;
int a[maxN], pos[maxN], seg[4*maxN];
set<pii> st;
void modify(int i,int v,int s=0,int e=maxN-1,int id=1){
    if(i<s || i>e) return;
    if(e==s){
        seg[id] = v;
        return;
    }
    int mid = (s+e)/2;
    modify(i,v,s,mid,2*id);
    modify(i,v,mid+1,e,2*id+1);
    seg[id] = min(seg[2*id],seg[2*id+1]);
}
int get(int l,int r,int s=0,int e=maxN-1,int id=1){
    if(l>e || r<s) return maxN;
    if(l<=s && e<=r) return seg[id];
    int mid = (s+e)/2;
    return min(get(l,r,s,mid,2*id),get(l,r,mid+1,e,2*id+1));
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[--a[i]] = i;
    }
    ll res = 0;
    st.insert({-1,-1});
    st.insert({n,n});
    for(int i=0;i<n;i++){
        modify(pos[i],i);
        auto it = st.lower_bound({pos[i],0});
        it--;
        int l = (*it).s;
        it++;it++;
        int r = (*it).f;
        int p = get(l+1,pos[i]-1);
        res += min(p-l,pos[i]-r);
        st.insert({pos[i],i});
    }
    cout << res << '\n';
}