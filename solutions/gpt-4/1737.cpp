#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 7;
const int LOGN = 20;
int n, q, parent[LOGN][MAXN];
vector<ll> v[MAXN];
vector<ll> bit[MAXN];

void add(int ind, int idx, ll val) {
    for(; idx < v[ind].size(); idx += idx & -idx)
        bit[ind][idx] += val;
}

ll sum(int ind, int idx) {
    ll tot = 0;
    for(; idx; idx -= idx & -idx)
        tot += bit[ind][idx];
    return tot;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    v[1].resize(n + 1);
    bit[1].resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> v[1][i];
        add(1, i, v[1][i]);
    }
    
    int idx = 2;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k, a;
            ll x;
            cin >> k >> a >> x;
            for(int b = k; b < MAXN; b = parent[0][b]) {
                add(b, a, x - v[b][a]);
            }
            v[k][a] = x;
        } 
        else if(type == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            cout << sum(k, b) - sum(k, a - 1) << "\n";
        } 
        else {
            int k;
            cin >> k;
            for(int j = 0; j < LOGN; j++) {
                parent[j][idx] = (j == 0 ? k : parent[j - 1][parent[j - 1][idx]]);
            }
            v[idx] = v[k]; 
            bit[idx] = bit[k];
            idx++;
        }
    }
    return 0;
}