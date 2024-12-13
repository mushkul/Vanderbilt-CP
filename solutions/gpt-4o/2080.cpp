#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int cnt[MAXN], sub[MAXN];
int n, k;

void countSubtreeSize(int node, int parent) {
    sub[node] = 1;
    for (int neighbor : tree[node]) {
        if (neighbor == parent) continue;
        countSubtreeSize(neighbor, node);
        sub[node] += sub[neighbor];
    }
}

void resetCounters(int node, int parent, int dist) {
    cnt[dist]--;
    for (int neighbor : tree[node]) {
        if (neighbor != parent) resetCounters(neighbor, node, dist + 1);
    }
}

void computePathCount(int node, int parent, int dist, long long &result) {
    if (dist > k) return;
    result += cnt[k - dist];
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            computePathCount(neighbor, node, dist + 1, result);
        }
    }
}

void dfs(int node, int parent, bool keep, long long &result) {
    int heavy = -1, maxSubtreeSize = -1;
    for (int neighbor : tree[node]) {
        if (neighbor == parent) continue;
        if (sub[neighbor] > maxSubtreeSize) {
            maxSubtreeSize = sub[neighbor];
            heavy = neighbor;
        }
    }
    for (int neighbor : tree[node]) {
        if (neighbor != parent && neighbor != heavy) {
            dfs(neighbor, node, false, result);
        }
    }
    if (heavy != -1) {
        dfs(heavy, node, true, result);
    }
    for (int neighbor : tree[node]) {
        if (neighbor != parent && neighbor != heavy) {
            computePathCount(neighbor, node, 1, result);
            for (int j = 1; j <= n; ++j) {
                if (j - 1 <= k) {
                    cnt[j]++;
                }
            }
        }
    }
    cnt[0]++;
    if (!keep) {
        resetCounters(node, parent, 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    countSubtreeSize(1, -1);
    
    long long result = 0;
    dfs(1, -1, false, result);
    
    cout << result / 2 << "\n";
    
    return 0;
}