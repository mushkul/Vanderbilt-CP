#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mx 200005

int n;
int a[mx];
int b[mx];
long long t[4*mx];
vector<int> v;

void update(int i, int l, int r, int j, long long v) {
    if (j<l || r<j) return;
    if (l==r) {
        t[i] = (t[i] + v) % mod;
        return ;
    }
    int mid = (l + r) / 2;
    update(i*2, l, mid, j, v);
    update(i*2+1, mid+1, r, j, v);
    t[i] = (t[i*2] + t[i*2+1]) % mod;
}

long long get(int i, int l, int r, int u, int v) {
    if (v<l || r<u) return 0;
    if (u<=l && r<=v) return t[i];
    int mid = (l + r) / 2;
    return (get(i*2, l, mid, u, v) + get(i*2+1, mid+1, r, u, v)) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    for (int i=1; i<=n; i++) {
        if (v.size() == 0 || v.back() != b[i]) v.push_back(b[i]);
    }
    for (int i=1; i<=n; i++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    for (int i=n; i>=1; i--) {
        long long k = get(1, 1, n, a[i] + 1, n);
        update(1, 1, n, a[i], k+1);
    }
    cout << t[1];
    return 0;
}