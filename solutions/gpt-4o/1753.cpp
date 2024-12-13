#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s, pattern;
    std::cin >> s >> pattern;
    int m = pattern.size();
    int n = s.size();
    int count = 0;

    std::vector<int> lps(m, 0);
    int j = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[j]) {
            lps[i++] = ++j;
        } else if (j) {
            j = lps[j - 1];
        } else {
            lps[i++] = 0;
        }
    }

    i = 0, j = 0;
    while (i < n) {
        if (s[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && s[i] != pattern[j]) {
            if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}