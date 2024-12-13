#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
ll n, k;
vector<ll> v;
 
bool check(ll mid) {
	ll cnt = 1, sum = 0;
	for(ll i = 0; i < n; i++) {
		if(sum + v[i] > mid) {
			cnt++;
			sum = v[i];
		} else
			sum += v[i];
	}
	return cnt <= k;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	v.resize(n);
	ll l = -1;
	for(ll i = 0; i < n; i++) {
		cin >> v[i];
		l = max(l, v[i]);
	}
	ll r = 1e18;
	while(r - l > 1) {
		ll mid = l + (r - l) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << '\n';
	return 0;
}