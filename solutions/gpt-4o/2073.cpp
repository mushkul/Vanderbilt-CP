#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        std::reverse(s.begin() + a - 1, s.begin() + b);
    }
    std::cout << s << '\n';
    return 0;
}