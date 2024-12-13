#include <iostream>
#include <string>
#include <unordered_set>

void deBruijn(int n, std::string &s, std::unordered_set<std::string> &visited, std::string &result) {
    if (result.size() == (1 << n) + n - 1) return;
    std::string next = s.substr(s.size() - n + 1);
    for (char c : {'0', '1'}) {
        std::string candidate = next + c;
        if (!visited.count(candidate)) {
            visited.insert(candidate);
            result.push_back(c);
            deBruijn(n, candidate, visited, result);
            if (result.size() == (1 << n) + n - 1) return;
            result.pop_back();
            visited.erase(candidate);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::string result(n, '0');
    std::unordered_set<std::string> visited;
    visited.insert(result);
    deBruijn(n, result, visited, result);
    std::cout << result << std::endl;
    return 0;
}