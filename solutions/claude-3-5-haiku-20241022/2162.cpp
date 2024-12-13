#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> order;
    vector<bool> removed(n + 1, false);
    
    int current = 1, count = 0;
    while (count < n) {
        if (!removed[current]) {
            removed[current] = true;
            order.push_back(current);
            count++;
        }
        
        int steps = 0;
        while (steps < 2) {
            current++;
            if (current > n) current = 1;
            if (!removed[current]) steps++;
        }
    }
    
    for (int child : order) {
        cout << child << " ";
    }
    
    return 0;
}