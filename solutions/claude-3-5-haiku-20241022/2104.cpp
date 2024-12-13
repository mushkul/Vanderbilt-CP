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
        size_t pos = s.find(pattern);
        if (pos != string::npos) {
            cout << pos + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}