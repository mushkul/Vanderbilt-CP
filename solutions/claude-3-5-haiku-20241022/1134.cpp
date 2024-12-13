#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> prufer(n-2);
    for (int i = 0; i < n-2; i++) {
        cin >> prufer[i];
    }
    
    vector<int> degree(n+1, 1);
    for (int x : prufer) {
        degree[x]++;
    }
    
    vector<vector<int>> edges;
    
    for (int i = 0; i < n-2; i++) {
        for (int j = 1; j <= n; j++) {
            if (degree[j] == 1 && j != prufer[i]) {
                edges.push_back({j, prufer[i]});
                degree[j]--;
                degree[prufer[i]]--;
                break;
            }
        }
    }
    
    for (int j = 1; j <= n; j++) {
        if (degree[j] == 1) {
            for (int k = j+1; k <= n; k++) {
                if (degree[k] == 1) {
                    edges.push_back({j, k});
                    break;
                }
            }
        }
    }
    
    for (auto& edge : edges) {
        cout << edge[0] << " " << edge[1] << "\n";
    }
    
    return 0;
}