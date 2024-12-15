#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, n;
    std::cin >> x >> n;
    std::vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> positions[i];
    }

    std::set<int> lights;
    lights.insert(0);
    lights.insert(x);
    std::multiset<int> lengths;
    lengths.insert(x);

    for (int i = 0; i < n; ++i) {
        auto pos = positions[i];
        auto it = lights.lower_bound(pos);
        int right = *it;
        int left = *(--it);

        lengths.erase(lengths.find(right - left));
        lengths.insert(pos - left);
        lengths.insert(right - pos);

        lights.insert(pos);

        std::cout << *lengths.rbegin() << " ";
    }

    return 0;
}