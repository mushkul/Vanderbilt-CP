#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    vector<pair<int, int>> edges(m);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        deg[a]++;
        deg[b]++;
    }
    
    long long exp2 = 1;
    for (int i = 0; i < m; ++i) exp2 = exp2 * 2 % MOD;
    long long odd_deg = 0;
    for (int i = 1; i <= n; ++i) if (deg[i] % 2 == 1) odd_deg++;

    long long res = exp2;
    long long sub = 1;
    for (int i = 0; i < odd_deg; ++i) sub = sub * 2 % MOD;
    res = (res - sub + MOD) % MOD;
    cout << res << "\n";
    return 0;
}