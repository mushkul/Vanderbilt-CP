#include <bits/stdc++.h>

std::vector<int> countDivisors(int max_x) {
    std::vector<int> divisors(max_x + 1, 0);
    for (int i = 1; i <= max_x; ++i) {
        for (int j = i; j <= max_x; j += i) {
            divisors[j]++;
        }
    }
    return divisors;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> numbers(n);
    int max_x = 0;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
        if (numbers[i] > max_x) {
            max_x = numbers[i];
        }
    }
    
    std::vector<int> divisors = countDivisors(max_x);
    
    for (int i = 0; i < n; ++i) {
        std::cout << divisors[numbers[i]] << "\n";
    }
    
    return 0;
}