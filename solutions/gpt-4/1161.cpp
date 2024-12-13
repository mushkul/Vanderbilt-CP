#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, n;
    cin >> x >> n;
    multiset<ll> st;
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        st.insert(a);
    }
    ll cost = 0;
    while (st.size() > 1) {
        ll a = *st.begin();
        st.erase(st.begin());
        ll b = *st.begin();
        st.erase(st.begin());
        ll s = a + b;
        st.insert(s);
        cost += s;
    }
    cout << cost;

    return 0;
}