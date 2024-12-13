#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int result = 0;
    for (int i = 0; i < n; i += 2) {
        result ^= a[i];
    }
    std::cout << result << std::endl;
    return 0;
}