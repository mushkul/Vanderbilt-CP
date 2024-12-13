#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    
    int n = s.size();
    std::vector<int> ones;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones.push_back(i);
        }
    }
    
    std::vector<int> result(n - 1, 0);
    
    for (int i = 0; i < ones.size(); ++i) {
        for (int j = i + 1; j < ones.size(); ++j) {
            int k = ones[j] - ones[i];
            if (k < n) {
                result[k - 1]++;
            } else {
                break;
            }
        }
    }
    
    for (int i = 0; i < n - 1; ++i) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}