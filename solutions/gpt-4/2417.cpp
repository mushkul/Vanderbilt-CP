#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, x[N], mxd, cnt[N];
long long ans;
vector<int> pri, vis(N), mu(N);
void get_mu() {
    mu[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) pri.push_back(i), mu[i] = -1;
        for (int j = 0; j < pri.size() && i * pri[j] < N; j++) {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) { mu[i * pri[j]] = 0; break; }
            mu[i * pri[j]] = -mu[i];
        }
    }
}
vector<int> fact[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    get_mu();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        mxd = max(mxd, x[i]);
        for (int j = 1; j * j <= x[i]; j++) 
            if (x[i] % j == 0) {
                fact[x[i]].push_back(j);
                if (j * j != x[i]) fact[x[i]].push_back(x[i] / j);
            }
    }
    for (int i = 1; i <= n; i++) {
        for (int j : fact[x[i]]) ans += mu[j] * cnt[j], cnt[j]++;
    }
    cout << ans << '\n';
    return 0;
}