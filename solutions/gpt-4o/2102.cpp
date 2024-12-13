#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    unordered_set<string> patterns;
    vector<string> inputPatterns(k);
    
    for (int i = 0; i < k; ++i) {
        cin >> inputPatterns[i];
    }

    for (const string& pat : inputPatterns) {
        if (s.find(pat) != string::npos) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}