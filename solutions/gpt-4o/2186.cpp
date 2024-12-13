#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int countSpecialSubstrings(const string& s) {
    int n = s.size();
    vector<unordered_map<char, int>> freq(n + 1);
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        freq[i + 1] = freq[i];
        freq[i + 1][s[i]]++;
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            unordered_map<int, int> charCount;
            for (char c = 'a'; c <= 'z'; ++c) {
                int cnt = freq[i + len][c] - freq[i][c];
                if (cnt > 0) charCount[cnt]++;
            }
            if (charCount.size() == 1) ++count;
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;
    cout << countSpecialSubstrings(s) << endl;
    return 0;
}