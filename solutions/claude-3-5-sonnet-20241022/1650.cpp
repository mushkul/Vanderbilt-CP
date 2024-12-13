#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> prefix(n + 1);
    prefix[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        prefix[i] = prefix[i-1] ^ x;
    }
    
    while (q--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (prefix[b] ^ prefix[a-1]) << '\n';
    }
    
    return 0;
}