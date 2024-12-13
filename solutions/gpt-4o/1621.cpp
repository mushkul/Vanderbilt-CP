#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;
    std::unordered_set<int> distinct;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        distinct.insert(x);
    }
    std::cout << distinct.size() << std::endl;
    return 0;
}