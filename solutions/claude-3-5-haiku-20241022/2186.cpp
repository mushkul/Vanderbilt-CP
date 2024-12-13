#include <bits/stdc++.h>
using namespace std;

int countSpecialSubstrings(string s) {
    int n = s.length();
    int specialCount = 0;

    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        unordered_set<int> uniqueFreqs;

        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;
            uniqueFreqs.clear();

            for (int k = 0; k < 26; k++) {
                if (freq[k] > 0) {
                    uniqueFreqs.insert(freq[k]);
                }
            }

            if (uniqueFreqs.size() == 1) {
                specialCount++;
            }
        }
    }

    return specialCount;
}

int main() {
    string s;
    cin >> s;
    cout << countSpecialSubstrings(s) << endl;
    return 0;
}