#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<long long> sticks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sticks[i];
    }
    
    std::sort(sticks.begin(), sticks.end());
    
    long long target = sticks[n/2];
    long long total_cost = 0;
    
    for (int i = 0; i < n; i++) {
        total_cost += std::abs(sticks[i] - target);
    }
    
    std::cout << total_cost << std::endl;
    
    return 0;
}