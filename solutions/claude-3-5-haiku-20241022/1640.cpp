#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    unordered_map<int, int> complement;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        int target = x - arr[i];
        if (complement.count(target)) {
            cout << complement[target] + 1 << " " << i + 1 << endl;
            return 0;
        }
        
        complement[arr[i]] = i;
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}