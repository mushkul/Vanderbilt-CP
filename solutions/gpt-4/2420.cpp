#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5+7;
const ll K=1e9+9,P=31;
ll p[N], inv_p[N], h1[N], h2[N];
char s[N];
int n,m;

ll binPow(ll b, ll p){
    ll res=1;
    while(p){
        if(p&1)
            res = (res*b)%K;
        b = (b*b)%K;
        p >>= 1;
    }
    return res;
}

void precalc(){
    p[0] = inv_p[0] = 1;
    ll inv_b = binPow(P, K-2);
    for(int i=1; i<n; ++i){
        p[i] = (p[i-1]*P)%K;
        inv_p[i] = (inv_p[i-1]*inv_b)%K;
    }
}

void gen_hash(){
    for(int i=0; i<n; ++i){
        h1[i+1] = (h1[i]+p[i]*(s[i]-'a'+1))%K;
        h2[i+1] = (h2[i]+p[n-i-1]*(s[i]-'a'+1))%K;
    }
}

ll get_hash(ll h[], int l, int r, ll p[]){
    ll res = (h[r] - h[l-1]+K)%K;
    return (res*p[n-r])%K;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    cin>>s;
    precalc();
    gen_hash();

    while(m--){
        int op; cin>>op;
        if(op==1){
            int pos; char val;
            cin>>pos>>val;
            --pos;
            ll d = (p[pos]*(val-'a'+1))%K;
            d = (d - p[pos]*(s[pos]-'a'+1)+K)%K;
            s[pos] = val;
            for(int i=pos+1; i<=n; ++i){
                h1[i] = (h1[i]+d)%K;
                h2[n-i] = (h2[n-i]+d*p[n-i])%K;
            }
        }
        else if(op == 2){
            int l,r;
            cin>>l>>r;
            --l; --r;
            ll h1_sub = get_hash(h1,l,r,inv_p);
            ll h2_sub = get_hash(h2,n-r,n-l,inv_p);
            cout<<(h1_sub == h2_sub?"YES\n":"NO\n");
        }
    }

    return 0;
}