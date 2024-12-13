#include <iostream>
#include <vector>
#include <string>

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
    
    int n = s.length();
    vector<int> z = compute_z_function(s);
    
    vector<int> periods;
    for (int i = 1; i <= n; i++) {
        int j = n - i;
        if (z[j] >= i) {
            periods.push_back(i);
        }
    }
    
    for (int period : periods) {
        cout << period << " ";
    }
    cout << endl;
    
    return 0;
}