#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    queue<long long> q;
    unordered_map<long long, int> steps;
    
    q.push(n);
    steps[n] = 0;
    
    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        
        if (current == 0) {
            cout << steps[current] << endl;
            return 0;
        }
        
        string s = to_string(current);
        for (char c : s) {
            int digit = c - '0';
            if (digit > 0 && steps.find(current - digit) == steps.end()) {
                steps[current - digit] = steps[current] + 1;
                q.push(current - digit);
            }
        }
    }
    return 0;
}