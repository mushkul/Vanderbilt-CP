#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    std::sort(p.begin(), p.end());
    int i = 0, j = n - 1;
    int gondolas = 0;
    while (i <= j) {
        if (p[i] + p[j] <= x) {
            ++i;
        }
        --j;
        ++gondolas;
    }
    std::cout << gondolas << '\n';
    return 0;
}