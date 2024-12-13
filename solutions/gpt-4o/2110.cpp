#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    for (int len = 1; len <= n; ++len) {
        unordered_set<string> substrings;
        for (int i = 0; i <= n - len; ++i) {
            substrings.insert(s.substr(i, len));
        }
        cout << substrings.size() << " ";
    }
    
    return 0;
}