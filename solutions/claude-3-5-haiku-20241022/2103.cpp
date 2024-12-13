#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    vector<string> patterns(k);
    for (int i = 0; i < k; i++) {
        cin >> patterns[i];
    }
    
    for (const string& pattern : patterns) {
        int count = 0;
        for (size_t j = 0; j + pattern.length() <= s.length(); j++) {
            if (s.substr(j, pattern.length()) == pattern) {
                count++;
            }
        }
        cout << count << endl;
    }
    
    return 0;
}