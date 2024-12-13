#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct data{ll sum, prop, reset; bool toReset;};
const int MAX = 200005;

int n, q;

void node_reset(data &node, ll x, ll len)
{
    node.reset = x; 
    node.prop = 0;
    node.sum=x*len; 
    node.toReset = true;
}

void node_propagate(data &node, ll x, ll len)
{
    node.prop += x;
    node.sum += len*x;
}

void propagate(int lrs, int rrs, int pos, ll len)
{
    if(tree[pos].toReset)
    {
        if(lrs!=rrs)
        {    
            node_reset(tree[lrs], tree[pos].reset, len/2);
            node_reset(tree[rrs], tree[pos].reset, len/2);
        }

        tree[pos].toReset = false;
    }
    else if(tree[pos].prop)
    {
        if(lrs!=rrs)
        {    
            node_propagate(tree[lrs], tree[pos].prop, len/2);
            node_propagate(tree[rrs], tree[pos].prop, len/2);
        }

        tree[pos].prop = 0;
    }
}

data make_data(ll v)
{
    data res;
    res.sum = v; res.toReset = false;
    res.prop = 0; res.reset = 0;
    return res;
}

data combine(data l, data r)
{
    data res;
    res.toReset = false;
    res.prop = 0;
    res.sum = l.sum + r.sum;
    res.reset = 0;

    return res;
}

void build(int pos, int l, int r, vector<data>&tree, vector<ll>&A)
{
    if(l == r) { tree[pos] = make_data(A[l]); return;}

    int mid = (l + r)>>1;
    int lrs = pos<<1, rrs = lrs + 1;

    build(lrs,l,mid,tree,A); build(rrs, mid + 1, r,tree,A);

    tree[pos] = combine(tree[lrs],tree[rrs]);
}

void range_update(int pos, int L, int R, int l, int r, vector<data>&tree, ll val, bool makeEqual = false)
{

    int lrs = pos<<1, rrs = lrs + 1;
    ll len = R - L + 1;
    
    propagate(lrs, rrs, pos, len);

    if(R<l || r<L) return;
    
    if(l<=L && R<=r)
    {
        if(makeEqual) node_reset(tree[pos], val, len);
        else node_propagate(tree[pos], val, len);

        propagate(lrs, rrs, pos, len);
        return;
    }

    int mid = (L+R)>>1;

    range_update(lrs, L, mid, l, r,tree,val,makeEqual); 
    range_update(rrs, mid+1, R, l, r,tree,val,makeEqual); 

    tree[pos] = combine(tree[lrs], tree[rrs]);
}

ll query(int pos, int L, int R, int l, int r, vector<data>&tree)
{

    int lrs = pos<<1, rrs = lrs + 1;
    ll len = R - L + 1;

    propagate(lrs, rrs, pos, len);

    if(r < L || R < l) return 0; 
    if(l <= L && R <= r) return tree[pos].sum; 

    int mid = (L+R)>>1;

    ll p1 = query(lrs, L, mid, l, r,tree); 
    ll p2 = query(rrs, mid+1, R, l, r,tree); 

    return p1 + p2;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> q;

    vector<ll>A(n + 1);
    for(int i = 1; i <= n; i++) cin >> A[i];

    vector<data>tree(4*MAX);

    build(1, 1, n, tree, A);

    while(q--)
    {
        ll t, a, b, x;
        cin >> t >> a >> b;
        if(t == 1)
        {
            cin >> x;
            range_update(1, 1, n, a, b,tree,x);
        }
        else if(t == 2)
        {
            cin >> x;
            range_update(1, 1, n, a, b,tree,x, true);
        }
        else if(t == 3)
        {
            cout << query(1, 1, n, a, b,tree) << "\n";
        }
    }

    return 0;
}