#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    int odd_count = 0;
    char mid_char = ' ';
    
    for (auto& p : freq) {
        if (p.second % 2 != 0) {
            odd_count++;
            mid_char = p.first;
        }
    }
    
    if (odd_count > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    
    string left = "", right = "";
    
    for (auto& p : freq) {
        int count = p.second / 2;
        string repeated(count, p.first);
        left += repeated;
    }
    
    right = left;
    reverse(right.begin(), right.end());
    
    if (mid_char != ' ') {
        int mid_count = freq[mid_char];
        string mid_repeated(mid_count, mid_char);
        left += mid_repeated;
    }
    
    cout << left + right << endl;
    return 0;
}