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
        if (s.find(pattern) != string::npos) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}