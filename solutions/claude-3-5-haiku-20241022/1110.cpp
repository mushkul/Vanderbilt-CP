#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string minimal_rotation(string s) {
    s += s;
    int n = s.length() / 2;
    int best_start = 0;
    
    for (int i = 1; i < n; i++) {
        if (s.substr(i, n) < s.substr(best_start, n)) {
            best_start = i;
        }
    }
    
    return s.substr(best_start, n);
}

int main() {
    string s;
    cin >> s;
    cout << minimal_rotation(s) << endl;
    return 0;
}