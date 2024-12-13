#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    long long max_sum = arr[0], current_sum = arr[0];
    for (int i = 1; i < n; ++i) {
        current_sum = std::max((long long)arr[i], current_sum + arr[i]);
        max_sum = std::max(max_sum, current_sum);
    }

    std::cout << max_sum << std::endl;
    return 0;
}