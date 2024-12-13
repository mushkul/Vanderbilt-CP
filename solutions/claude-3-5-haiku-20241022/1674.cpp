#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int subordinates[MAXN];

int dfs(int node) {
    int total = 0;
    for (int child : graph[node]) {
        total += dfs(child) + 1;
    }
    subordinates[node] = total;
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        graph[boss].push_back(i);
    }
    
    dfs(1);
    
    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    
    return 0;
}