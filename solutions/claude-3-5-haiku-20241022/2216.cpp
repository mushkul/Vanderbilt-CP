#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        pos[x] = i;
    }
    
    int rounds = 1;
    int current = 0;
    
    for (int i = 1; i <= n; i++) {
        if (pos[i] < current) {
            rounds++;
        }
        current = pos[i];
    }
    
    std::cout << rounds << std::endl;
    
    return 0;
}