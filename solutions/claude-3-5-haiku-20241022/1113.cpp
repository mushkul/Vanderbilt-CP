#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    
    int n = s.length() - 1;
    std::vector<std::string> rotations;
    
    for (int i = 0; i < n + 1; ++i) {
        rotations.push_back(s.substr(i) + s.substr(0, i));
    }
    
    std::sort(rotations.begin(), rotations.end());
    
    std::string result;
    for (const auto& rotation : rotations) {
        result += rotation.back();
    }
    
    for (int i = 0; i < n; ++i) {
        if (result.substr(i) + result.substr(0, i) == s) {
            std::cout << result.substr(0, n) << std::endl;
            break;
        }
    }
    
    return 0;
}