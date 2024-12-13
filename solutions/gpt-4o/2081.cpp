#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int subtreeSize[MAXN];
bool visited[MAXN];
int n, k1, k2;
long long result;

void calculateSubtreeSizes(int node, int par) {
    subtreeSize[node] = 1;
    for (int child : tree[node]) {
        if (child != par && !visited[child]) {
            calculateSubtreeSizes(child, node);
            subtreeSize[node] += subtreeSize[child];
        }
    }
}

int findCentroid(int node, int par, int size) {
    for (int child : tree[node]) {
        if (child != par && !visited[child] && subtreeSize[child] > size / 2) {
            return findCentroid(child, node, size);
        }
    }
    return node;
}

void countPaths(int node, int par, int depth, vector<int>& depthCount, int op) {
    if (depth > k2) return;
    if (op == 1) {
        result += depthCount[k2 - depth + 1] - (k1 - depth > 1 ? depthCount[k1 - depth] : 0);
    } else {
        while (depthCount.size() <= depth) depthCount.push_back(0);
        depthCount[depth]++;
    }
    for (int child : tree[node]) {
        if (child != par && !visited[child]) countPaths(child, node, depth + 1, depthCount, op);
    }
}

void decompose(int node) {
    calculateSubtreeSizes(node, -1);
    int centroid = findCentroid(node, -1, subtreeSize[node]);
    visited[centroid] = true;

    for (int child : tree[centroid]) {
        if (!visited[child]) {
            vector<int> depthCount(1, 0);
            countPaths(child, centroid, 1, depthCount, 1);
            countPaths(child, centroid, 1, vector<int>(1, 0), 0);
        }
    }

    result += accumulate(depthCount.begin() + max(k1, 1) - 1, depthCount.begin() + k2 + 1, 0LL);
    for (int child : tree[centroid]) {
        if (!visited[child]) decompose(child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k1 >> k2;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    result = 0;
    memset(visited, false, sizeof(visited));
    decompose(1);
    
    cout << result << "\n";
    return 0;
}