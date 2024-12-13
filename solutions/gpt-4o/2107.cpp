#include <iostream>
#include <vector>
#include <string>

std::vector<int> calculateZ(const std::string &s) {
    int n = s.size();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

std::vector<int> calculatePi(const std::string &s) {
    int n = s.size();
    std::vector<int> pi(n);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

int main() {
    std::string s;
    std::cin >> s;
    
    auto z = calculateZ(s);
    auto pi = calculatePi(s);

    for (int i = 0; i < s.size(); ++i) {
        std::cout << z[i] << (i + 1 == s.size() ? '\n' : ' ');
    }

    for (int i = 0; i < s.size(); ++i) {
        std::cout << pi[i] << (i + 1 == s.size() ? '\n' : ' ');
    }

    return 0;
}