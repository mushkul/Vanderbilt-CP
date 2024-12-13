#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    vector<string> substrings;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i + j <= n; ++j) {
            substrings.push_back(s.substr(i, j));
        }
    }
    sort(substrings.begin(), substrings.end());
    substrings.erase(unique(substrings.begin(), substrings.end()), substrings.end());
    cout << substrings[k - 1] << endl;
    return 0;
}