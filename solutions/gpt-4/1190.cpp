#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN=2e5;
int n, m, a1;
ll x, a[mxN], s[1<<19], mx[1<<19];
void build(int i=1, int l2=0, int r2=n-1) {
	if(l2==r2) {
		s[i]=mx[i]=a[l2];
		return;
	}
	int m2=(l2+r2)/2;
	build(2*i, l2, m2);
	build(2*i+1, m2+1, r2);
	s[i]=s[2*i]+s[2*i+1];
	mx[i]=max({mx[2*i], mx[2*i+1], s[2*i]+mx[2*i+1]});
}
void upd(int l1, ll x, int i=1, int l2=0, int r2=n-1) {
	if(l2==l1&&r2==l1) {
		s[i]=mx[i]=x;
		return;
	}
	int m2=(l2+r2)/2;
	if(l1<=m2)
		upd(l1, x, 2*i, l2, m2);
	else
		upd(l1, x, 2*i+1, m2+1, r2);
	s[i]=s[2*i]+s[2*i+1];
	mx[i]=max({mx[2*i], mx[2*i+1], s[2*i]+mx[2*i+1]});
}
int main() {
	cin >> n >> m;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
	}
	build();
	for(int i=0; i<m; ++i) {
		int k;
		cin >> k >> x, --k;
		upd(k,x);
		cout << max(0LL, mx[1]) << "\n";
	}
}