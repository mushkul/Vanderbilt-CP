#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    vector<int> ones_pos;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones_pos.push_back(i);
        }
    }
    
    vector<int> result(n-1, 0);
    
    for (int i = 0; i < ones_pos.size(); i++) {
        for (int j = i+1; j < ones_pos.size(); j++) {
            int dist = ones_pos[j] - ones_pos[i];
            if (dist < n) {
                result[dist-1]++;
            }
        }
    }
    
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}