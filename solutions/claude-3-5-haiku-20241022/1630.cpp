#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> tasks(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> tasks[i].first >> tasks[i].second;
    }
    
    std::sort(tasks.begin(), tasks.end());
    
    long long reward = 0;
    long long currentTime = 0;
    
    for (auto& task : tasks) {
        currentTime += task.first;
        reward += task.second - currentTime;
    }
    
    std::cout << reward << std::endl;
    
    return 0;
}