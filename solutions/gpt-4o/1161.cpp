#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> x >> n;
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long length;
        cin >> length;
        pq.push(length);
    }
    
    long long totalCost = 0;
    while (pq.size() > 1) {
        long long first = pq.top(); pq.pop();
        long long second = pq.top(); pq.pop();
        long long newStick = first + second;
        totalCost += newStick;
        pq.push(newStick);
    }
    
    cout << totalCost << endl;
    return 0;
}