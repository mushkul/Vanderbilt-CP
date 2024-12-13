#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<long long> times(n);
    for (int i = 0; i < n; i++) {
        std::cin >> times[i];
    }
    
    std::sort(times.begin(), times.end());
    
    long long total_time = 0;
    long long max_time = 0;
    
    for (int i = 0; i < n; i++) {
        total_time += times[i];
        max_time = std::max(max_time, (i + 1 < n ? total_time + times[i + 1] : total_time));
    }
    
    std::cout << max_time << std::endl;
    
    return 0;
}