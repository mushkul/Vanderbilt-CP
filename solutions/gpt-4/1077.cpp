#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define st first
#define nd second

const int maxN = 2e5 + 5;
int n, k, arr[maxN];
pii data[maxN];
multiset<ll> val;
vector<ll> mini(maxN);
vector<ll> pre(maxN), suf(maxN);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		data[i] = {arr[i], i};
	sort(data, data + n);
	for (int i = 0; i < n; i++) {
		if ((int)val.size() < k) {
			val.insert(data[i].st);
			mini[data[i].nd] = *val.rbegin();
			continue;
		}
		val.erase(val.find(data[i - k].st));
		val.insert(data[i].st);
		mini[data[i].nd] = *val.rbegin();
	}
	val.clear();
	for (int i = n - 1; i >= 0; i--) {
		if (n - i <= k) {
			val.insert(data[i].st);
			mini[data[i].nd] = min(mini[data[i].nd], *val.begin());
			continue;
		}
		val.erase(val.find(data[i + k].st));
		val.insert(data[i].st);
		mini[data[i].nd] = min(mini[data[i].nd], *val.begin());
	}
	for (int i = 0; i < n; i++) {
		if (i > 0)
			pre[i] = pre[i - 1] + arr[i];
		else
			pre[i] = arr[i];
		if (i >= k - 1) {
			int r = mini[i];
			if (i - k >= 0)
				cout << (ll)k * r - pre[i] + pre[i - k] << "\n";
			else
				cout << (ll)k * r - pre[i] << "\n";
		}
	}
}