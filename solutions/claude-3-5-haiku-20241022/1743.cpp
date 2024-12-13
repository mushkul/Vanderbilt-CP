#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'A']++;
    }
    
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            pq.push({freq[i], 'A' + i});
        }
    }
    
    string result;
    pair<int, char> prev = {0, 'A'};
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        result += curr.second;
        curr.first--;
        
        if (prev.first > 0) {
            pq.push(prev);
        }
        
        prev = curr;
    }
    
    if (result.length() != s.length()) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}