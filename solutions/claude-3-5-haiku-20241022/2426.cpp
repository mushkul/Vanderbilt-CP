#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a, b, n;
    std::cin >> a >> b >> n;
    
    std::vector<std::pair<int, int>> applicants(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> applicants[i].first >> applicants[i].second;
    }
    
    std::sort(applicants.begin(), applicants.end(), [](const auto& x, const auto& y) {
        return x.first + x.second > y.first + y.second;
    });
    
    long long total_skills = 0;
    
    for (int i = 0; i < a; i++) {
        total_skills += applicants[i].first;
    }
    
    for (int i = a; i < a + b; i++) {
        total_skills += applicants[i].second;
    }
    
    std::cout << total_skills << std::endl;
    
    return 0;
}