#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    long long moves = 0;
    for (int i = 1; i < n; ++i) {
        if (array[i] < array[i-1]) {
            moves += array[i-1] - array[i];
            array[i] = array[i-1];
        }
    }

    std::cout << moves << std::endl;
    return 0;
}