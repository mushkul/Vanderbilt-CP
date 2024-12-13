#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> compute_z_function(const string& s) {
    int n = s.length();
    vector<int> z(n);
    int left = 0, right = 0;
    
    for (int i = 1; i < n; i++) {
        if (i > right) {
            left = right = i;
            while (right < n && s[right - left] == s[right]) {
                right++;
            }
            z[i] = right - left;
            right--;
        } else {
            int k = i - left;
            if (z[k] < right - i + 1) {
                z[i] = z[k];
            } else {
                left = i;
                while (right < n && s[right - left] == s[right]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    
    vector<int> z = compute_z_function(s);
    vector<int> borders;
    
    for (int i = 1; i < s.length(); i++) {
        if (z[i] == s.length() - i && s.length() - i > 0) {
            borders.push_back(s.length() - i);
        }
    }
    
    sort(borders.begin(), borders.end());
    
    for (int border : borders) {
        cout << border << " ";
    }
    
    return 0;
}