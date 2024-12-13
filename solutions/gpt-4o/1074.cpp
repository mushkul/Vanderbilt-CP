#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    std::sort(p.begin(), p.end());
    int median = p[n / 2];
    long long cost = 0;
    for (int length : p) {
        cost += std::abs(length - median);
    }
    std::cout << cost << std::endl;
    return 0;
}