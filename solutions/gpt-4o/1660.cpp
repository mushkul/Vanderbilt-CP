#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long x;
    std::cin >> n >> x;
    
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::unordered_map<long long, int> prefix_sum_count;
    long long current_prefix_sum = 0;
    int subarrays_count = 0;

    prefix_sum_count[0] = 1; // to count subarrays starting from index 0

    for (int i = 0; i < n; ++i) {
        current_prefix_sum += a[i];

        long long needed_prefix_sum = current_prefix_sum - x;
        if (prefix_sum_count.find(needed_prefix_sum) != prefix_sum_count.end()) {
            subarrays_count += prefix_sum_count[needed_prefix_sum];
        }

        ++prefix_sum_count[current_prefix_sum];
    }

    std::cout << subarrays_count << "\n";

    return 0;
}