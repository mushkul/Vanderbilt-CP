#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> char_count(26, 0);
    
    for (char c : s) {
        char_count[c - 'A']++;
    }
    
    int odd_count = 0;
    char odd_char;
    
    for (int i = 0; i < 26; i++) {
        if (char_count[i] % 2 == 1) {
            odd_count++;
            odd_char = i + 'A';
        }
    }
    
    if (odd_count > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    string first_half;
    
    for (int i = 0; i < 26; i++) {
        first_half += string(char_count[i] / 2, i + 'A');
    }
    
    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());
    
    if (odd_count == 1) {
        cout << first_half + odd_char + second_half;
    } else {
        cout << first_half + second_half;
    }
    
    return 0;
}