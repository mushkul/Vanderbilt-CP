#include<bits/stdc++.h>
using namespace std;
#define ar array

const int MX = 2e5;

int n, m, c[MX], st[MX], t;
vector<int> g[MX], x[MX];
vector<ar<int, 2>> e;
bool vis[MX];

void dfs(int i) {
	vis[i] = 1;
	for(int j : g[i])
		if(!vis[j])
			dfs(j);
	st[t++] = i;
}

void dfs2(int i, int k) {
	c[i] = k;
	for(int j : x[i])
		if(!c[j])
			dfs2(j, k);
}

int main() {
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<2; j++) {
			int t; char a; cin >> a >> t; t--;
			e.push_back({a=='+'? t : t+m, t+m});
			swap(e.back()[0], e.back()[1]);
			x[e.back()[0]].push_back(e.back()[1]);
		}
	}
	for(int i = 0; i<=4*m-1; i++)
		if(!vis[i])
			dfs(i);
	for(ar<int, 2> a : e)
		g[a[1]].push_back(a[0]);
	for(int i = 4*m-1; i>=0; i--)
		if(!c[st[i]])
			dfs2(st[i], st[i]+1);
	for(int i = 0; i<m; i++)
		if(c[i]&&c[i+m]&&c[i]==c[i+m]) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	for(int i = 0; i<m; i++)
		cout << (c[i]>c[i+m]? '+' : '-') << " ";
}