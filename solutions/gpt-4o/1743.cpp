#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'A']++;
    }

    priority_queue<pair<int, char>> maxHeap;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            maxHeap.push({-count[i], 'A' + i});
        }
    }
    
    string result;
    pair<int, char> prev = {1, '#'};
    
    while (!maxHeap.empty()) {
        auto [cnt1, char1] = maxHeap.top();
        maxHeap.pop();
        
        result += char1;
        
        if (prev.first < 0) {
            maxHeap.push(prev);
        }        

        prev = {cnt1 + 1, char1};
    }
    
    if (result.size() != s.length()) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}