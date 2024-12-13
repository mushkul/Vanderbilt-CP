#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    
    vector<int> freq(26, 0);
    for(char c : s) {
        freq[c - 'A']++;
    }
    
    int oddCount = 0;
    char oddChar;
    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 == 1) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }
    
    if(oddCount > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    
    string result;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < freq[i]/2; j++) {
            result += (char)('A' + i);
        }
    }
    
    string temp = result;
    if(oddCount == 1) {
        result += oddChar;
    }
    reverse(temp.begin(), temp.end());
    result += temp;
    
    cout << result;
    return 0;
}