#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
int head[N],ver[N<<1],nxt[N<<1],tot;
int n,q;
int x[N],fa[N],dep[N],son[N],siz[N],top[N],id[N],dfn;
ll c[N<<2],w[N],s[N]; 

inline void add(int x,int y) {
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs1(int x) {
    siz[x]=1;
    for(int i=head[x];i;i=nxt[i]) {
        int y=ver[i];
        if(y==fa[x]) continue;
        fa[y]=x;
        dep[y]=dep[x]+1;
        dfs1(y);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y; 
    }
}

void dfs2(int x,int t) {
    id[x]=++dfn;
    w[dfn]=s[x];
    top[x]=t;
    if(son[x]) dfs2(son[x],t);
    for(int i=head[x];i;i=nxt[i]) {
        int y=ver[i];
        if(y==fa[x]||y==son[x]) continue;
        dfs2(y,y);
    }
}

void build(int x,int l,int r) {
    if(l==r) {
        c[x]=w[l];
        return; 
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    c[x]=max(c[x<<1],c[x<<1|1]);
}

ll query(int x,int l,int r,int ql,int qr) {
    if(ql<=l&&r<=qr) return c[x];
    int mid = (l+r)>>1; ll res = 0;
    if(ql<=mid) res = max(res, query(x<<1,l,mid,ql,qr));
    if(mid<qr) res = max(res, query(x<<1|1,mid+1,r,ql,qr));
    return res;
}

ll Q(int x,int y) {
    ll res=0;
    while(top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res=max(res,query(1,1,n,id[top[x]],id[x]));
        x = fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    res = max(res,query(1,1,n,id[x],id[y]));
    return res;
}

inline void change(int x,int l,int r,int pos,ll v) {
    if(l==r) {
        c[x]=v;
        return;
    }
    int mid = (l+r)>>1;
    if(pos<=mid) change(x<<1,l,mid,pos,v);
    else change(x<<1|1,mid+1,r,pos,v);
    c[x] = max(c[x<<1],c[x<<1|1]);
}

int main() {
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;++i) scanf("%lld",&s[i]);
    for(int i=1;i<n;++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        add(x,y); add(y,x);
    }
    dep[1]=1;
    dfs1(1);
    dfs2(1,1);
    build(1,1,n);
    while(q--) {
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(op==1) {
            s[x] = y;
            change(1,1,n,id[x],y);
        }
        else printf("%lld\n",Q(x,y));
    }
    return 0;
}