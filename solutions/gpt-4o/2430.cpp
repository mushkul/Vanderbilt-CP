#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string result;
    
    while (n > 0) {
        int bits = 1;
        while ((1 << bits) - 1 <= n) {
            bits++;
        }
        bits--;
        result += '1';
        for (int i = 1; i < bits; i++) {
            result += '0';
        }
        n -= (1 << bits) - 1;
    }

    std::cout << result << std::endl;

    return 0;
}