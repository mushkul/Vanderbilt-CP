#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    std::set<std::string> permutations;
    std::sort(s.begin(), s.end());
    do {
        permutations.insert(s);
    } while (std::next_permutation(s.begin(), s.end()));
    
    std::cout << permutations.size() << "\n";
    for (const std::string& perm : permutations) {
        std::cout << perm << "\n";
    }

    return 0;
}