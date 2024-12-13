#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) : parent(n), size(n, 1) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int a) {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    bool unite(int a, int b, int &maxSize) {
        int rootA = find(a), rootB = find(b);
        if(rootA == rootB) return false;
        if(size[rootA] < size[rootB]) swap(rootA, rootB);
        parent[rootB] = rootA;
        size[rootA] += size[rootB];
        maxSize = max(maxSize, size[rootA]);
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    int numComponents = n, maxSize = 1;

    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // To convert to 0-indexing
        if(dsu.unite(a, b, maxSize))
            numComponents--;
        cout << numComponents << " " << maxSize << endl;
    }

    return 0;
}