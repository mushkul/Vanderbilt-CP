#include <iostream>
#include <unordered_map>

int main() {
    int n, x;
    std::cin >> n >> x;
    
    std::unordered_map<int, int> index_map;
    
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        
        int complement = x - a;
        if (index_map.find(complement) != index_map.end()) {
            std::cout << index_map[complement] + 1 << " " << i + 1 << "\n";
            return 0;
        }
        
        index_map[a] = i;
    }
    
    std::cout << "IMPOSSIBLE\n";
    return 0;
}