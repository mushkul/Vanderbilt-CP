#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> prufer(n - 2);
    std::vector<int> degree(n + 1, 1);
    std::set<int> leaves;
    
    for (int i = 0; i < n - 2; ++i) {
        std::cin >> prufer[i];
        degree[prufer[i]]++;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            leaves.insert(i);
        }
    }
    
    std::vector<std::pair<int, int>> edges;
    
    for (int i = 0; i < n - 2; ++i) {
        int u = *leaves.begin();
        leaves.erase(leaves.begin());
        int v = prufer[i];
        edges.emplace_back(u, v);
        
        degree[v]--;
        if (degree[v] == 1) {
            leaves.insert(v);
        }
    }
    
    int u = *leaves.begin();
    leaves.erase(leaves.begin());
    int v = *leaves.begin();
    edges.emplace_back(u, v);
    
    for (const auto& edge : edges) {
        std::cout << edge.first << " " << edge.second << "\n";
    }
    
    return 0;
}