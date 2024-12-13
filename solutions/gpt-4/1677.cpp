#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<int> parent;
int n, m, k;
vector<int> rnk;
vector<pair<int,int>> edge;
vector<vector<int>> g;
vector<bool> visit, ed;

int find(int x) {
	while (x != parent[x]) {
		x = parent[x] = parent[parent[x]];
	}
	return x;
}

void unite(int a, int b){
	int x = find(a);
	int y = find(b);
	if (x != y) {
		if (rnk[x] > rnk[y]) {
			parent[y] = x;
			rnk[x] += rnk[y];
		} else {
			parent[x] = y;
			rnk[y] += rnk[x];
		}
	}
}

void dfs(int v) {
	visit[v] = true;
	for (auto i : g[v])
		if (!visit[i]){
			parent[i] = parent[v];
			dfs(i);
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	parent.resize(n + 1);
	g.resize(n + 1);
	visit.assign(n + 1, false);
	ed.assign(m, false);
	rnk.assign(n + 1, 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	vector<int> a(m), b(m), pos(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i]; a[i]--; b[i]--;
		pos[i] = i;
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
		edge.push_back(make_pair(a[i], b[i]));
	}
	sort(pos.begin(), pos.end(), [&](int i, int j){ return a[i] < a[j] || (a[i] == a[j] && b[i] < b[j]); });
	vector<int> lose(k);
	for (int i = 0; i < k; i++)
		cin >> lose[i];
	for (int i = 0; i < k; i++) lose[i]=lower_bound(pos.begin(),pos.end(),lose[i]-1,[&](int i, int j){ return a[i] < a[j] || (a[i] == a[j] && b[i] < b[j]); })-pos.begin();
	reverse(lose.begin(), lose.end());
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		ed[lose[i]] = true;
	}
	int j = 0;
	for (int i = 0; i < m; i++) {
		if (!ed[i]) {
			unite(edge[i].first, edge[i].second);
		}
	}
	for (int i = 0; i < n; i++) if (!visit[i]){
		dfs(i);
		j++;
	}
	ans.push_back(j);
	for (int i = 0; i < k - 1; i++) {
		if (find(edge[lose[i]].first) != find(edge[lose[i]].second)) {
			unite(edge[lose[i]].first, edge[lose[i]].second);
			ans.push_back(--j);
		}
		else
			ans.push_back(j);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < k; i++) cout<<ans[i]<<"\n";
	return 0;
}