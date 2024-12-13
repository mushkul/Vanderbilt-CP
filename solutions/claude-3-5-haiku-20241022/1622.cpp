#include <bits/stdc++.h>
using namespace std;

set<string> result;

void generatePermutations(string s, int l, int r) {
    if (l == r) {
        result.insert(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            generatePermutations(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main() {
    string s;
    cin >> s;
    
    generatePermutations(s, 0, s.length() - 1);
    
    cout << result.size() << endl;
    for (string perm : result) {
        cout << perm << endl;
    }
    
    return 0;
}