#include<bits/stdc++.h>
using namespace std;
template<class T> struct dsu {
	vector<T> p, r; T n; dsu(T _n) :n(_n) { p = r = vector<T>(n); iota(p.begin(), p.end(), 0); }
	T find(T x) { return (p[x] == x) ? x : (p[x] = find(p[x])); }
	bool merge(T x, T y) {
		x = find(x); y = find(y);
		if (x == y) return 0;
		if (r[x] < r[y]) swap(x, y);
		p[y] = x;
		if (r[x] == r[y]) r[x]++;
		return 1;
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        --edges[i].first; --edges[i].second;
    }
    reverse(edges.begin(), edges.end());
    dsu<int> d(n);
    vector<int> ans(m + 1, -1);
    for (int i = 0; i < m; i++) { if (d.merge(edges[i].first, edges[i].second)) ans[i + 1] = i; else ans[i + 1] = ans[i]; }
    vector<int> queries(m + 1, -1);
    vector<vector<pair<int, int>>> query(n);
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; --u; --v;
        query[d.find(u)].push_back({ d.find(v), i });
    }
    for (int x = 0; x < n; x++)
        for (auto&& i : query[x])
            for (int b = m, a; b >= 0; b = a - 1) {
                a = queries[lower_bound(queries.begin(), queries.begin() + b, ans[d.find(i.first)]) - queries.begin()];
                if (ans[d.find(i.first)] <= a) { queries[i.second] = b + 1; break; }
            }
    for (int i = 0; i < q; i++) cout << queries[i] << "\n";
    return 0;
}