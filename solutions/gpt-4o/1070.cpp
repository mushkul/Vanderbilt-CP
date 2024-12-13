#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << "1\n";
        return 0;
    }

    if (n < 4) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 2; i <= n; i += 2) {
        std::cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}