#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    string best = "";
    
    for (int k = 0; k < n; k++) {
        // Odd length palindromes
        for (int j = 0; k - j >= 0 && k + j < n; j++) {
            if (s[k-j] != s[k+j]) break;
            string curr = s.substr(k-j, 2*j+1);
            if (curr.length() > best.length()) best = curr;
        }
        
        // Even length palindromes
        for (int j = 0; k - j >= 0 && k + j + 1 < n; j++) {
            if (s[k-j] != s[k+j+1]) break;
            string curr = s.substr(k-j, 2*j+2);
            if (curr.length() > best.length()) best = curr;
        }
    }
    
    return best.empty() ? s.substr(0, 1) : best;
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}