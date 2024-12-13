#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> subtree_size, distance_sum, result;
int n;

void dfs1(int node, int parent) {
    subtree_size[node] = 1;
    for (int neighbor : tree[node]) {
        if (neighbor == parent) continue;
        dfs1(neighbor, node);
        subtree_size[node] += subtree_size[neighbor];
        distance_sum[node] += distance_sum[neighbor] + subtree_size[neighbor];
    }
}

void dfs2(int node, int parent) {
    result[node] = distance_sum[node];
    for (int neighbor : tree[node]) {
        if (neighbor == parent) continue;
        int parent_distance = distance_sum[node];
        int child_distance = distance_sum[neighbor];
        int parent_size = subtree_size[node];
        int child_size = subtree_size[neighbor];

        // move the root to neighbor
        distance_sum[node] -= child_distance + child_size;
        subtree_size[node] -= child_size;
        distance_sum[neighbor] += parent_distance - (child_distance + child_size);
        subtree_size[neighbor] += parent_size - child_size;

        dfs2(neighbor, node);

        // restore the original sums and sizes after recursive call
        distance_sum[neighbor] -= parent_distance - (child_distance + child_size);
        subtree_size[neighbor] -= parent_size - child_size;
        distance_sum[node] += child_distance + child_size;
        subtree_size[node] += child_size;
    }
}

int main() {
    cin >> n;
    tree.resize(n);
    subtree_size.resize(n);
    distance_sum.resize(n);
    result.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}