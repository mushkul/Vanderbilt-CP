#include <iostream>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;

    while (m--) {
        int a, b;
        std::cin >> a >> b;
        std::string cut = s.substr(a - 1, b - a + 1);
        s += cut;
    }

    std::cout << s << std::endl;
    return 0;
}