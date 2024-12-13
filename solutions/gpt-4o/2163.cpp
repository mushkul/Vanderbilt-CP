#include <iostream>
#include <set>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::set<int> children;
    for (int i = 1; i <= n; ++i) {
        children.insert(i);
    }

    auto it = children.begin();
    while (!children.empty()) {
        int step = (k % children.size());
        for (int i = 0; i < step; ++i) {
            if (++it == children.end()) it = children.begin();
        }
        std::cout << *it << " ";
        it = children.erase(it);
        if (it == children.end()) it = children.begin();
    }

    return 0;
}