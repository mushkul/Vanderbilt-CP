#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[100010], y[100010];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, i, boundary = 0, area = 0;
    cin >> n;
    for(i=0; i<n; i++) cin >> x[i] >> y[i];
    for(i=0; i<n; i++) {
        ll j = (i+1)%n;
        boundary += gcd(abs(x[i]-x[j]), abs(y[i]-y[j]));
        area += (x[j]+x[i])*(y[j]-y[i]);
    }
    cout << abs(area)/2 - boundary/2 + 1 << " " << boundary << "\n";
    return 0;
}