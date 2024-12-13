#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> colors;
vector<vector<int>> tree;
vector<unordered_set<int>> colorSets;
vector<int> result;

void dfs(int node, int parent) {
    colorSets[node].insert(colors[node]);
    for (int neighbor : tree[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
        if (colorSets[neighbor].size() > colorSets[node].size()) {
            swap(colorSets[node], colorSets[neighbor]);
        }
        colorSets[node].insert(colorSets[neighbor].begin(), colorSets[neighbor].end());
    }
    result[node] = colorSets[node].size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    colors.resize(n + 1);
    tree.resize(n + 1);
    colorSets.resize(n + 1);
    result.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> colors[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    
    return 0;
}