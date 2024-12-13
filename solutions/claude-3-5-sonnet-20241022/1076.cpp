#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    multiset<int> left, right;
    
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            if (left.find(a[i-k]) != left.end()) {
                left.erase(left.find(a[i-k]));
            }
            else {
                right.erase(right.find(a[i-k]));
            }
        }
        
        if (right.empty() || a[i] <= *right.begin()) {
            left.insert(a[i]);
        }
        else {
            right.insert(a[i]);
        }

        while (left.size() > right.size()) {
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }
        while (right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }

        if (i >= k-1) {
            cout << *left.rbegin() << " ";
        }
    }
    
    return 0;
}