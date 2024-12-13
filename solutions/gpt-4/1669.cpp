C++
#include<bits/stdc++.h>
using namespace std;
int n, m, i, j, p[100010], visited[100010], cycle_start, cycle_end;
vector<int> adj[100010];
bool dfs(int v, int par) {
	visited[v] = 1;
	for (int u : adj[v]) {
		if(u == par) continue;
		if (visited[u]) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
		p[u] = v;
		if (dfs(u, p[u])) return true;
	}
	return false;
}
void find_cycle() {
	memset(visited, 0, sizeof visited);
	memset(p, -1, sizeof p);
	cycle_start = -1;
	for (i = 1; i <= n; i++) {
		if (visited[i]) continue;
		if (dfs(i, p[i])) break;
	}
	if (cycle_start == -1) {
		puts("IMPOSSIBLE");
		return;
	}
	vector<int> cycle;
	cycle.push_back(cycle_start);
	for (i = cycle_end; i != cycle_start; i = p[i])
		cycle.push_back(i);
	cycle.push_back(cycle_start);
	cout << cycle.size() << "\n";
	for (i = cycle.size()-1; i >=0; --i)
		cout << cycle[i] << ' ';
}
int main() {
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	find_cycle();
}