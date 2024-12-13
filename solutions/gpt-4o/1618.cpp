#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    long long count = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    std::cout << count << std::endl;
    return 0;
}