#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool hasRepeatingSubstring(const string &s, int length) {
    unordered_map<string, int> seen;
    for (int i = 0; i <= s.length() - length; ++i) {
        string substr = s.substr(i, length);
        if (seen.count(substr)) {
            return true;
        }
        seen[substr]++;
    }
    return false;
}

string longestRepeatingSubstring(const string &s) {
    int left = 0, right = s.length();
    string result = "";
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (hasRepeatingSubstring(s, mid)) {
            if (mid > result.size()) {
                for (int i = 0; i <= s.length() - mid; ++i) {
                    string substr = s.substr(i, mid);
                    if (s.find(substr, i + 1) != string::npos) {
                        result = substr;
                        break;
                    }
                }
            }
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (result.empty()) {
        return "-1";
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << longestRepeatingSubstring(s) << endl;
    return 0;
}