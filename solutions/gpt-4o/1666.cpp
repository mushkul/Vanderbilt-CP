#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent, rank_set;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank_set[a] < rank_set[b])
            swap(a, b);
        parent[b] = a;
        if (rank_set[a] == rank_set[b])
            rank_set[a]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    rank_set.resize(n + 1, 0);
    
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);
    }
    
    vector<int> components;
    for (int i = 1; i <= n; i++) {
        if (find_set(i) == i)
            components.push_back(i);
    }
    
    cout << components.size() - 1 << endl;
    for (size_t i = 1; i < components.size(); i++) {
        cout << components[i - 1] << " " << components[i] << endl;
    }
    
    return 0;
}