#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }
    
    vector<int> removed;
    for (int i = 0; i < n; i++) {
        int pos = positions[i] - 1;
        removed.push_back(arr[pos]);
        arr.erase(arr.begin() + pos);
    }
    
    for (int val : removed) {
        cout << val << " ";
    }
    
    return 0;
}