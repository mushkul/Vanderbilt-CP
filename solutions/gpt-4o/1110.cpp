#include <iostream>
#include <string>

std::string minimal_lexicographic_rotation(const std::string& s) {
    int n = s.size();
    std::string ss = s + s;
    int start = 0;
    for (int i = 1, j = 0; i < n; ++i) {
        while (j < n && ss[start + j] == ss[i + j]) ++j;
        if (j >= n) break;
        if (ss[start + j] > ss[i + j])
            start = i, j = 0;
    }
    return ss.substr(start, n);
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << minimal_lexicographic_rotation(s) << "\n";
    return 0;
}