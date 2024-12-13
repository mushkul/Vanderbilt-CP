#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    multiset<int> lower, upper;
    
    for (int i = 0; i < k; i++) {
        lower.insert(arr[i]);
    }
    
    while (lower.size() > (k + 1) / 2) {
        upper.insert(*lower.rbegin());
        lower.erase(prev(lower.end()));
    }
    
    vector<int> medians;
    medians.push_back(*lower.rbegin());
    
    for (int i = k; i < n; i++) {
        if (lower.find(arr[i-k]) != lower.end()) {
            lower.erase(lower.find(arr[i-k]));
        } else {
            upper.erase(upper.find(arr[i-k]));
        }
        
        if (!lower.empty() && arr[i] <= *lower.rbegin()) {
            lower.insert(arr[i]);
        } else {
            upper.insert(arr[i]);
        }
        
        if (lower.size() > (k + 1) / 2) {
            upper.insert(*lower.rbegin());
            lower.erase(prev(lower.end()));
        }
        
        if (lower.size() < (k + 1) / 2) {
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
        
        medians.push_back(*lower.rbegin());
    }
    
    for (int median : medians) {
        cout << median << " ";
    }
    cout << endl;
    
    return 0;
}