#include <iostream>
#include <vector>
#include <string>

std::vector<int> computePrefixFunction(const std::string& s) {
    int n = s.length();
    std::vector<int> pi(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

std::vector<int> findBorders(const std::string& s) {
    int n = s.length();
    std::vector<int> pi = computePrefixFunction(s);
    std::vector<int> borders;
    int borderLength = pi[n - 1];
    while (borderLength > 0) {
        borders.push_back(borderLength);
        borderLength = pi[borderLength - 1];
    }
    std::reverse(borders.begin(), borders.end());
    return borders;
}

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> borders = findBorders(s);
    for (int length : borders) {
        std::cout << length << " ";
    }
    return 0;
}