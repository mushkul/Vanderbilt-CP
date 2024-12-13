#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> signal(n);
    std::vector<int> mask(m);
    for (int i = 0; i < n; ++i) std::cin >> signal[i];
    for (int i = 0; i < m; ++i) std::cin >> mask[i];

    std::vector<int> result(n + m - 1, 0);
    
    for (int i = 0; i < n + m - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i - j >= 0 && i - j < n) {
                result[i] += signal[i - j] * mask[j];
            }
        }
    }
    
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}