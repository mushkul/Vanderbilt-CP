#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    unordered_set<string> subsequences;
    
    // Generate all single character subsequences
    for (char ch : s) {
        string t(1, ch);
        subsequences.insert(t);
    }
    
    // Check for a single character missing subsequence
    string alphabet = "ACGT";
    for (char ch : alphabet) {
        string t(1, ch);
        if (subsequences.find(t) == subsequences.end()) {
            cout << t << endl;
            return 0;
        }
    }
    
    // Generate all two-character subsequences
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string t;
            t.append(1, s[i]);
            t.append(1, s[j]);
            subsequences.insert(t);
        }
    }
    
    // Check for a two-character missing subsequence
    for (char c1 : alphabet) {
        for (char c2 : alphabet) {
            string t;
            t.push_back(c1);
            t.push_back(c2);
            if (subsequences.find(t) == subsequences.end()) {
                cout << t << endl;
                return 0;
            }
        }
    }

    // Generate all three-character subsequences
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                string t;
                t.append(1, s[i]);
                t.append(1, s[j]);
                t.append(1, s[k]);
                subsequences.insert(t);
            }
        }
    }

    // Check for a three-character missing subsequence
    for (char c1 : alphabet) {
        for (char c2 : alphabet) {
            for (char c3 : alphabet) {
                string t;
                t.push_back(c1);
                t.push_back(c2);
                t.push_back(c3);
                if (subsequences.find(t) == subsequences.end()) {
                    cout << t << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}