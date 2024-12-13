#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    vector<int> divisions(n);
    for (int i = 0; i < n; i++) {
        cin >> divisions[i];
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int div : divisions) {
        pq.push(div);
    }
    
    long long totalCost = 0;
    
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        int newStick = first + second;
        totalCost += newStick;
        
        pq.push(newStick);
    }
    
    cout << totalCost << endl;
    
    return 0;
}