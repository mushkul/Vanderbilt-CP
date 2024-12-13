#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, q, o, a, b, t[200005], s[800020], lz[800020];

void build(ll idx, ll s, ll e){
    if(s == e){
        s[idx] = t[s];
        return;
    }

    ll m = (s+e)/2;
    build(2*idx+1, s, m);
    build(2*idx+2, m+1, e);
    s[idx] = s[2*idx+1] + s[2*idx+2];
}

void update(ll idx, ll s, ll e, ll l, ll r, ll val){
    if(lz[idx] != 0){
        s[idx] += lz[idx]*(e-s+1)*(e-s+2)/2 - (s-l)*(s-l-1)/2*lz[idx];

        if(s != e){
            lz[2*idx+1] += lz[idx];
            lz[2*idx+2] += lz[idx] + (m-s+1)*lz[idx];
        }
        lz[idx] = 0;
    }

    if(s>e || s>r || e<l)
        return;

    if(s>=l && e<=r){
        s[idx] += val*(e-s+1)*(e-s+2)/2 - (s-l)*(s-l-1)/2*val;

        if(s != e){
            lz[2*idx+1] += val;
            lz[2*idx+2] += val + (m-s+1)*val;
        }
        return;
    }

    ll m = (s+e)/2;
    update(2*idx+1, s, m, l, r, val);
    update(2*idx+2, m+1, e, l, r, val);
    s[idx] = s[2*idx+1] + s[2*idx+2];
}

ll query(ll idx, ll s, ll e, ll l, ll r){
    if(lz[idx] != 0){
        s[idx] += lz[idx]*(e-s+1)*(e-s+2)/2 - (s-l)*(s-l-1)/2*lz[idx];

        if(s != e){
            lz[2*idx+1] += lz[idx];
            lz[2*idx+2] += lz[idx] + (m-s+1)*lz[idx];
        }
        lz[idx] = 0;
    }

    if(s>e || s>r || e<l)
        return 0;

    if(s>=l && e<=r)
        return s[idx];

    ll m = (s+e)/2;
    return query(2*idx+1, s, m, l, r) + query(2*idx+2, m+1, e, l, r);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> q;
    for(ll i = 1; i <= n; ++i)
        cin >> t[i];

    build(0, 1, n);

    while(q--){
        cin >> o >> a >> b;
        if(o == 1)
            update(0, 1, n, a, b, 1);
        else
            cout << query(0, 1, n, a, b) << '\n';
    }

    return 0;
}