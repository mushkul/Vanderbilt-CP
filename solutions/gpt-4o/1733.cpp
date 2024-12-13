#include <iostream>
#include <vector>
#include <string>

std::vector<int> computePrefixFunction(const std::string &s) {
    int n = s.length();
    std::vector<int> pi(n);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<int> pi = computePrefixFunction(s);
    for (int i = 1; i <= n; ++i) {
        if (i % (i - pi[i - 1]) == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}