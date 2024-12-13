#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::multiset<int> towers;
    for (int i = 0; i < n; ++i) {
        int cube;
        std::cin >> cube;
        auto it = towers.upper_bound(cube);
        if (it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(cube);
    }
    std::cout << towers.size() << "\n";
    return 0;
}