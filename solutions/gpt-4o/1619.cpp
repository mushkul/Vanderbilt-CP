#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }
    std::sort(events.begin(), events.end());
    
    int current_customers = 0, max_customers = 0;
    for (auto &event : events) {
        current_customers += event.second;
        max_customers = std::max(max_customers, current_customers);
    }
    
    std::cout << max_customers << std::endl;
    return 0;
}