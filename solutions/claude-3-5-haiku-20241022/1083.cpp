#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    long long totalSum = (long long)n * (n + 1) / 2;
    long long inputSum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int num;
        std::cin >> num;
        inputSum += num;
    }
    
    std::cout << totalSum - inputSum << std::endl;
    
    return 0;
}