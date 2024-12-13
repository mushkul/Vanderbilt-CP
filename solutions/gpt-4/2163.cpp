#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    set<ll> s;
    for(ll i=1;i<=n;++i) s.insert(i);
    auto it=s.begin();
    while(!s.empty()) {
        it = s.erase(it);
        if(it == s.end()) it = s.begin();
        ll skip = k%s.size();
        advance(it, skip);
        if(it == s.end()) it = s.begin();
        cout << *it << ' ';
    }
    return 0;
}