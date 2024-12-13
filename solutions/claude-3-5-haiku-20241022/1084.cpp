#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> applicants(n);
    std::vector<int> apartments(m);

    for (int i = 0; i < n; i++) {
        std::cin >> applicants[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> apartments[i];
    }

    std::sort(applicants.begin(), applicants.end());
    std::sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, count = 0;

    while (i < n && j < m) {
        if (std::abs(applicants[i] - apartments[j]) <= k) {
            count++;
            i++;
            j++;
        }
        else if (applicants[i] < apartments[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}