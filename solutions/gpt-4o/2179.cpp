#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> degree(n+1, 0);
    vector<pair<int, int>> edges(m);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        degree[a]++;
        degree[b]++;
    }
    
    vector<int> balance(n+1, 0);
    vector<pair<int, int>> result;
    
    for (auto &[a, b] : edges) {
        if (balance[a] == 0 && balance[b] == 0) {
            result.emplace_back(a, b);
            balance[a]++;
            balance[b]--;
        } else if (balance[a] == 0 || degree[a] % 2 == 0) {
            result.emplace_back(a, b);
            balance[a]++;
            balance[b]--;
        } else {
            result.emplace_back(b, a);
            balance[b]++;
            balance[a]--;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (abs(balance[i]) % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    
    for (auto &[a, b] : result) {
        cout << a << " " << b << endl;
    }
    return 0;
}